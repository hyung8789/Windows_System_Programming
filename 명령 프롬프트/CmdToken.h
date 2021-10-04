#ifndef _CMDTOKEN_H_
#define _CMDTOKEN_H_

// CmdToken.cpp

class CMD_TOKEN //명령어 토큰
{
public:
	CMD_TOKEN();
	~CMD_TOKEN();

	void ClearAll();
	
	void GenerateToken(void* args);

	enum CMD_TYPE GetCmdType();
	const TCHAR* GetCmdSubArgs();

private:
	BOOL isCmdSubArgsAssigned;
	BOOL isCmdTypeAssigned;

	enum CMD_TYPE _cmdType; //명령어 타입
	TCHAR _cmdSubArgs[MAX_STR_LEN]; //해당 명령어에 대한 하위 인자
};
#endif