#ifndef _CMDTOKEN_H_
#define _CMDTOKEN_H_

// CmdToken.cpp

enum class CMD_TOKEN_STATE : const BOOL //��ɾ� ��ū ����
{
	//3���� ���¿� ���Ͽ� 2^2 = 4, 2��Ʈ �ʿ�

	NOT_ASSIGNED = 0, //�� �Ҵ� ����
	UPDATED, //�б� ���� �ֽ� ����
	OUT_DATED //�̹� �о ���� �� ���� (�ٽ� �б� ����)
};

struct CMD_TOKEN_FLAGS //��ɾ� ��ū �÷���
{
	//������ ��Ʈ���� ���ʷ� ��ġ (LSB -> MSB)
	BOOL _cmdTypeFlag : 2; //��ɾ� Ÿ�� �÷���
	BOOL _cmdSubArgsFlag : 2; //��� ��ɾ ���� ���� ���� �÷���
};

class CMD_TOKEN //��ɾ� ��ū
{
public:
	CMD_TOKEN();
	~CMD_TOKEN();
	
	void GenerateToken(void* args);

	CMD_TYPE GetCmdTypeOnce();
	const TCHAR* GetCmdSubArgsOnce();

private:
	void ClearAll();

	CMD_TOKEN_FLAGS _cmdTokenFlags; //��ɾ� ��ū �÷���
	CMD_TYPE _cmdType; //��ɾ� Ÿ��
	TCHAR _cmdSubArgs[MAX_STR_LEN]; //�ش� ��ɾ ���� ���� ����
};
#endif