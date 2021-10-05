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
	this->_cmdTokenFlags = CMD_TYPE_NOT_ASSIGNED | CMD_SUBARGS_NOT_ASSIGNED;
	this->_cmdType = CMD_TYPE::OUT_OF_RANGE;
	memset(this->_cmdSubArgs, NULL, sizeof(TCHAR) * MAX_STR_LEN);
}

/// <summary>
/// ��ɾ� ��ū ����
/// ��ɾ� �Ľ̰������� �ϳ��� ó���ϹǷ� ���� �۾� �� �� ���� �ϳ��� �۾��� ����
/// </summary>
/// <param name="args">��ɾ� ��ū ���� �� ����</param>
/// <returns>��ɾ� ��ū�� ���� ����</returns>
unsigned char CMD_TOKEN::GenerateToken(void* args)
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

	this->_cmdType = CMD_TYPE_PARSER::GetCmdTypeFromString((const TCHAR*)args); //��ɾ� Ÿ�� �Ľ��Ͽ� �Ҵ�
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
enum CMD_TYPE CMD_TOKEN::GetCmdTypeOnce()
{
	if (this->_cmdTokenFlags & CMD_TYPE_EXPIRED) //�ٽ� �б� ����
		ThrowException(EX::EXPIRED_TOKEN_ACCESS);

	return this->_cmdType;
}

/// <summary>
/// ��ɾ� ���� ���� ��ȯ
/// </summary>
const TCHAR* CMD_TOKEN::GetCmdSubArgsOnce()
{
	if (this->_cmdTokenFlags & CMD_SUBARGS_EXPIRED) //�ٽ� �б� ����
		ThrowException(EX::EXPIRED_TOKEN_ACCESS);

	return this->_cmdSubArgs;
}