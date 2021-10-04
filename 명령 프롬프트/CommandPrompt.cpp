#include "Core.h"

/// <summary>
/// 
/// </summary>
/// <param name="argc"></param>
/// <param name="argv"></param>
/// <returns></returns>
DWORD CmdArgvProc(int argc, TCHAR** argv)
{


	return 0;
}

/// <summary>
/// 명령어 입력받아 토큰 분리 작업 수행 및 마지막으로 분리 된 토큰 인덱스 반환
/// </summary>
/// <returns>마지막으로 분리 된 토큰 인덱스</returns>
void CmdReadTokenizeProc()
{
	static const TCHAR seps[] = _T(" ,\t\n"); //구분자
	
	TCHAR inputCmdString[MAX_STR_LEN] = { NULL, }; //입력받은 명령어
	TCHAR* token = NULL;
	TCHAR* context = NULL; //분리 된 문자열에 대한 두 번째 문자열의 시작 주소

	_fputts(_T("Enter Command >>"), stdout);
	_getts_s(inputCmdString, MAX_STR_LEN - 1);
	token = _tcstok_s(inputCmdString, seps, &context); //구분자로 분리

	while (token != NULL)
	{
		_tcscpy_s(cmdTokenList[cmdTokenIndex++], StrLower(token));
		token = _tcstok_s(NULL, seps, &context);
	}
}

/// <summary>
/// 해당 명령어에 지정된 기능을 수행
/// exit 명령에 대해 COMPLETE 반환 후 프로그램 종료
/// </summary>
/// <returns>exit 명령에 대해 COMPLETE 반환, 그 외 SUCCESS 반환</returns>
DWORD CmdProc()
{
	static const TCHAR ERROR_MSG[] = _T("'%s'은(는) 실행할 수 있는 프로그램이 아닙니다.\n");
	TCHAR cmdStringWithOptions[MAX_STR_LEN] = { NULL, };
	TCHAR subArgs[MAX_STR_LEN] = { NULL, };

	STARTUPINFO sInfo = { 0, };
	PROCESS_INFORMATION pInfo;
	BOOL processCreationState = false;

	sInfo.cb = sizeof(sInfo);
	

	if (_tcscmp(cmdTokenList[0], _T("exit")) == 0) //종료
	{
		return COMPLETE;
	}
	else if (_tcscmp(cmdTokenList[0], _T("start")) == 0)
	{
		if (cmdTokenIndex > 1)
		{
			for (int i = 1; i < cmdTokenIndex; i++)
			{
				_stprintf_s(subArgs, _T("%s %s"), subArgs, cmdTokenList[i]);

			}

			_stprintf_s(cmdStringWithOptions, _T("%s %s"), selfProcessName, subArgs);
		}
		else //start만 입력
		{
			_stprintf_s(cmdStringWithOptions, _T("%s"), selfProcessName);
		}

		processCreationState =
			CreateProcess(
				NULL, cmdStringWithOptions, NULL, NULL,
				TRUE, 0, NULL, NULL,
				&sInfo, &pInfo
			); //해당 명령어 수행

		CloseHandle(pInfo.hProcess);
		CloseHandle(pInfo.hThread);
	}
	else if (_tcscmp(cmdTokenList[0], _T("echo")) == 0)
	{

	}
	else //프로세스 생성
	{
		// https://docs.microsoft.com/en-us/windows/win32/api/processthreadsapi/ns-processthreadsapi-startupinfow
		// https://docs.microsoft.com/en-us/windows/win32/procthread/process-creation-flags
	

		processCreationState =
			CreateProcess(
				NULL, cmdTokenList[0], NULL, NULL, 
				TRUE, 0, NULL, NULL,
				&sInfo, &pInfo
			); //해당 명령어 수행

		CloseHandle(pInfo.hProcess);
		CloseHandle(pInfo.hThread);

		if(processCreationState == FALSE) //프로세스 생성 실패 시
			_tprintf(ERROR_MSG, cmdTokenList[0]);
	}

	return SUCCESS;
}

/// <summary>
/// 문자열 내의 모든 대문자를 소문자로 변경
/// </summary>
/// <param name="srcStr">원본 문자열 (editable)</param>
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
/// 토큰 목록 및 인덱스 초기화
/// </summary>
void ClearToken()
{
	for (int i = 0; i < MAX_CMD_TOKEN_COUNT; i++)
		memset(cmdTokenList[i], NULL, sizeof(TCHAR) * MAX_STR_LEN);

	cmdTokenIndex = 0;
}