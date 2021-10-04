#include "Core.h"


CMD_TOKEN::CMD_TOKEN()
{
	this->ClearAll();
}

CMD_TOKEN::~CMD_TOKEN()
{

}

/// <summary>
/// 모두 초기화
/// </summary>
void CMD_TOKEN::ClearAll()
{
	this->_cmdType = CMD_TYPE::OUT_OF_RANGE;
	memset(this->_cmdSubArgs, NULL, sizeof(TCHAR) * MAX_STR_LEN);

	this->isCmdSubArgsAssigned = this->isCmdTypeAssigned = false;
}

/// <summary>
/// 명령어 토큰 생성
/// 명령어 파싱과정에서 하나씩 처리하므로 생성 작업 시 한 번에 하나의 작업만 수행
/// </summary>
/// <param name="args">명령어 토큰 생성 시 인자</param>
void CMD_TOKEN::GenerateToken(void* args)
{
	if (!this->isCmdTypeAssigned)
		goto CMD_TYPE_ASSIGN_PROC;
	else if (!this->isCmdSubArgsAssigned)
		goto CMD_SUB_ARGS_ASSIGN_PROC;
	else
		return;
/// <summary>
/// 
/// </summary>
/// <param name="args"></param>
CMD_TYPE_ASSIGN_PROC:
	this->_cmdType = CMD_TYPE_PARSER::GetCmdTypeFromString((const TCHAR*)args); //명령어 타입 파싱하여 할당
	if (this->_cmdType == CMD_TYPE::NONE_CMD_TYPE) //하위인자로처리
	{

	}

	this->isCmdTypeAssigned = true;
	return;

CMD_SUB_ARGS_ASSIGN_PROC:
	_tcscpy_s(this->_cmdSubArgs, (const TCHAR*)args); //명령어에 대한 하위 인자 복사
	this->isCmdSubArgsAssigned = true;
	return;
}

/// <summary>
/// 명령어 타입 반환 
/// </summary>
enum CMD_TYPE CMD_TOKEN::GetCmdType()
{
	return this->_cmdType;
}

/// <summary>
/// 명령어 하위 인자 반환
/// </summary>
const TCHAR* CMD_TOKEN::GetCmdSubArgs()
{
	return this->_cmdSubArgs;
}