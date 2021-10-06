#include "Core.h"

/// <summary>
/// ��ɾ� ��ū ���� �׽�Ʈ
/// </summary>
void UnitTest_CmdToken()
{
	CmdToken token;
	//token.GenerateToken(NULL);
	_tprintf_s(_T("---UnitTest_CmdToken---\n"));
	const TCHAR* input = _T("test");
	_tprintf_s(_T("input : %s\n"), input);
	token.GenerateToken(input);
	_tprintf_s(_T("tokenType : %s\n"), 
		CmdTypeParser::GetStringFromCmdType(token.GetCmdTypeOnce()));
	_tprintf_s(_T("tokenSubArgs : %s\n"),
		token.GetCmdSubArgsOnce());

	const TCHAR* input2 = _T("echo");
	_tprintf_s(_T("input : %s\n"), input2);
	token.GenerateToken(input2);
	_tprintf_s(_T("tokenType : %s\n"),
		CmdTypeParser::GetStringFromCmdType(token.GetCmdTypeOnce()));
	_tprintf_s(_T("tokenSubArgs : %s\n"),
		token.GetCmdSubArgsOnce());

	_tprintf_s(_T("Exception Test\n"));
	token.GetCmdTypeOnce();
	token.GetCmdSubArgsOnce();
}

void UnitTest_�ҹ��ں�ȯ()
{
	_tprintf_s(_T("---UnitTest_�ҹ��ں�ȯ---\n"));
	const TCHAR* expected = _T("test");
	TCHAR buffer[] = _T("TeST");
	const TCHAR* actual = utils::StrLower(buffer);
	_tprintf_s(_T("expected : %s, actual : %s\n"), expected, actual);

	const TCHAR* actual2 = utils::StrLower(NULL);
	_tprintf_s(_T("actual2 null? : %c\n"), (actual2 == NULL) ? 'T' : 'F');
}

void UnitTest_GetSelfProcessNameWithExt()
{
	while(1)
		_tprintf_s(_T("%s\n"), utils::GetSelfProcessNameWithExt());
}

void RunDebugMode()
{
	_fputts(_T("Running Debug Mode\n"), stdout);
	UnitTest_�ҹ��ں�ȯ();
	//UnitTest_GetSelfProcessNameWithExt();
	UnitTest_CmdToken();

}