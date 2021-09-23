#include "Core.h"

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
	TCHAR cmdTokenList[MAX_CMD_TOKEN_COUNT][MAX_STR_LEN] = { NULL, }; //분리 된 토큰 목록
	int cmdTokenIndex = 0;

	_fputts(_T("Enter Command >>"), stdout);
	_getts_s(inputCmdString, MAX_STR_LEN - 1);
	token = _tcstok(inputCmdString, seps); //구분자로 분리

	while (token != NULL)
	{
		_tcscpy(cmdTokenList[cmdTokenIndex++], StrLower(token));
		token = _tcstok(NULL, seps);
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
				NULL,
				cmdTokenList[0], //해당 토큰 내용으로 명령어 입력
				NULL,
				NULL,
				TRUE,
				0,
				NULL,
				NULL,
				&sInfo,
				&pInfo
			);

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
