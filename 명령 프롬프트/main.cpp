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
	
	_tprintf_s(_T("%s\n"), utils::GetSelfProcessNameWithExt());

#ifdef DEBUG_MODE
	RunDebugMode();
#endif

	return EXIT_SUCCESS;
}