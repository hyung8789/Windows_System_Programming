#include "Core.h"

/// <summary>
/// ��ɾ� ��ū ���� �׽�Ʈ
/// </summary>
void UnitTest_CmdToken()
{
	
	//_tprintf_s(_T("%d\n"), cmdToken.GenerateToken(NULL));
}

void UnitTest_�ҹ��ں�ȯ()
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
	UnitTest_�ҹ��ں�ȯ();
	//UnitTest_CmdToken();

}