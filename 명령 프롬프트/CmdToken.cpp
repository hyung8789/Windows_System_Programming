#include "Core.h"


CmdToken::CmdToken()
{
	this->ClearAll();
}

CmdToken::~CmdToken()
{

}

/// <summary>
/// 모두 초기화
/// </summary>
void CmdToken::ClearAll()
{
	this->_cmdTokenFlags = FALSE_BIT;
	this->_cmdType = CMD_TYPE::OUT_OF_RANGE;
	memset(this->_cmdSubArgs, NULL, sizeof(TCHAR) * MAX_STR_LEN);
}

/// <summary>
/// 명령어 토큰 생성
/// 명령어 파싱과정에서 하나씩 처리하므로 생성 작업 시 한 번에 하나의 작업만 수행
/// </summary>
/// <param name="args">명령어 토큰 생성 시 인자</param>
/// <returns>명령어 토큰의 현재 상태</returns>
unsigned char CmdToken::GenerateToken(void* args)
{
	//TODO : 명령어 토큰 생성 작업
	//
	/***
		< 현재 플래그 값에 따른 토큰 생성 작업에서의 이벤트 처리 >

		cmdTypeFlag |  cmdSubArgsFlag | event proc

	***/

CMD_TYPE_ASSIGN_PROC:

	if (args == NULL)
	{
		//TODO : 현재 토큰 상태에 따라 예외처리 추가
	}

	this->_cmdType = CmdTypeParser::GetCmdTypeFromString((const TCHAR*)args); //명령어 타입 파싱하여 할당
	// 명령어가 이미 할당되었지만 start start echo test와 같이 다시 명령어가 올 경우

	if (this->_cmdType == CMD_TYPE::NONE_CMD_TYPE) //하위인자로처리
	{

	}



CMD_SUB_ARGS_ASSIGN_PROC:
	_tcscpy_s(this->_cmdSubArgs, (const TCHAR*)args); //명령어에 대한 하위 인자 복사

	return this->_cmdTokenFlags;
}

/// <summary>
/// 명령어 타입 반환
/// </summary>
enum CMD_TYPE CmdToken::GetCmdTypeOnce()
{
	if (this->_cmdTokenFlags & CMD_TYPE_EXPIRED) //다시 읽기 방지
		exceptionhandler::ThrowException(exceptionhandler::EX::EXPIRED_TOKEN_ACCESS);

	return this->_cmdType;
}

/// <summary>
/// 명령어 하위 인자 반환
/// </summary>
const TCHAR* CmdToken::GetCmdSubArgsOnce()
{
	if (this->_cmdTokenFlags & CMD_SUBARGS_EXPIRED) //다시 읽기 방지
		exceptionhandler::ThrowException(exceptionhandler::EX::EXPIRED_TOKEN_ACCESS);

	return this->_cmdSubArgs;
}