#include "Core.h"

#ifdef DEBUG_MODE
/// <summary>
/// 통합 테스트
/// </summary>
void IntegrationTest()
{

}

/// <summary>
/// 명령어 토큰 단위 테스트
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