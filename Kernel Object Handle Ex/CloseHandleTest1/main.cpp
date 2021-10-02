#include <stdio.h>
#include <tchar.h>
#include <windows.h>

/// <summary>
/// Kernel Object와 HANDLE의 종속 관계 예제 1
/// </summary>
/// <param name="argc">실행 시 인자 개수</param>
/// <param name="argv">실행 시 인자</param>
/// <returns>작업 상태</returns>
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
	_fputts(_T("'CloseHandleTest2' Handle closed by ClosedHandleTest1\n"), stdout);

	return EXIT_SUCCESS;
}