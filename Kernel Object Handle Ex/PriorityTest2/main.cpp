#include <stdio.h>
#include <tchar.h>
#include <windows.h>


int _tmain(int argc, TCHAR* argv[])
{
	SetPriorityClass(GetCurrentProcess(), HIGH_PRIORITY_CLASS); //PriorityTest2�� �켱���� ����

	while (1)
	{
		//if (1 == 0)
		{
			for (DWORD i = 0; i < 10000; i++)
				for (DWORD i = 0; i < 10000; i++)
				{
					/***
						Sleep���� ��� �� ���� ���μ����� Blocked ���·� ���Ѵ�.
						Running ���·� ���(Busy Waiting)
					***/
				}
		}

		//Sleep(5000); //5�� ���

		_fputts(_T("PriorityTest2 Running\n"), stdout);
	}

	return EXIT_SUCCESS;
}
