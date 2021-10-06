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
/// <param name="arg">명령어 토큰 생성 시 인자 (Not Editable)</param>
/// <returns>명령어 토큰의 현재 상태</returns>
CMD_TOKEN_FLAGS CmdToken::GenerateToken(const void* arg)
{
	/***
		< 현재 플래그 값에 따른 토큰 생성 작업에서의 이벤트 처리 >

		CMD_TYPE_ASSIGNED || CMD_SUBARGS_ASSIGNED || current event proc
		T					 T						clearAll (cmdType 및 cmdSubArgs 모두 EXPIRED 상태여야함), cmdTypeAssign
		T					 F						cmdSubArgsAssign
		F					 T						ThrowException (이전에 명령어 타입이 아니라서 하위 인자로 처리했을 경우에도 ASSIGN 상태여야 함)
		F					 F						cmdTypeAssign
	***/

	//TODO : TEMP 예외처리 수정
	if (arg == NULL)
		exceptionhandler::ThrowException(exceptionhandler::EX::TEMP);

	if (this->_cmdTokenFlags & (CMD_TYPE_ASSIGNED | CMD_SUBARGS_ASSIGNED)) //T T
	{
		if (this->_cmdTokenFlags & (CMD_TYPE_EXPIRED | CMD_SUBARGS_EXPIRED))
		{
			this->ClearAll(); //clearAll (EXPIRED 상태여야함)
			goto CMD_TYPE_ASSIGN_PROC;
		}
		else
			exceptionhandler::ThrowException(exceptionhandler::EX::NOT_USED_TOKEN_EXIST);
	}
	else if (!(this->_cmdTokenFlags & (CMD_TYPE_ASSIGNED | CMD_SUBARGS_ASSIGNED))) //F F
	{
		goto CMD_TYPE_ASSIGN_PROC;
	}
	else //T F or F T
	{
		if (!(this->_cmdTokenFlags & (CMD_TYPE_ASSIGNED)))
			exceptionhandler::ThrowException(exceptionhandler::EX::WRONG_CMD_TYPE_FLAG);

		goto CMD_SUB_ARGS_ASSIGN_PROC;
	}

CMD_TYPE_ASSIGN_PROC:
	this->_cmdType = CmdTypeParser::GetCmdTypeFromString((const TCHAR*)arg); //명령어 타입 파싱하여 할당
	this->_cmdTokenFlags |= CMD_TYPE_ASSIGNED;

	// 토큰 생성 과정에서 명령어 타입의 토큰이 아닐 경우에 NONE_CMD_TYPE으로 타입 설정 및 하위 인자로 처리
	if (this->_cmdType == CMD_TYPE::NONE_CMD_TYPE)
		goto CMD_SUB_ARGS_ASSIGN_PROC;

	return this->_cmdTokenFlags;

CMD_SUB_ARGS_ASSIGN_PROC:
	_tcscpy_s(this->_cmdSubArgs, (const TCHAR*)arg); //명령어에 대한 하위 인자 복사
	this->_cmdTokenFlags |= CMD_SUBARGS_ASSIGNED;

	return this->_cmdTokenFlags;
}

/// <summary>
/// 명령어 타입 반환 (한 번만)
/// </summary>
enum CMD_TYPE CmdToken::GetCmdTypeOnce()
{
	if (this->_cmdTokenFlags & CMD_TYPE_ASSIGNED)
	{
		if (this->_cmdTokenFlags & CMD_SUBARGS_EXPIRED) //다시 읽기 방지
			exceptionhandler::ThrowException(exceptionhandler::EX::EXPIRED_TOKEN_ACCESS);
	}

	this->_cmdTokenFlags |= CMD_TYPE_EXPIRED;
	return this->_cmdType;
}

/// <summary>
/// 명령어 하위 인자 반환 (한 번만)
/// </summary>
const TCHAR* CmdToken::GetCmdSubArgsOnce()
{
	if (this->_cmdTokenFlags & CMD_SUBARGS_ASSIGNED)
	{
		if (this->_cmdTokenFlags & CMD_SUBARGS_EXPIRED) //다시 읽기 방지
			exceptionhandler::ThrowException(exceptionhandler::EX::EXPIRED_TOKEN_ACCESS);
	}

	/***
		사용자가 입력 한 명령어에 대해 하위 인자가 할당되지 않은 경우 혹은 
		명령어 타입이 아니어서 하위 인자로 할당된 경우
		다음 토큰 처리를 위해 만료 상태로 변경 및 빈 값 반환
	***/

	this->_cmdTokenFlags |= CMD_SUBARGS_EXPIRED;
	return this->_cmdSubArgs;
}