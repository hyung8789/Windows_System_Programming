#include "Core.h"

/// <summary>
/// ��ɾ� ��ū ���� �׽�Ʈ
/// </summary>
void UnitTest_CmdToken()
{
	CMD_TOKEN cmdToken;
	_tprintf_s(_T("%d\n"), cmdToken.GenerateToken(NULL));
}

void UnitTest_�ҹ��ں�ȯ()
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
	UnitTest_�ҹ��ں�ȯ();
	//UnitTest_CmdToken();

}