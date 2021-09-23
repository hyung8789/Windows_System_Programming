#include <stdio.h>
#include <tchar.h>
#include <windows.h>

#define DIR_LENGTH MAX_PATH + 1

/// <summary>
/// ���� ���ڸ� ���� AdderProc ���� ���α׷�
/// </summary>
/// <param name="argc">���� �� ���� ����</param>
/// <param name="argv">���� �� ����</param>
/// <returns>�۾� ����</returns>
int _tmain(int argc, TCHAR* argv[])
{
	STARTUPINFO sInfo = { 0 };
	PROCESS_INFORMATION pInfo;

	// https://docs.microsoft.com/en-us/windows/win32/api/processthreadsapi/ns-processthreadsapi-startupinfow
	sInfo.cb = sizeof(sInfo);
	sInfo.dwFlags = STARTF_USEPOSITION | STARTF_USESIZE; //��ǥ�� ���� ���
	sInfo.dwX = 100; //���μ��� �������� x ��ǥ
	sInfo.dwY = 200; //���μ��� �������� y ��ǥ
	sInfo.dwXSize = 300; //���� ����
	sInfo.dwYSize = 200; //���� ����
	sInfo.lpTitle = (LPWSTR)_T("This is Title");

	TCHAR command[] = _T("AdderProc.exe 10 20");
	TCHAR currentDirPath[DIR_LENGTH]; //���� ���͸� ���
	BOOL processCreationState;

	GetCurrentDirectory(DIR_LENGTH, currentDirPath); //���� ���͸� Ȯ��
	_fputts(currentDirPath, stdout);
	_fputts(_T("\n"), stdout);

	SetCurrentDirectory(_T("C:\\test")); //���� ���丮 ����

	GetCurrentDirectory(DIR_LENGTH, currentDirPath); //���� ���͸� Ȯ��
	_fputts(currentDirPath, stdout);
	_fputts(_T("\n"), stdout);

	GetSystemDirectory(currentDirPath, DIR_LENGTH); //�ý��� ���丮 (sys32)
	_tprintf(_T("sysdir : %s\n"), currentDirPath);

	GetWindowsDirectory(currentDirPath, DIR_LENGTH); //������ ���丮 (windows)
	_tprintf(_T("windir : %s\n"), currentDirPath);

	/***
	* ǥ�� �˻���ο� ���� ���� ���� ���� ���� ���μ����� ���������� �����ϴ� ���͸��� �������� ���������� ã��,
	* �������� ���� ��� ���� ���� ���� ���μ����� ���� ���͸�(SetCurrentDirectory�� ���� ���� �� ���͸�)���� ã��
	* �� ����, sysdir -> windir -> ȯ�溯�� PATH�� ���� �� ���͸� ��
	***/

	// https://docs.microsoft.com/en-us/windows/win32/procthread/process-creation-flags
	processCreationState = CreateProcess(
		NULL, //�������� �̸�
		command, //���� �� ��ɾ�
		NULL,
		NULL,
		TRUE, //Handle ��� ����
		CREATE_NEW_CONSOLE, //�� �ܼ� â���� ����
		NULL,
		NULL,
		&sInfo,
		&pInfo
	);
	
	if (processCreationState != 0)
		_fputts(_T("Success\n"), stdout);
	else
		_fputts(_T("Fail\n"), stdout);

	_gettchar();

	return EXIT_SUCCESS;
}