#include <stdio.h>
#include <tchar.h>
#include <windows.h>


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
				for (DWORD i = 0; i < 10000; i++)
				{
					/***
						Sleep���� ��� �� ���� ���μ����� Blocked ���·� ���Ѵ�.
						Running ���·� ���(Busy Waiting)
					***/
				}
		}

		//Sleep(5000); //5�� ���

		_fputts(_T("PriorityTest1 Running\n"), stdout);
	}

	return EXIT_SUCCESS;
}
