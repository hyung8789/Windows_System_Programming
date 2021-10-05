#include "Core.h"


CMD_TOKEN::CMD_TOKEN()
{
	this->ClearAll();

#ifdef DEBUG_MODE
	_fputts(_T("CMD_TOKEN Generated\n"), stdout);
#endif
}

CMD_TOKEN::~CMD_TOKEN()
{

}

/// <summary>
/// 모두 초기화
/// </summary>
void CMD_TOKEN::ClearAll()
{
	this->_cmdTokenFlags =
	{
		(BOOL)CMD_TOKEN_STATE::NOT_ASSIGNED,
		(BOOL)CMD_TOKEN_STATE::NOT_ASSIGNED
	};

	this->_cmdType = CMD_TYPE::OUT_OF_RANGE;
	memset(this->_cmdSubArgs, NULL, sizeof(TCHAR) * MAX_STR_LEN);

#ifdef DEBUG_MODE
	_fputts(_T("CMD_TOKEN Cleared\n"), stdout);
#endif
}

/// <summary>
/// 명령어 토큰 생성
/// 명령어 파싱과정에서 하나씩 처리하므로 생성 작업 시 한 번에 하나의 작업만 수행
/// </summary>
/// <param name="args">명령어 토큰 생성 시 인자</param>
void CMD_TOKEN::GenerateToken(void* args)
{
	//TODO : 명령어 토큰 생성 작업

	/***
		< 현재 플래그 값에 따른 이벤트 처리 >

		_cmdTypeFlag |  _cmdSubArgsFlag | event proc
		NOT_ASSIGNED	NOT_ASSIGNED	 cmdType 할당
		NOT_ASSIGNED	UPDATED			 오류
		UPDATED			NOT_ASSIGNED	 cmdSubArgs 할당
		UPDATED			UPDATED			 오류 (이미 모두 할당 완료 된 상태)
	***/

	///명령어 토큰이 사용 됨 상태는 언제 누가 변경시켜야 하는가?
///명령어 프롬프트의 이벤트 처리 시 명령어 토큰의 명령어 타입과 인자를 읽는 시점에 
/// 명령어 타입 혹은 하위 인자가 읽어서 사용되었음을 나타내는 플래그 추가
/// 두 개 모두 사용 되었을 경우에 명령어 토큰이 사용됨 상태로 변경
/// 이는 각 명령어 타입 혹은 인자를 읽는 시점에 명령어 토큰 내부에서 처리


CMD_TYPE_ASSIGN_PROC:
	this->_cmdType = CMD_TYPE_PARSER::GetCmdTypeFromString((const TCHAR*)args); //명령어 타입 파싱하여 할당
	// 명령어가 이미 할당되었지만 start start echo test와 같이 다시 명령어가 올 경우

	if (this->_cmdType == CMD_TYPE::NONE_CMD_TYPE) //하위인자로처리
	{

	}



CMD_SUB_ARGS_ASSIGN_PROC:
	_tcscpy_s(this->_cmdSubArgs, (const TCHAR*)args); //명령어에 대한 하위 인자 복사


}

/// <summary>
/// 명령어 타입 반환
/// </summary>
enum CMD_TYPE CMD_TOKEN::GetCmdTypeOnce()
{
	if (this->_cmdTokenFlags._cmdTypeFlag == (const BOOL)CMD_TOKEN_STATE::OUT_DATED) //다시 읽기 방지
		ThrowException(EX::ACCESSED_OUT_DATED_CMD_TOKEN, _T("만료 된 토큰 접근"));

	return this->_cmdType;
}

/// <summary>
/// 명령어 하위 인자 반환
/// </summary>
const TCHAR* CMD_TOKEN::GetCmdSubArgsOnce()
{
	if (this->_cmdTokenFlags._cmdSubArgsFlag == (const BOOL)CMD_TOKEN_STATE::OUT_DATED) //다시 읽기 방지
		ThrowException(EX::ACCESSED_OUT_DATED_CMD_TOKEN, _T("만료 된 토큰 접근"));

	return this->_cmdSubArgs;
}