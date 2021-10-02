#include <stdio.h>
#include <tchar.h>
#include <windows.h>

/// <summary>
/// Kernel Object와 HANDLE의 종속 관계 예제 2
/// </summary>
/// <param name="argc">실행 시 인자 개수</param>
/// <param name="argv">실행 시 인자</param>
/// <returns>작업 상태</returns>
int _tmain(int argc, TCHAR* argv[])
{
	DWORD count = 0;

	while (count < 100)
	{
		for (DWORD i = 0; i < 10000; i++)
			for (DWORD j = 0; j < 10000; j++)
			{
				//Busy Waiting
			}

		_tprintf(_T("CloseHandleTest2 : %lu\n"), count);
		count++;
	}

	return EXIT_SUCCESS;
}