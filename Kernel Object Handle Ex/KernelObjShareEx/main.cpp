#include <stdio.h>
#include <tchar.h>
#include <windows.h>

/// <summary>
/// Kernel Object ���� ����
/// </summary>
/// <param name="argc">���� �� ���� ����</param>
/// <param name="argv">���� �� ����</param>
/// <returns>�۾� ����</returns>
int _tmain(int argc, TCHAR* argv[])
{
	STARTUPINFO sInfo = { 0, };
	PROCESS_INFORMATION pInfo;

	sInfo.cb = sizeof(sInfo);
	TCHAR command[] = _T("PriorityTest2.exe");

	/***
		1)'PriorityTest2' �� �ڽ��� ���� ���μ��� �켱������ ���� (���� �� ��)
		2) ���� ���μ����� 'KernelObjShareEx' �� Busy Waiting �� 'PriorityTest2' �� �켱������ ���� �켱������ ����
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
			//���μ��� ���� �� �̿� �� ���μ����� ����(PROCESS_INFORMATION) ����ü�� ���� �� ���μ����� �ڵ��� ���� �ִ�.
			SetPriorityClass(pInfo.hProcess, NORMAL_PRIORITY_CLASS); //�ڵ��� ���� ���� �� 'PriorityTest2' �� �켱������ ���� �켱������ ����
		}
	}

	return EXIT_SUCCESS;
}