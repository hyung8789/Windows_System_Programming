#ifndef _COMMANDPROMPT_H_
#define _COMMANDPROMPT_H_

//main.cpp
extern TCHAR cmdTokenList[MAX_CMD_TOKEN_COUNT][MAX_STR_LEN]; //분리 된 토큰 목록
extern int cmdTokenIndex; //마지막으로 분리 됟 토큰 인덱스

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