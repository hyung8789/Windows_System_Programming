#ifndef _CMDTYPE_
#define _CMDTYPE_

// CmdType.cpp

enum class CMD_TYPE : const int //명령어 타입
{
	START = 0,
	ECHO,
	EXIT,
	NUM_OF_CMD_TYPE, //전체 명령어의 수
	NONE_CMD_TYPE, //명령어가 아닌 경우
	OUT_OF_RANGE
};

static const TCHAR* cmdTypeString[] = //명령어 타입 문자열
{
	_T("start"),
	_T("echo"),
	_T("exit")
};

class CMD_TYPE_PARSER //명령어 타입 파서
{
public:
	static inline const TCHAR* GetStringFromCmdType(int index);
	static CMD_TYPE GetCmdTypeFromString(const TCHAR* srcCmd);
};
#endif