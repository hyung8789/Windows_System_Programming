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
		(BOOL)CMD_TOKEN_STATE::NOT_ASSIGNED,
		(BOOL)CMD_TOKEN_STATE::NOT_ASSIGNED
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

	/***
		< ���� �÷��� ���� ���� �̺�Ʈ ó�� >

		_cmdTypeFlag |  _cmdSubArgsFlag | event proc
		NOT_ASSIGNED	NOT_ASSIGNED	 cmdType �Ҵ�
		NOT_ASSIGNED	UPDATED			 ����
		UPDATED			NOT_ASSIGNED	 cmdSubArgs �Ҵ�
		UPDATED			UPDATED			 ���� (�̹� ��� �Ҵ� �Ϸ� �� ����)
	***/

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



CMD_SUB_ARGS_ASSIGN_PROC:
	_tcscpy_s(this->_cmdSubArgs, (const TCHAR*)args); //��ɾ ���� ���� ���� ����


}

/// <summary>
/// ��ɾ� Ÿ�� ��ȯ
/// </summary>
enum CMD_TYPE CMD_TOKEN::GetCmdTypeOnce()
{
	if (this->_cmdTokenFlags._cmdTypeFlag == (const BOOL)CMD_TOKEN_STATE::OUT_DATED) //�ٽ� �б� ����
		ThrowException(EX::ACCESSED_OUT_DATED_CMD_TOKEN, _T("���� �� ��ū ����"));

	return this->_cmdType;
}

/// <summary>
/// ��ɾ� ���� ���� ��ȯ
/// </summary>
const TCHAR* CMD_TOKEN::GetCmdSubArgsOnce()
{
	if (this->_cmdTokenFlags._cmdSubArgsFlag == (const BOOL)CMD_TOKEN_STATE::OUT_DATED) //�ٽ� �б� ����
		ThrowException(EX::ACCESSED_OUT_DATED_CMD_TOKEN, _T("���� �� ��ū ����"));

	return this->_cmdSubArgs;
}