#ifndef _CORE_H_
#define _CORE_H_

#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <locale.h>
#include <windows.h>
#include <Psapi.h>

#define MAX_STR_LEN 256 //최대 문자열 길이
#define MAX_CMD_TOKEN_COUNT 10 //최대 토큰 개수

#include "CmdType.h"
#include "CmdPrompt.h"
#include "CmdToken.h"
#include "Utils.h"
#include "DebugModule.h"
#endif