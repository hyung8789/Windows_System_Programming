#ifndef _CMDTOKEN_H_
#define _CMDTOKEN_H_

// CmdToken.cpp

//TODO : 토큰 플래그 최소화

enum class CMD_TOKEN_FLAG : const BOOL
{
	NOT_ASSIGNED = 0, //미 할당
	ASSIGNED, //할당
	USED //사용 됨
};

struct CMD_TOKEN_FLAGS //명령어 토큰 플래그
{
	//최하위 비트부터 차례로 배치 (LSB -> MSB)
	CMD_TOKEN_FLAG _cmdTypeFlag : 3; //명령어 타입 플래그
	CMD_TOKEN_FLAG _cmdSubArgsFlag : 3; //헤당 명령어에 대한 하위 인자 플래그
};

class CMD_TOKEN //명령어 토큰
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

	struct CMD_TOKEN_FLAGS _cmdTokenFlags; //명령어 토큰 플래그
	enum CMD_TYPE _cmdType; //명령어 타입
	TCHAR _cmdSubArgs[MAX_STR_LEN]; //해당 명령어에 대한 하위 인자
};
#endif