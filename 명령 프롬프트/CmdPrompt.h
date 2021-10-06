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

	TCHAR _cmdTokenList[MAX_CMD_TOKEN_COUNT][MAX_STR_LEN]; //�и� �� ��ū ���
	int _lastCmdTokenIndex; //���������� �и� �� ��ū �ε���
};
#endif