#ifndef _COMMANDPROMPT_H_
#define _COMMANDPROMPT_H_

//main.cpp
extern TCHAR cmdTokenList[MAX_CMD_TOKEN_COUNT][MAX_STR_LEN]; //�и� �� ��ū ���
extern int cmdTokenIndex; //���������� �и� �� ��ū �ε���

struct CMD_TOKEN
{

};

//CommandPrompt.cpp
DWORD CmdArgvProc(int argc, TCHAR** argv);
void CmdReadTokenizeProc();

DWORD CmdProc();
TCHAR* StrLower(TCHAR* srcStr);

void ClearToken();
#endif