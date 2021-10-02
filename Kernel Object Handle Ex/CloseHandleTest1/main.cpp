#include <stdio.h>
#include <tchar.h>
#include <windows.h>

/// <summary>
/// Kernel Object�� HANDLE�� ���� ���� ���� 1
/// </summary>
/// <param name="argc">���� �� ���� ����</param>
/// <param name="argv">���� �� ����</param>
/// <returns>�۾� ����</returns>
int _tmain(int argc, TCHAR* argv[])
{
	STARTUPINFO sInfo = { 0, };
	PROCESS_INFORMATION pInfo;

	sInfo.cb = sizeof(sInfo);
	TCHAR command[] = _T("CloseHandleTest2.exe");

	/***
		1) 'CloseHandleTest1' �� 'CloseHandleTest2' ����
		2) 'CloseHandleTest1' �� 'CloseHandleTest2' �ڵ� ��ȯ
	***/

	CreateProcess(
		NULL, command, NULL, NULL, TRUE,
		0, NULL, NULL, &sInfo, &pInfo
	);

	CloseHandle(pInfo.hProcess); //�ڵ� ��ȯ
	_fputts(_T("'CloseHandleTest2' Handle closed by ClosedHandleTest1\n"), stdout);

	return EXIT_SUCCESS;
}