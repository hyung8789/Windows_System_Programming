#include "Core.h"

/// <summary>
/// 명령어 토큰 단위 테스트
/// </summary>
void UnitTest_CmdToken()
{
	
	//_tprintf_s(_T("%d\n"), cmdToken.GenerateToken(NULL));
}

void UnitTest_소문자변환()
{
	const TCHAR* expected = _T("test");
	TCHAR buffer[] = _T("TeST");
	const TCHAR* actual = utils::StrLower(buffer);
	_tprintf_s(_T("expected : %s, actual : %s\n"), expected, actual);

	const TCHAR* actual2 = utils::StrLower(NULL);
	_tprintf_s(_T("actual2 null? : %c\n"), (actual2 == NULL) ? 'T' : 'F');
}

void RunDebugMode()
{
	_fputts(_T("Running Debug Mode\n"), stdout);
	UnitTest_소문자변환();
	//UnitTest_CmdToken();

}