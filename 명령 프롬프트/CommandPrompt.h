#ifndef _COMMANDPROMPT_H_
#define _COMMANDPROMPT_H_

#include <tchar.h>
#include <locale.h>
#include <windows.h>

#define MAX_STR_LEN 256 //�ִ� ���ڿ� ����
#define MAX_CMD_TOKEN_COUNT 10 //�ִ� ��ū ����

//main.cpp
extern TCHAR cmdTokenList[MAX_CMD_TOKEN_COUNT][MAX_STR_LEN];

//CommandPrompt.cpp
DWORD CmdArgvProcessing(int argc, TCHAR** argv);
DWORD CmdReadTokenize();
DWORD CmdProcessing();
TCHAR* StrLower(TCHAR* srcStr);
void ClearTokenList();
#endif