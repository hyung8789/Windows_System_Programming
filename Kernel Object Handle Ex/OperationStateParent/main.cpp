#include <stdio.h>
#include <tchar.h>
#include <windows.h>

/// <summary>
/// 작업 상태 반환 부모 프로그램
/// </summary>
/// <param name="argc">실행 시 인자 개수</param>
/// <param name="argv">실행 시 인자</param>
/// <returns>작업 상태</returns>
int _tmain(int argc, TCHAR* argv[])
{
	STARTUPINFO sInfo = { 0, };
	PROCESS_INFORMATION pInfo;

	DWORD exitCode = 0; //종료 코드

	// https://docs.microsoft.com/en-us/windows/win32/api/processthreadsapi/ns-processthreadsapi-startupinfow
	sInfo.cb = sizeof(sInfo);
	sInfo.dwFlags = STARTF_USEPOSITION | STARTF_USESIZE; //좌표와 길이 사용
	sInfo.dwX = 100; //프로세스 윈도우의 x 좌표
	sInfo.dwY = 200; //프로세스 윈도우의 y 좌표
	sInfo.dwXSize = 300; //가로 길이
	sInfo.dwYSize = 200; //세로 길이
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
				//OperationStateChild의 종료 대기 (Busy Waiting)
				//사용자로부터 입력 받아 연산을 마치기 전 종료 코드를 얻으므로 STILL_ACTIVE 반환
			}
	}

	// https://docs.microsoft.com/en-us/windows/win32/api/synchapi/nf-synchapi-waitforsingleobject
	WaitForSingleObject(pInfo.hProcess, INFINITE); //OperationStateChild의 종료 대기

	// https://docs.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-getexitcodeprocess
	GetExitCodeProcess(pInfo.hProcess, &exitCode);
	_tprintf(_T("OperationStateChild exitCode : %d\n"), exitCode);
	_fgettchar();
	
	/***
		OperationStateChild가 종료 되었을 시 부모 프로세스인 현재 프로세스가
		Handle을 통해 해당 자식 프로세스에 대한 커널 오브젝트를 아직 참조중이므로, Usage Count = 1
	***/
	if (exitCode != STILL_ACTIVE) //OperationStateChild가 종료 시 핸들 반환
	{
		CloseHandle(pInfo.hProcess); //핸들 반환에 따라 해당 자식 프로세스에 대한 Kernel Object의 Usage Count 1 감소
	}

	return EXIT_SUCCESS;
}