#include "Core.h"

/// <summary>
/// ���� ���α׷�
/// </summary>
/// <param name="argc">���� �� ���� ����</param>
/// <param name="argv">���� �� ����</param>
/// <returns>�۾� ����</returns>
int _tmain(int argc, TCHAR* argv[])
{
	while (1)
	{
		DispMenu();

		switch (InputMenu())
		{
		case OP::EXIT:
			goto END_SUCCESS;

		case OP::NOP:
		default:
			break;
		}
	}

END_SUCCESS:
	return EXIT_SUCCESS;
}