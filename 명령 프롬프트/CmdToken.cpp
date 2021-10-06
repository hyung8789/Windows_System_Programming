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
/// <param name="args">��ɾ� ��ū ���� �� ����</param>
/// <returns>��ɾ� ��ū�� ���� ����</returns>
unsigned char CmdToken::GenerateToken(void* args)
{
	//TODO : ��ɾ� ��ū ���� �۾�
	//
	/***
		< ���� �÷��� ���� ���� ��ū ���� �۾������� �̺�Ʈ ó�� >

		cmdTypeFlag |  cmdSubArgsFlag | event proc

	***/

CMD_TYPE_ASSIGN_PROC:

	if (args == NULL)
	{
		//TODO : ���� ��ū ���¿� ���� ����ó�� �߰�
	}

	this->_cmdType = CmdTypeParser::GetCmdTypeFromString((const TCHAR*)args); //��ɾ� Ÿ�� �Ľ��Ͽ� �Ҵ�
	// ��ɾ �̹� �Ҵ�Ǿ����� start start echo test�� ���� �ٽ� ��ɾ �� ���

	if (this->_cmdType == CMD_TYPE::NONE_CMD_TYPE) //�������ڷ�ó��
	{

	}



CMD_SUB_ARGS_ASSIGN_PROC:
	_tcscpy_s(this->_cmdSubArgs, (const TCHAR*)args); //��ɾ ���� ���� ���� ����

	return this->_cmdTokenFlags;
}

/// <summary>
/// ��ɾ� Ÿ�� ��ȯ
/// </summary>
enum CMD_TYPE CmdToken::GetCmdTypeOnce()
{
	if (this->_cmdTokenFlags & CMD_TYPE_EXPIRED) //�ٽ� �б� ����
		exceptionhandler::ThrowException(exceptionhandler::EX::EXPIRED_TOKEN_ACCESS);

	return this->_cmdType;
}

/// <summary>
/// ��ɾ� ���� ���� ��ȯ
/// </summary>
const TCHAR* CmdToken::GetCmdSubArgsOnce()
{
	if (this->_cmdTokenFlags & CMD_SUBARGS_EXPIRED) //�ٽ� �б� ����
		exceptionhandler::ThrowException(exceptionhandler::EX::EXPIRED_TOKEN_ACCESS);

	return this->_cmdSubArgs;
}