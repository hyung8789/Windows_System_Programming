#include "Core.h"

CmdToken::CmdToken()
{
	this->ClearAll();
}

CmdToken::~CmdToken()
{

}

/// <summary>
/// ��� �ʱ�ȭ
/// </summary>
void CmdToken::ClearAll()
{
	this->_cmdTokenFlags = FALSE_BIT;
	this->_cmdType = CMD_TYPE::OUT_OF_RANGE;
	memset(this->_cmdSubArgs, NULL, sizeof(TCHAR) * MAX_STR_LEN);
}

/// <summary>
/// ��ɾ� ��ū ����
/// ��ɾ� �Ľ̰������� �ϳ��� ó���ϹǷ� ���� �۾� �� �� ���� �ϳ��� �۾��� ����
/// </summary>
/// <param name="arg">��ɾ� ��ū ���� �� ����</param>
/// <returns>��ɾ� ��ū�� ���� ����</returns>
CMD_TOKEN_FLAGS CmdToken::GenerateToken(void* arg)
{
	/***
		< ���� �÷��� ���� ���� ��ū ���� �۾������� �̺�Ʈ ó�� >

		CMD_TYPE_ASSIGNED || CMD_SUBARGS_ASSIGNED || current event proc
		T					 T						clearAll (cmdType �� cmdSubArgs ��� EXPIRED ���¿�����), cmdTypeAssign
		T					 F						cmdSubArgsAssign
		F					 T						ThrowException (��ɾ� Ÿ���� �ƴ϶� ���� ���ڷ� ó���ϴ��� CMD_TYPE_ASSIGNED�� T)
		F					 F						cmdTypeAssign

	***/

	if (this->_cmdTokenFlags & (CMD_TYPE_ASSIGNED | CMD_SUBARGS_ASSIGNED)) //T T
	{ 
		if (this->_cmdTokenFlags & (CMD_TYPE_EXPIRED | CMD_SUBARGS_EXPIRED))
		{
			this->ClearAll(); //clearAll (EXPIRED ���¿�����)
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
		//TODO : ���� ��ū ���¿� ���� ����ó�� �߰�
	}

	this->_cmdType = CmdTypeParser::GetCmdTypeFromString((const TCHAR*)arg); //��ɾ� Ÿ�� �Ľ��Ͽ� �Ҵ�
	//��ū ���� �������� ��ɾ� Ÿ���� ��ū�� �ƴ� ��� ���� ���ڷμ� ó��



	if (this->_cmdType == CMD_TYPE::NONE_CMD_TYPE) //�������ڷ�ó��
	{

	}



CMD_SUB_ARGS_ASSIGN_PROC:
	_tcscpy_s(this->_cmdSubArgs, (const TCHAR*)arg); //��ɾ ���� ���� ���� ����

	return this->_cmdTokenFlags;
}

/// <summary>
/// ��ɾ� Ÿ�� ��ȯ
/// </summary>
enum CMD_TYPE CmdToken::GetCmdTypeOnce()
{
	if (this->_cmdTokenFlags & CMD_TYPE_ASSIGNED)
	{
		if (this->_cmdTokenFlags & CMD_SUBARGS_EXPIRED) //�ٽ� �б� ����
			exceptionhandler::ThrowException(exceptionhandler::EX::EXPIRED_TOKEN_ACCESS);

		this->_cmdTokenFlags |= CMD_TYPE_EXPIRED;

		return this->_cmdType;
	}

	exceptionhandler::ThrowException(exceptionhandler::EX::NOT_ASSIGNED_TOKEN_ACCESS);
}

/// <summary>
/// ��ɾ� ���� ���� ��ȯ
/// </summary>
const TCHAR* CmdToken::GetCmdSubArgsOnce()
{
	if (this->_cmdTokenFlags & CMD_SUBARGS_ASSIGNED)
	{
		if (this->_cmdTokenFlags & CMD_SUBARGS_EXPIRED) //�ٽ� �б� ����
			exceptionhandler::ThrowException(exceptionhandler::EX::EXPIRED_TOKEN_ACCESS);

		this->_cmdTokenFlags |= CMD_SUBARGS_EXPIRED;

		return this->_cmdSubArgs;
	}

	exceptionhandler::ThrowException(exceptionhandler::EX::NOT_ASSIGNED_TOKEN_ACCESS);
}