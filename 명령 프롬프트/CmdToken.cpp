#include "Core.h"


CMD_TOKEN::CMD_TOKEN()
{
	this->ClearAll();
}

CMD_TOKEN::~CMD_TOKEN()
{

}

/// <summary>
/// ��� �ʱ�ȭ
/// </summary>
void CMD_TOKEN::ClearAll()
{
	this->_cmdType = CMD_TYPE::OUT_OF_RANGE;
	memset(this->_cmdSubArgs, NULL, sizeof(TCHAR) * MAX_STR_LEN);

	this->isCmdSubArgsAssigned = this->isCmdTypeAssigned = false;
}

/// <summary>
/// ��ɾ� ��ū ����
/// ��ɾ� �Ľ̰������� �ϳ��� ó���ϹǷ� ���� �۾� �� �� ���� �ϳ��� �۾��� ����
/// </summary>
/// <param name="args">��ɾ� ��ū ���� �� ����</param>
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
	this->_cmdType = CMD_TYPE_PARSER::GetCmdTypeFromString((const TCHAR*)args); //��ɾ� Ÿ�� �Ľ��Ͽ� �Ҵ�
	if (this->_cmdType == CMD_TYPE::NONE_CMD_TYPE) //�������ڷ�ó��
	{

	}

	this->isCmdTypeAssigned = true;
	return;

CMD_SUB_ARGS_ASSIGN_PROC:
	_tcscpy_s(this->_cmdSubArgs, (const TCHAR*)args); //��ɾ ���� ���� ���� ����
	this->isCmdSubArgsAssigned = true;
	return;
}

/// <summary>
/// ��ɾ� Ÿ�� ��ȯ 
/// </summary>
enum CMD_TYPE CMD_TOKEN::GetCmdType()
{
	return this->_cmdType;
}

/// <summary>
/// ��ɾ� ���� ���� ��ȯ
/// </summary>
const TCHAR* CMD_TOKEN::GetCmdSubArgs()
{
	return this->_cmdSubArgs;
}