#include "Core.h"

/// <summary>
/// 명령 프롬프트 프로그램
/// </summary>
/// <param name="argc">실행 시 인자 개수</param>
/// <param name="argv">실행 시 인자</param>
/// <returns>작업 상태</returns>
int _tmain(int argc, TCHAR* argv[])
{
	// https://docs.microsoft.com/ko-kr/cpp/c-runtime-library/reference/setlocale-wsetlocale?view=msvc-160
	_tsetlocale(LC_ALL, _T("Korean"));

	while(1)
	{
		switch (CmdProcessing())
		{
		case COMPLETE:
			_fputts(_T("명령어 처리를 종료합니다.\n"), stdout);
			goto END_SUCCESS;

		case SUCCESS:
			break;
		}
	}

END_SUCCESS:
	return EXIT_SUCCESS;
}