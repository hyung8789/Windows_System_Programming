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
/// <param name="arg">��ɾ� ��ū ���� �� ���� (Not Editable)</param>
/// <returns>��ɾ� ��ū�� ���� ����</returns>
CMD_TOKEN_FLAGS CmdToken::GenerateToken(const void* arg)
{
	/***
		< ���� �÷��� ���� ���� ��ū ���� �۾������� �̺�Ʈ ó�� >

		CMD_TYPE_ASSIGNED || CMD_SUBARGS_ASSIGNED || current event proc
		T					 T						clearAll (cmdType �� cmdSubArgs ��� EXPIRED ���¿�����), cmdTypeAssign
		T					 F						cmdSubArgsAssign
		F					 T						ThrowException (������ ��ɾ� Ÿ���� �ƴ϶� ���� ���ڷ� ó������ ��쿡�� ASSIGN ���¿��� ��)
		F					 F						cmdTypeAssign
	***/

	//TODO : TEMP ����ó�� ����
	if (arg == NULL)
		exceptionhandler::ThrowException(exceptionhandler::EX::TEMP);

	if (this->_cmdTokenFlags & (CMD_TYPE_ASSIGNED | CMD_SUBARGS_ASSIGNED)) //T T
	{
		if (this->_cmdTokenFlags & (CMD_TYPE_EXPIRED | CMD_SUBARGS_EXPIRED))
		{
			this->ClearAll(); //clearAll (EXPIRED ���¿�����)
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
	this->_cmdType = CmdTypeParser::GetCmdTypeFromString((const TCHAR*)arg); //��ɾ� Ÿ�� �Ľ��Ͽ� �Ҵ�
	this->_cmdTokenFlags |= CMD_TYPE_ASSIGNED;

	// ��ū ���� �������� ��ɾ� Ÿ���� ��ū�� �ƴ� ��쿡 NONE_CMD_TYPE���� Ÿ�� ���� �� ���� ���ڷ� ó��
	if (this->_cmdType == CMD_TYPE::NONE_CMD_TYPE)
		goto CMD_SUB_ARGS_ASSIGN_PROC;

	return this->_cmdTokenFlags;

CMD_SUB_ARGS_ASSIGN_PROC:
	_tcscpy_s(this->_cmdSubArgs, (const TCHAR*)arg); //��ɾ ���� ���� ���� ����
	this->_cmdTokenFlags |= CMD_SUBARGS_ASSIGNED;

	return this->_cmdTokenFlags;
}

/// <summary>
/// ��ɾ� Ÿ�� ��ȯ (�� ����)
/// </summary>
enum CMD_TYPE CmdToken::GetCmdTypeOnce()
{
	if (this->_cmdTokenFlags & CMD_TYPE_ASSIGNED)
	{
		if (this->_cmdTokenFlags & CMD_SUBARGS_EXPIRED) //�ٽ� �б� ����
			exceptionhandler::ThrowException(exceptionhandler::EX::EXPIRED_TOKEN_ACCESS);
	}

	this->_cmdTokenFlags |= CMD_TYPE_EXPIRED;
	return this->_cmdType;
}

/// <summary>
/// ��ɾ� ���� ���� ��ȯ (�� ����)
/// </summary>
const TCHAR* CmdToken::GetCmdSubArgsOnce()
{
	if (this->_cmdTokenFlags & CMD_SUBARGS_ASSIGNED)
	{
		if (this->_cmdTokenFlags & CMD_SUBARGS_EXPIRED) //�ٽ� �б� ����
			exceptionhandler::ThrowException(exceptionhandler::EX::EXPIRED_TOKEN_ACCESS);
	}

	/***
		����ڰ� �Է� �� ��ɾ ���� ���� ���ڰ� �Ҵ���� ���� ��� Ȥ�� 
		��ɾ� Ÿ���� �ƴϾ ���� ���ڷ� �Ҵ�� ���
		���� ��ū ó���� ���� ���� ���·� ���� �� �� �� ��ȯ
	***/

	this->_cmdTokenFlags |= CMD_SUBARGS_EXPIRED;
	return this->_cmdSubArgs;
}