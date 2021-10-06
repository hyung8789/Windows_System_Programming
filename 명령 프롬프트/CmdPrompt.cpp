#include "Core.h"

CmdPrompt::CmdPrompt()
{
	this->ClearTokenList();
}

CmdPrompt::~CmdPrompt()
{
}

void CmdPrompt::Run()
{
	//TODO : 사용자 입력 및 토큰 분리, 명령어 토큰 생성 후 이벤트 호출

	static const TCHAR seps[] = _T(" ,\t\n"); //구분자

	TCHAR inputCmdString[MAX_STR_LEN] = { NULL, }; //입력받은 명령어
	TCHAR* token = NULL;
	TCHAR* context = NULL; //분리 된 문자열에 대한 두 번째 문자열의 시작 주소

	CmdToken cmdToken;

	_fputts(_T("Enter Command >>"), stdout);
	_getts_s(inputCmdString, MAX_STR_LEN - 1);
	token = _tcstok_s(inputCmdString, seps, &context); //구분자로 분리

	/***
		< 사용자로부터의 명령어 입력 예시 >

		1) echo test
		: 화면에 test 출력
		=>cmdType : echo, cmdSubArgs : test

		2) start echo test
		: 새로운 명령어 프롬프트를 실행 후 해당 명령 프롬프트에서 화면에 test 출력
		=>cmdType : start, cmdSubArgs : echo test
			=>cmdType : echo, cmdSubArgs : test

		3) start start echo test
		: 새로운 명령 프롬프트 실행, 해당 명령 프롬프트에서 다시 새로운 명령 프롬프트 실행
		마지막 명령 프롬프트에서 화면에 test 출력
		=>cmdType : start, cmdSubArgs : start echo test
			=>cmdType : start, cmdSubArgs : echo test
				=>cmdType : echo, cmdSubArgs : test

		4) echo test start
		: 화면에 test 출력 후 새로운 명령 프롬프트 실행
		=>cmdType : echo, cmdSubArgs : test
			=>cmdType : start, cmdSubArgs : 비었지만 할당 상태로 처리

		---
		< 사용자 입력 및 토큰 분리, 명령어 토큰 생성 후 이벤트 호출 >

		1) 한 줄로 입력 받은 명령어를 소문자로 변경 후 토큰 목록에 추가
		2) 이하, 입력 받은 모든 토큰 목록에 대해 처리 될 때까지 반복
		3) 토큰 목록으로부터 하나의 명령어 토큰 생성 (명령어 타입 및 하위 인자 결정)
			3-1) 토큰 생성 과정에서 명령어 타입 혹은 하위 인자 결정 시 플래그 값 변경
		4) 하나의 명령어 토큰 생성 완료 시(모두 할당 상태일 경우) 해당 토큰에 대한 명령어 이벤트 처리
		5) 다음 명령어 토큰 생성을 위하여 토큰 내부 초기화 작업 수행 후 2) 부터 다시 수행
	 ***/

	while (token != NULL)
	{
		_tcscpy_s(this->_cmdTokenList[this->_lastCmdTokenIndex++], utils::StrLower(token));
		cmdToken.GenerateToken(this->_cmdTokenList[this->_lastCmdTokenIndex]);
	
		
		
		//start start 입력 시 뒤의 start를 하위인자로 처리하지 않고 다음 토큰 처리로 넘겨야 함
		_lastCmdTokenIndex++;

		token = _tcstok_s(NULL, seps, &context);
	}
}

void CmdPrompt::CmdArgvProc(int argc, TCHAR** argv)
{
	//TODO : 시작 인자 처리
}

/// <summary>
/// 명령어 이벤트 처리
/// </summary>
/// <param name="srcCmdToken">명령어 토큰</param>
void CmdPrompt::CmdEventProc(CmdToken srcCmdToken)
{
	//TODO : 명령어 이벤트 처리
	
	static const TCHAR ERROR_MSG[] = _T("'%s'은(는) 실행할 수 있는 프로그램이 아닙니다.\n");
	TCHAR cmdStringWithOptions[MAX_STR_LEN] = { NULL, };
	TCHAR subArgs[MAX_STR_LEN] = { NULL, };

	STARTUPINFO sInfo = { 0, };
	PROCESS_INFORMATION pInfo;
	BOOL processCreationState = false;

	sInfo.cb = sizeof(sInfo);

	switch(srcCmdToken.GetCmdTypeOnce())
	{
	case CMD_TYPE::EXIT:
		_fputts(_T("명령어 처리를 종료합니다.\n"), stdout);
		exit(EXIT_SUCCESS);

	case CMD_TYPE::START:
		break;

	case CMD_TYPE::ECHO:
		break;

	default:
		break;
	}


	//if (_tcscmp(_cmdTokenList[0], _T("start")) == 0)
	//{
	//	if (cmdTokenIndex > 1)
	//	{
	//		for (int i = 1; i < cmdTokenIndex; i++)
	//		{
	//			_stprintf_s(subArgs, _T("%s %s"), subArgs, _cmdTokenList[i]);

	//		}

	//		//_stprintf_s(cmdStringWithOptions, _T("%s %s"), selfProcessName, subArgs);
	//	}
	//	else //start만 입력
	//	{
	//		//	_stprintf_s(cmdStringWithOptions, _T("%s"), selfProcessName);
	//	}

	//	processCreationState =
	//		CreateProcess(
	//			NULL, cmdStringWithOptions, NULL, NULL,
	//			TRUE, 0, NULL, NULL,
	//			&sInfo, &pInfo
	//		); //해당 명령어 수행

	//	CloseHandle(pInfo.hProcess);
	//	CloseHandle(pInfo.hThread);
	//}
	//else //프로세스 생성
	//{
	//	// https://docs.microsoft.com/en-us/windows/win32/api/processthreadsapi/ns-processthreadsapi-startupinfow
	//	// https://docs.microsoft.com/en-us/windows/win32/procthread/process-creation-flags


	//	processCreationState =
	//		CreateProcess(
	//			NULL, _cmdTokenList[0], NULL, NULL,
	//			TRUE, 0, NULL, NULL,
	//			&sInfo, &pInfo
	//		); //해당 명령어 수행

	//	CloseHandle(pInfo.hProcess);
	//	CloseHandle(pInfo.hThread);

	//	if (processCreationState == FALSE) //프로세스 생성 실패 시
	//		_tprintf(ERROR_MSG, _cmdTokenList[0]);
	//}
}

/// <summary>
/// 토큰 목록 및 인덱스 초기화
/// </summary>
void CmdPrompt::ClearTokenList()
{
	for (int i = 0; i < MAX_CMD_TOKEN_COUNT; i++)
		memset(this->_cmdTokenList[i], NULL, sizeof(TCHAR) * MAX_STR_LEN);

	this->_lastCmdTokenIndex = 0;
}