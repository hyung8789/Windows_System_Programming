#include <stdio.h>
#include <tchar.h>
#include <windows.h>

/// <summary>
/// ���μ��� �켱���� ���� ���� 2
/// </summary>
/// <param name="argc">���� �� ���� ����</param>
/// <param name="argv">���� �� ����</param>
/// <returns>�۾� ����</returns>
int _tmain(int argc, TCHAR* argv[])
{
	SetPriorityClass(GetCurrentProcess(), HIGH_PRIORITY_CLASS); //�ڱ��ڽ�('PriorityTest2')�� �켱���� ����

	while (1)
	{
		//if (1 == 0)
		{
			for (DWORD i = 0; i < 10000; i++)
				for (DWORD j = 0; j < 10000; j++)
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
