#ifndef _CMDTOKEN_H_
#define _CMDTOKEN_H_

// CmdToken.cpp

enum class CMD_TOKEN_STATE : const BOOL //명령어 토큰 상태
{
	//3가지 상태에 대하여 2^2 = 4, 2비트 필요

	NOT_ASSIGNED = 0, //미 할당 상태
	UPDATED, //읽기 위한 최신 상태
	OUT_DATED //이미 읽어서 오래 된 상태 (다시 읽기 방지)
};

struct CMD_TOKEN_FLAGS //명령어 토큰 플래그
{
	//최하위 비트부터 차례로 배치 (LSB -> MSB)
	BOOL _cmdTypeFlag : 2; //명령어 타입 플래그
	BOOL _cmdSubArgsFlag : 2; //헤당 명령어에 대한 하위 인자 플래그
};

class CMD_TOKEN //명령어 토큰
{
public:
	CMD_TOKEN();
	~CMD_TOKEN();
	
	void GenerateToken(void* args);

	CMD_TYPE GetCmdTypeOnce();
	const TCHAR* GetCmdSubArgsOnce();

private:
	void ClearAll();

	CMD_TOKEN_FLAGS _cmdTokenFlags; //명령어 토큰 플래그
	CMD_TYPE _cmdType; //명령어 타입
	TCHAR _cmdSubArgs[MAX_STR_LEN]; //해당 명령어에 대한 하위 인자
};
#endif