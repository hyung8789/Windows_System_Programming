#include "Core.h"

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

	while(1)
	{
		switch (CmdProcessing())
		{
		case COMPLETE:
			_fputts(_T("��ɾ� ó���� �����մϴ�.\n"), stdout);
			goto END_SUCCESS;

		case SUCCESS:
			break;
		}
	}

END_SUCCESS:
	return EXIT_SUCCESS;
}