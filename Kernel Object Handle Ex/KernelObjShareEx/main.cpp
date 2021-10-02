#include <stdio.h>
#include <tchar.h>
#include <windows.h>

/// <summary>
/// Kernel Object 공유 예제
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

	/***
		1)'PriorityTest2' 는 자신을 높은 프로세스 우선순위로 변경 (최초 한 번)
		2) 현재 프로세스인 'KernelObjShareEx' 는 Busy Waiting 후 'PriorityTest2' 의 우선순위를 기존 우선순위로 낮춤
	***/

	CreateProcess(
		NULL, command, NULL, NULL, TRUE,
		0, NULL, NULL, &sInfo, &pInfo
	);

	DWORD timing = 0;
	while (1)
	{
		for (DWORD i = 0; i < 10000; i++)
			for (DWORD j = 0; j < 10000; j++)
			{
				//Busy Waiting
			}

		_fputts(_T("KernelObjShare Running\n"), stdout);

		if (timing++ == 2)
		{
			//프로세스 생성 시 이용 한 프로세스의 정보(PROCESS_INFORMATION) 구조체에 생성 된 프로세스의 핸들을 갖고 있다.
			SetPriorityClass(pInfo.hProcess, NORMAL_PRIORITY_CLASS); //핸들을 통해 접근 해 'PriorityTest2' 의 우선순위를 기존 우선순위로 낮춤
		}
	}

	return EXIT_SUCCESS;
}