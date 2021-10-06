#ifndef _CMDTYPE_H_
#define _CMDTYPE_H_

// CmdType.cpp

enum class CMD_TYPE : const int //명령어 타입
{
	START = 0, //프로세스 시작
	ECHO, //문자열 출력
	EXIT, //프로그램 종료
	NUM_OF_CMD_TYPE, //전체 명령어의 수
	NONE_CMD_TYPE, //명령어가 아닌 경우
	OUT_OF_RANGE //명령어 범위 초과
};

static const TCHAR* cmdTypeString[] = //명령어 타입 문자열 (명령어 타입과 1:1 대응)
{
	_T("start"),
	_T("echo"),
	_T("exit")
};

class CmdTypeParser //명령어 타입 파서
{
public:
	static inline const TCHAR* GetStringFromCmdType(CMD_TYPE srcCmdType);
	static CMD_TYPE GetCmdTypeFromString(const TCHAR* srcCmd);
};
#endif