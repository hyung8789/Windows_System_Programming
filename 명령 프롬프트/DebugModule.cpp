#include "Core.h"

#ifdef DEBUG_MODE
/// <summary>
/// ���� �׽�Ʈ
/// </summary>
void IntegrationTest()
{

}

/// <summary>
/// ��ɾ� ��ū ���� �׽�Ʈ
/// </summary>
void UnitTest_CmdToken()
{
	CMD_TOKEN cmdToken;

}


void RunDebugMode()
{
	_fputts(_T("Running Debug Mode\n"), stdout);
	UnitTest_CmdToken();

}
#endif