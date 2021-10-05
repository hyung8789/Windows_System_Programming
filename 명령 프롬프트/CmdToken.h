#ifndef _CMDTOKEN_H_
#define _CMDTOKEN_H_

// CmdToken.cpp

//TODO : ��ū �÷��� �ּ�ȭ

enum class CMD_TOKEN_FLAG : const BOOL
{
	NOT_ASSIGNED = 0, //�� �Ҵ�
	ASSIGNED, //�Ҵ�
	USED //��� ��
};

struct CMD_TOKEN_FLAGS //��ɾ� ��ū �÷���
{
	//������ ��Ʈ���� ���ʷ� ��ġ (LSB -> MSB)
	CMD_TOKEN_FLAG _cmdTypeFlag : 3; //��ɾ� Ÿ�� �÷���
	CMD_TOKEN_FLAG _cmdSubArgsFlag : 3; //��� ��ɾ ���� ���� ���� �÷���
};

class CMD_TOKEN //��ɾ� ��ū
{
public:
	CMD_TOKEN();
	~CMD_TOKEN();

	void ClearAll();
	void GenerateToken(void* args);

	struct CMD_TOKEN_FLAGS GetCmdTokenFlags();
	enum CMD_TYPE GetCmdType();
	const TCHAR* GetCmdSubArgs();

private:
	void CmdTokenFlagsEventProc();

	struct CMD_TOKEN_FLAGS _cmdTokenFlags; //��ɾ� ��ū �÷���
	enum CMD_TYPE _cmdType; //��ɾ� Ÿ��
	TCHAR _cmdSubArgs[MAX_STR_LEN]; //�ش� ��ɾ ���� ���� ����
};
#endif