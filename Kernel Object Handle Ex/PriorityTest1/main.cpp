#include <stdio.h>
#include <tchar.h>
#include <windows.h>

/// <summary>
/// 프로세스 우선순위 변경 예제 1
/// </summary>
/// <param name="argc">실행 시 인자 개수</param>
/// <param name="argv">실행 시 인자</param>
/// <returns>작업 상태</returns>
int _tmain(int argc, TCHAR* argv[])
{
	STARTUPINFO sInfo = { 0, };
	PROCESS_INFORMATION pInfo;

	sInfo.cb = sizeof(sInfo);
	TCHAR command[] = _T("PriorityTest2.exe");

	CreateProcess(
		NULL, command,
		NULL,
		NULL,
		TRUE,
		0,
		NULL,
		NULL,
		&sInfo,
		&pInfo
	);

	while (1)
	{
		//if (1 == 0)
		{
			for (DWORD i = 0; i < 10000; i++)
				for (DWORD j = 0; j < 10000; j++)
				{
					/***
						Sleep으로 대기 시 현재 프로세스는 Blocked 상태로 변한다.
						Running 상태로 대기(Busy Waiting)
					***/
				}
		}

		//Sleep(5000); //5초 대기

		_fputts(_T("PriorityTest1 Running\n"), stdout);
	}

	return EXIT_SUCCESS;
}
