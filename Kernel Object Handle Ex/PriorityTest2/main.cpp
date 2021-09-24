#include <stdio.h>
#include <tchar.h>
#include <windows.h>


int _tmain(int argc, TCHAR* argv[])
{
	SetPriorityClass(GetCurrentProcess(), HIGH_PRIORITY_CLASS); //PriorityTest2의 우선순위 높임

	while (1)
	{
		//if (1 == 0)
		{
			for (DWORD i = 0; i < 10000; i++)
				for (DWORD i = 0; i < 10000; i++)
				{
					/***
						Sleep으로 대기 시 현재 프로세스는 Blocked 상태로 변한다.
						Running 상태로 대기(Busy Waiting)
					***/
				}
		}

		//Sleep(5000); //5초 대기

		_fputts(_T("PriorityTest2 Running\n"), stdout);
	}

	return EXIT_SUCCESS;
}
