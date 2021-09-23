#include "Core.h"

/// <summary>
/// 계산기 프로그램
/// </summary>
/// <param name="argc">실행 시 인자 개수</param>
/// <param name="argv">실행 시 인자</param>
/// <returns>작업 상태</returns>
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