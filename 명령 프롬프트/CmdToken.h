#ifndef _CMDTOKEN_H_
#define _CMDTOKEN_H_

// CmdToken.cpp

enum class CMD_TOKEN_STATE : const BOOL //��ɾ� ��ū ����
{
	//��ɾ� ��ū ���� ������ ���� 4��Ʈ(2^2 = 4) �ʿ�

	INIT = 0, //�ʱ� ����
	INCOMPLETE, //�ҿ��� ���� : �Ϻ� �Ҵ� ����
	COMPLETE, //���� ���� : ���� �Ҵ� �Ϸ� ����
	USED //���� ���� : ��� �� ��ū�� ���� ����
};
 
struct CMD_TOKEN_FLAGS //��ɾ� ��ū �÷���
{
	//������ ��Ʈ���� ���ʷ� ��ġ (LSB -> MSB)

	BOOL _cmdTokenState : 4; //��ɾ� ��ū ���� (MSB)
	BOOL _isCmdTypeUsed : 1; //��ɾ� Ÿ�� ��� ����
	BOOL _isCmdSubArgsUsed : 1; //��ɾ� ���� ���� ��� ����
	BOOL _isCmdTypeAssigned : 1;  //��ɾ� Ÿ�� �Ҵ� ����
	BOOL _isCmdSubArgsAssigned : 1; //�ش� ��ɾ ���� ���� ���� �Ҵ� ���� 
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