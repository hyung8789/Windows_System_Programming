#ifndef _CMDTOKEN_H_
#define _CMDTOKEN_H_

// CmdToken.cpp

//��ɾ� ��ū �÷��� : DUMMY (4bit) | CMD_TYPE_FLAG (2bit) | CMD_SUBARGS_FLAG (2bit)
#define CMD_TYPE_NOT_ASSIGNED (0x0) //�� �Ҵ�, 0000(2)
#define CMD_TYPE_ASSIGNED (0x4) //�Ҵ�, 0100(2)
#define CMD_TYPE_EXPIRED (0x8) //����, 1000(2)

#define CMD_SUBARGS_NOT_ASSIGNED (0x0) //�� �Ҵ�, 0000(2)
#define CMD_SUBARGS_ASSIGNED (0x1) //�Ҵ�, 0001(2)
#define CMD_SUBARGS_EXPIRED (0x2) //����, 0010(2)

class CMD_TOKEN //��ɾ� ��ū
{
public:
	CMD_TOKEN();
	~CMD_TOKEN();
	
	unsigned char GenerateToken(void* arg);

	CMD_TYPE GetCmdTypeOnce();
	const TCHAR* GetCmdSubArgsOnce();

private:
	void ClearAll();

	unsigned char _cmdTokenFlags; //��ɾ� ��ū �÷���
	CMD_TYPE _cmdType; //��ɾ� Ÿ��
	TCHAR _cmdSubArgs[MAX_STR_LEN]; //�ش� ��ɾ ���� ���� ����
};
#endif