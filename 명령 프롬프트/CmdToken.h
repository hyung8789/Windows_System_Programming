#ifndef _CMDTOKEN_H_
#define _CMDTOKEN_H_

// CmdToken.cpp

/***
	< CMD_TOKEN_FLAGS >
	DUMMY (MSB, CMD_TYPE, 2bit) | ASSIGNED (CMD_TYPE, 1bit) | EXPIRED (CMD_TYPE, 1bit) |
	DUMMY (CMD_SUBARGS, 2bit) | ASSIGNED (CMD_SUBARGS, 1bit) | EXPIRED (LSB, CMD_SUBARGS, 1bit)
***/

typedef unsigned char CMD_TOKEN_FLAGS;

#define TRUE_BIT (0x1)
#define FALSE_BIT (0x0)

#define CMD_TYPE_ASSIGNED (0x20) //�Ҵ� ����, 0010 0000(2)
#define CMD_TYPE_EXPIRED (0x10) //���� ����, 0001 0000(2)

#define CMD_SUBARGS_ASSIGNED (0x2) //�Ҵ� ����, 0000 0010(2)
#define CMD_SUBARGS_EXPIRED (0x1) //���� ����, 0000 0001(2)

class CmdToken //��ɾ� ��ū
{
public:
	CmdToken();
	~CmdToken();
	
	CMD_TOKEN_FLAGS GenerateToken(void* arg);

	CMD_TYPE GetCmdTypeOnce();
	const TCHAR* GetCmdSubArgsOnce();

private:
	void ClearAll();

	CMD_TOKEN_FLAGS _cmdTokenFlags; //��ɾ� ��ū �÷���
	CMD_TYPE _cmdType; //��ɾ� Ÿ��
	TCHAR _cmdSubArgs[MAX_STR_LEN]; //�ش� ��ɾ ���� ���� ����
};
#endif