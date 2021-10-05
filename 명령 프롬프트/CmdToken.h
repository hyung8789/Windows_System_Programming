#ifndef _CMDTOKEN_H_
#define _CMDTOKEN_H_

// CmdToken.cpp

enum class CMD_TOKEN_STATE : const BOOL //명령어 토큰 상태
{
	//명령어 토큰 상태 관리에 대한 4비트(2^2 = 4) 필요

	INIT = 0, //초기 상태
	INCOMPLETE, //불완전 상태 : 일부 할당 상태
	COMPLETE, //완전 상태 : 전부 할당 완료 상태
	USED //사용됨 상태 : 사용 된 토큰에 대한 상태
};
 
struct CMD_TOKEN_FLAGS //명령어 토큰 플래그
{
	//최하위 비트부터 차례로 배치 (LSB -> MSB)

	BOOL _cmdTokenState : 4; //명령어 토큰 상태 (MSB)
	BOOL _isCmdTypeUsed : 1; //명령어 타입 사용 여부
	BOOL _isCmdSubArgsUsed : 1; //명령어 하위 인자 사용 여부
	BOOL _isCmdTypeAssigned : 1;  //명령어 타입 할당 여부
	BOOL _isCmdSubArgsAssigned : 1; //해당 명령어에 대한 하위 인자 할당 여부 
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