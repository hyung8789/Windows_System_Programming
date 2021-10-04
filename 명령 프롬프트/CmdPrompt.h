#ifndef _CMDPROMPT_H_
#define _CMDPROMPT_H_

// CmdPrompt.cpp

class CMD_PROMPT
{
public:
	CMD_PROMPT();
	~CMD_PROMPT();

	void Run();
	
private:
	void CmdArgvProc(int argc, TCHAR** argv);
	void CmdEventProc(class CMD_TOKEN cmdToken);

	void ClearTokenList();

	TCHAR _cmdTokenList[MAX_CMD_TOKEN_COUNT][MAX_STR_LEN]; //�и� �� ��ū ���
	int _lastCmdTokenIndex; //���������� �и� �� ��ū �ε���
};
#endif