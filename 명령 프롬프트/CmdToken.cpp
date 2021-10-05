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
/// ��� �ʱ�ȭ
/// </summary>
void CMD_TOKEN::ClearAll()
{
	this->_cmdTokenFlags =
	{
		(BOOL)CMD_TOKEN_STATE::INIT,
		false,
		false
	};

	this->_cmdType = CMD_TYPE::OUT_OF_RANGE;
	memset(this->_cmdSubArgs, NULL, sizeof(TCHAR) * MAX_STR_LEN);

#ifdef DEBUG_MODE
	_fputts(_T("CMD_TOKEN Cleared\n"), stdout);
#endif
}

/// <summary>
/// ��ɾ� ��ū ����
/// ��ɾ� �Ľ̰������� �ϳ��� ó���ϹǷ� ���� �۾� �� �� ���� �ϳ��� �۾��� ����
/// </summary>
/// <param name="args">��ɾ� ��ū ���� �� ����</param>
void CMD_TOKEN::GenerateToken(void* args)
{
	//TODO : ��ɾ� ��ū ���� �۾�

	if (!this->_cmdTokenFlags._isCmdTypeAssigned)
		goto CMD_TYPE_ASSIGN_PROC;
	else if (!this->_cmdTokenFlags._isCmdSubArgsAssigned)
		goto CMD_SUB_ARGS_ASSIGN_PROC;
	else

	///��ɾ� ��ū�� ��� �� ���´� ���� ���� ������Ѿ� �ϴ°�?
///��ɾ� ������Ʈ�� �̺�Ʈ ó�� �� ��ɾ� ��ū�� ��ɾ� Ÿ�԰� ���ڸ� �д� ������ 
/// ��ɾ� Ÿ�� Ȥ�� ���� ���ڰ� �о ���Ǿ����� ��Ÿ���� �÷��� �߰�
/// �� �� ��� ��� �Ǿ��� ��쿡 ��ɾ� ��ū�� ���� ���·� ����
/// �̴� �� ��ɾ� Ÿ�� Ȥ�� ���ڸ� �д� ������ ��ɾ� ��ū ���ο��� ó��


CMD_TYPE_ASSIGN_PROC:
	this->_cmdType = CMD_TYPE_PARSER::GetCmdTypeFromString((const TCHAR*)args); //��ɾ� Ÿ�� �Ľ��Ͽ� �Ҵ�
	// ��ɾ �̹� �Ҵ�Ǿ����� start start echo test�� ���� �ٽ� ��ɾ �� ���

	if (this->_cmdType == CMD_TYPE::NONE_CMD_TYPE) //�������ڷ�ó��
	{

	}

	this->_cmdTokenFlags._isCmdTypeAssigned = true;


CMD_SUB_ARGS_ASSIGN_PROC:
	_tcscpy_s(this->_cmdSubArgs, (const TCHAR*)args); //��ɾ ���� ���� ���� ����
	this->_cmdTokenFlags._isCmdSubArgsAssigned = true;


	
}

/// <summary>
/// ��ɾ� ��ū �÷��� ��ȯ
/// </summary>
struct CMD_TOKEN_FLAGS CMD_TOKEN::GetCmdTokenFlags()
{
	return this->_cmdTokenFlags;
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

/// <summary>
/// ��ɾ� ��ū �÷��� �̺�Ʈ ó��
/// </summary>
void CMD_TOKEN::CmdTokenFlagsEventProc()
{
	//TODO : �÷��� �̺�Ʈ ó�� ����

	switch (this->_cmdTokenFlags._cmdTokenState)
	{
	case (const BOOL)CMD_TOKEN_STATE::INIT:
		this->_cmdTokenFlags._cmdTokenState = (const BOOL)CMD_TOKEN_STATE::INCOMPLETE;
		break;

	case (const BOOL)CMD_TOKEN_STATE::INCOMPLETE:
		if (this->_cmdTokenFlags._isCmdTypeAssigned &&
			this->_cmdTokenFlags._isCmdSubArgsAssigned)
			this->_cmdTokenFlags._cmdTokenState = (const BOOL)CMD_TOKEN_STATE::COMPLETE;
		break;

	case (const BOOL)CMD_TOKEN_STATE::COMPLETE:
	case (const BOOL)CMD_TOKEN_STATE::USED:
		return;
	}
}
