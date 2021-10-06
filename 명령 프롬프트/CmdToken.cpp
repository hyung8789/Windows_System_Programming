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
/// <param name="arg">명령어 토큰 생성 시 인자</param>
/// <returns>명령어 토큰의 현재 상태</returns>
CMD_TOKEN_FLAGS CmdToken::GenerateToken(void* arg)
{
	/***
		< 현재 플래그 값에 따른 토큰 생성 작업에서의 이벤트 처리 >

		CMD_TYPE_ASSIGNED || CMD_SUBARGS_ASSIGNED || current event proc
		T					 T						clearAll (cmdType 및 cmdSubArgs 모두 EXPIRED 상태여야함), cmdTypeAssign
		T					 F						cmdSubArgsAssign
		F					 T						ThrowException (명령어 타입이 아니라서 하위 인자로 처리하더라도 CMD_TYPE_ASSIGNED는 T)
		F					 F						cmdTypeAssign

	***/

	if (this->_cmdTokenFlags & (CMD_TYPE_ASSIGNED | CMD_SUBARGS_ASSIGNED)) //T T
	{ 
		if (this->_cmdTokenFlags & (CMD_TYPE_EXPIRED | CMD_SUBARGS_EXPIRED))
		{
			this->ClearAll(); //clearAll (EXPIRED 상태여야함)
			//cmdTypeAssign
		}
		else	
			exceptionhandler::ThrowException(exceptionhandler::EX::NOT_USED_TOKEN_EXIST);
	}
	else if(!this->_cmdTokenFlags & (CMD_TYPE_ASSIGNED | CMD_SUBARGS_ASSIGNED)) //F F
	{
		//cmdTypeAssign
		
	}
	else //T F or F T
	{
		if(this->_cmdTokenFlags & (CMD_SUBARGS_ASSIGNED))
			exceptionhandler::ThrowException(exceptionhandler::EX::WRONG_CMD_TYPE_FLAG);

		//cmdSubArgsAssign
	}


CMD_TYPE_ASSIGN_PROC:

	if (arg == NULL)
	{
		//TODO : 현재 토큰 상태에 따라 예외처리 추가
	}

	this->_cmdType = CmdTypeParser::GetCmdTypeFromString((const TCHAR*)arg); //명령어 타입 파싱하여 할당
	//토큰 생성 과정에서 명령어 타입의 토큰이 아닐 경우 하위 인자로서 처리



	if (this->_cmdType == CMD_TYPE::NONE_CMD_TYPE) //하위인자로처리
	{

	}



CMD_SUB_ARGS_ASSIGN_PROC:
	_tcscpy_s(this->_cmdSubArgs, (const TCHAR*)arg); //명령어에 대한 하위 인자 복사

	return this->_cmdTokenFlags;
}

/// <summary>
/// 명령어 타입 반환
/// </summary>
enum CMD_TYPE CmdToken::GetCmdTypeOnce()
{
	if (this->_cmdTokenFlags & CMD_TYPE_ASSIGNED)
	{
		if (this->_cmdTokenFlags & CMD_SUBARGS_EXPIRED) //다시 읽기 방지
			exceptionhandler::ThrowException(exceptionhandler::EX::EXPIRED_TOKEN_ACCESS);

		this->_cmdTokenFlags |= CMD_TYPE_EXPIRED;

		return this->_cmdType;
	}

	exceptionhandler::ThrowException(exceptionhandler::EX::NOT_ASSIGNED_TOKEN_ACCESS);
}

/// <summary>
/// 명령어 하위 인자 반환
/// </summary>
const TCHAR* CmdToken::GetCmdSubArgsOnce()
{
	if (this->_cmdTokenFlags & CMD_SUBARGS_ASSIGNED)
	{
		if (this->_cmdTokenFlags & CMD_SUBARGS_EXPIRED) //다시 읽기 방지
			exceptionhandler::ThrowException(exceptionhandler::EX::EXPIRED_TOKEN_ACCESS);

		this->_cmdTokenFlags |= CMD_SUBARGS_EXPIRED;

		return this->_cmdSubArgs;
	}

	exceptionhandler::ThrowException(exceptionhandler::EX::NOT_ASSIGNED_TOKEN_ACCESS);
}