#include "Core.h"

TCHAR cmdTokenList[MAX_CMD_TOKEN_COUNT][MAX_STR_LEN]; //�и� �� ��ū ���

/// <summary>
/// ��� ������Ʈ ���α׷�
/// </summary>
/// <param name="argc">���� �� ���� ����</param>
/// <param name="argv">���� �� ����</param>
/// <returns>�۾� ����</returns>
int _tmain(int argc, TCHAR* argv[])
{
	// https://docs.microsoft.com/ko-kr/cpp/c-runtime-library/reference/setlocale-wsetlocale?view=msvc-160
	_tsetlocale(LC_ALL, _T("Korean"));

	ClearTokenList();

	if (argc > 2)
	{
		/***
			argv[0] ���� �׻� ���� ��ΰ� ����
			ex) ��� ������Ʈ.exe start echo test
			argv[1] : start
			argv[2] : echo
			argv[3] : test
		***/
		for (int i = 1; i < argc; i++)
		{

		}
	}

	while(1)
	{
		switch (CmdProcessing())
		{
		case COMPLETE:
			goto END_SUCCESS;

		case SUCCESS:
			break;
		}
	}

END_SUCCESS:
	_fputts(_T("��ɾ� ó���� �����մϴ�.\n"), stdout);
	return EXIT_SUCCESS;
}