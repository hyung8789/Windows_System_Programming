#include "Core.h"

/// <summary>
/// 
/// </summary>
/// <param name="argc"></param>
/// <param name="argv"></param>
/// <returns></returns>
DWORD CmdArgvProcessing(int argc, TCHAR** argv)
{
	return 0;
}

/// <summary>
/// 명령어 토큰화 분리 작업 수행 및 분리 된 토큰 개수 반환
/// </summary>
/// <returns>분리 된 토큰 개수</returns>
DWORD CmdReadTokenize()
{
	static TCHAR seps[] = _T(" ,\t\n"); //구분자
	static TCHAR ERROR_MSG[] = _T("'%s'은(는) 실행할 수 있는 프로그램이 아닙니다.\n");

	TCHAR inputCmdString[MAX_STR_LEN] = { NULL, }; //입력받은 명령어
	TCHAR* token = NULL;
	TCHAR* context = NULL; //분리 된 문자열에 대한 두 번째 문자열의 시작 주소

	int cmdTokenIndex = 0;

	_fputts(_T("Enter Command >>"), stdout);
	_getts_s(inputCmdString, MAX_STR_LEN - 1);
	token = _tcstok_s(inputCmdString, seps, &context); //구분자로 분리

	while (token != NULL)
	{
		_tcscpy_s(cmdTokenList[cmdTokenIndex++], StrLower(token));
		token = _tcstok_s(NULL, seps, &context);
	}

	return 0;
}

/// <summary>
/// 대소문자 구분 없이 명령어를 입력받아 해당 명령어에 지정된 기능을 수행
/// exit 입력 시 COMPLETE 반환 후 프로그램 종료
/// </summary>
/// <returns>if exit entered return COMPLETE, else return SUCCESS</returns>
DWORD CmdProcessing()
{
	static TCHAR seps[] = _T(" ,\t\n"); //구분자
	static TCHAR ERROR_MSG[] = _T("'%s'은(는) 실행할 수 있는 프로그램이 아닙니다.\n");

	TCHAR inputCmdString[MAX_STR_LEN] = { NULL, }; //입력받은 명령어
	TCHAR* token = NULL;
	TCHAR* context = NULL; //분리 된 문자열에 대한 두 번째 문자열의 시작 주소

	int cmdTokenIndex = 0;

	_fputts(_T("Enter Command >>"), stdout);
	_getts_s(inputCmdString, MAX_STR_LEN - 1);
	token = _tcstok_s(inputCmdString, seps, &context); //구분자로 분리

	while (token != NULL)
	{
		_tcscpy_s(cmdTokenList[cmdTokenIndex++], StrLower(token));
		token = _tcstok_s(NULL, seps, &context);
	}

	if (_tcscmp(cmdTokenList[0], _T("exit")) == 0) //종료
	{
		return COMPLETE;
	}
	else if (1==0)
	{
		///dummy
	}
	else //프로세스 생성
	{
		// https://docs.microsoft.com/en-us/windows/win32/api/processthreadsapi/ns-processthreadsapi-startupinfow
		// https://docs.microsoft.com/en-us/windows/win32/procthread/process-creation-flags
		STARTUPINFO sInfo = { 0, };
		PROCESS_INFORMATION pInfo;
		sInfo.cb = sizeof(sInfo);

		BOOL processCreationState =
			CreateProcess(
				NULL, cmdTokenList[0], NULL, NULL, 
				TRUE, 0, NULL, NULL,
				&sInfo, &pInfo
			); //해당 명령어 수행

		if(processCreationState == FALSE) //프로세스 생성 실패 시
			_tprintf(ERROR_MSG, cmdTokenList[0]);
	}

	return SUCCESS;
}

/// <summary>
/// 문자열 내의 모든 대문자를 소문자로 변경
/// </summary>
/// <param name="srcStr">원본 문자열</param>
/// <returns>변경 된 문자열</returns>
TCHAR* StrLower(TCHAR* srcStr)
{
	if (srcStr == NULL)
		return NULL;

	TCHAR* result = srcStr;

	while (*srcStr)
	{
		if (_istupper(*srcStr))
			*srcStr = _totlower(*srcStr);

		srcStr++;
	}

	return result;
}

/// <summary>
/// 토큰 목록 초기화
/// </summary>
void ClearTokenList()
{
	for (int i = 0; i < MAX_CMD_TOKEN_COUNT; i++)
		memset(cmdTokenList[i], NULL, sizeof(TCHAR) * MAX_STR_LEN);
}
