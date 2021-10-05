#ifndef _CMDTOKEN_H_
#define _CMDTOKEN_H_

// CmdToken.cpp

//명령어 토큰 플래그 : DUMMY (4bit) | CMD_TYPE_FLAG (2bit) | CMD_SUBARGS_FLAG (2bit)
#define CMD_TYPE_NOT_ASSIGNED (0x0) //미 할당, 0000(2)
#define CMD_TYPE_ASSIGNED (0x4) //할당, 0100(2)
#define CMD_TYPE_EXPIRED (0x8) //만료, 1000(2)

#define CMD_SUBARGS_NOT_ASSIGNED (0x0) //미 할당, 0000(2)
#define CMD_SUBARGS_ASSIGNED (0x1) //할당, 0001(2)
#define CMD_SUBARGS_EXPIRED (0x2) //만료, 0010(2)

class CMD_TOKEN //명령어 토큰
{
public:
	CMD_TOKEN();
	~CMD_TOKEN();
	
	unsigned char GenerateToken(void* arg);

	CMD_TYPE GetCmdTypeOnce();
	const TCHAR* GetCmdSubArgsOnce();

private:
	void ClearAll();

	unsigned char _cmdTokenFlags; //명령어 토큰 플래그
	CMD_TYPE _cmdType; //명령어 타입
	TCHAR _cmdSubArgs[MAX_STR_LEN]; //해당 명령어에 대한 하위 인자
};
#endif