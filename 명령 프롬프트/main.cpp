#include "Core.h"

TCHAR cmdTokenList[MAX_CMD_TOKEN_COUNT][MAX_STR_LEN]; //분리 된 토큰 목록

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

	ClearTokenList();

	if (argc > 2)
	{
		/***
			argv[0] 에는 항상 실행 경로가 존재
			ex) 명령 프롬프트.exe start echo test
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
	_fputts(_T("명령어 처리를 종료합니다.\n"), stdout);
	return EXIT_SUCCESS;
}