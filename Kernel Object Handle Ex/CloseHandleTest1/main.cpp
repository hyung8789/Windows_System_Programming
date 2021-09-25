#include <stdio.h>
#include <tchar.h>
#include <windows.h>


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

	return EXIT_SUCCESS;
}