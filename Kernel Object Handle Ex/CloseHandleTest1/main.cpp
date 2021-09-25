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
		1) 'CloseHandleTest1' 는 'CloseHandleTest2' 실행
		2) 'CloseHandleTest1' 는 'CloseHandleTest2' 핸들 반환
	***/

	CreateProcess(
		NULL, command, NULL, NULL, TRUE,
		0, NULL, NULL, &sInfo, &pInfo
	);

	CloseHandle(pInfo.hProcess); //핸들 반환

	return EXIT_SUCCESS;
}