#include "Core.h"

/// <summary>
/// 명령어 토큰 단위 테스트
/// </summary>
void UnitTest_CmdToken()
{
	CMD_TOKEN cmdToken;
	_tprintf_s(_T("%d\n"), cmdToken.GenerateToken(NULL));
}

void UnitTest_소문자변환()
{
	const TCHAR* expected = _T("test");
	TCHAR buffer[] = _T("TeST");
	const TCHAR* actual = utils::StrLower(buffer);
	_tprintf_s(_T("%s, %s\n"), expected, actual);

	const TCHAR* actual2 = utils::StrLower(NULL);
	_tprintf_s(_T("%c\n"), (actual2 == NULL) ? 'T' : 'F');
}

void RunDebugMode()
{
	_fputts(_T("Running Debug Mode\n"), stdout);
	UnitTest_소문자변환();
	//UnitTest_CmdToken();

}