#include <stdio.h>
#include <tchar.h>
#include <windows.h>


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