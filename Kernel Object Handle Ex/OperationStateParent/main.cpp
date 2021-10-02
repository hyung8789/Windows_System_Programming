#include <stdio.h>
#include <tchar.h>
#include <windows.h>

/// <summary>
/// �۾� ���� ��ȯ �θ� ���α׷�
/// </summary>
/// <param name="argc">���� �� ���� ����</param>
/// <param name="argv">���� �� ����</param>
/// <returns>�۾� ����</returns>
int _tmain(int argc, TCHAR* argv[])
{
	STARTUPINFO sInfo = { 0, };
	PROCESS_INFORMATION pInfo;

	DWORD exitCode = 0; //���� �ڵ�

	// https://docs.microsoft.com/en-us/windows/win32/api/processthreadsapi/ns-processthreadsapi-startupinfow
	sInfo.cb = sizeof(sInfo);
	sInfo.dwFlags = STARTF_USEPOSITION | STARTF_USESIZE; //��ǥ�� ���� ���
	sInfo.dwX = 100; //���μ��� �������� x ��ǥ
	sInfo.dwY = 200; //���μ��� �������� y ��ǥ
	sInfo.dwXSize = 300; //���� ����
	sInfo.dwYSize = 200; //���� ����
	sInfo.lpTitle = (LPWSTR)_T("OperationStateChild");

	TCHAR command[] = _T("OperationStateChild.exe");

	CreateProcess(
		NULL, command, NULL, NULL,
		TRUE, CREATE_NEW_CONSOLE, NULL, NULL,
		&sInfo, &pInfo
	);

	if (1==0)
	{
		for (DWORD i = 0; i < 100; i++)
			for (DWORD j = 0; j < 100; j++)
			{
				//OperationStateChild�� ���� ��� (Busy Waiting)
				//����ڷκ��� �Է� �޾� ������ ��ġ�� �� ���� �ڵ带 �����Ƿ� STILL_ACTIVE ��ȯ
			}
	}

	// https://docs.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-waitforsingleobject
	WaitForSingleObject(pInfo.hProcess, INFINITE); //OperationStateChild�� ���� ���

	// https://docs.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-getexitcodeprocess
	GetExitCodeProcess(pInfo.hProcess, &exitCode);
	_tprintf(_T("OperationStateChild exitCode : %d\n"), exitCode);
	_fgettchar();
	
	/***
		OperationStateChild�� ���� �Ǿ��� �� �θ� ���μ����� ���� ���μ�����
		Handle�� ���� �ش� �ڽ� ���μ����� ���� Ŀ�� ������Ʈ�� ���� �������̹Ƿ�, Usage Count = 1
	***/
	if (exitCode != STILL_ACTIVE) //OperationStateChild�� ���� �� �ڵ� ��ȯ
	{
		CloseHandle(pInfo.hProcess); //�ڵ� ��ȯ�� ���� �ش� �ڽ� ���μ����� ���� Kernel Object�� Usage Count 1 ����
	}

	return EXIT_SUCCESS;
}