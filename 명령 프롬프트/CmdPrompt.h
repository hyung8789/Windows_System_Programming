#ifndef _CMDPROMPT_H_
#define _CMDPROMPT_H_

// CmdPrompt.cpp

class CmdPrompt
{
public:
	CmdPrompt();
	~CmdPrompt();

	void Run();
	
private:
	void CmdArgvProc(int argc, TCHAR** argv);
	void CmdEventProc(class CmdToken cmdToken);

	void ClearTokenList();

	TCHAR _cmdTokenList[MAX_CMD_TOKEN_COUNT][MAX_STR_LEN]; //분리 된 토큰 목록
	int _lastCmdTokenIndex; //마지막으로 분리 된 토큰 인덱스
};
#endif