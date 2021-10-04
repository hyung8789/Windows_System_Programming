#ifndef _CMDTYPE_
#define _CMDTYPE_

// CmdType.cpp

enum class CMD_TYPE : const int //��ɾ� Ÿ��
{
	START = 0,
	ECHO,
	EXIT,
	NUM_OF_CMD_TYPE, //��ü ��ɾ��� ��
	NONE_CMD_TYPE, //��ɾ �ƴ� ���
	OUT_OF_RANGE
};

static const TCHAR* cmdTypeString[] = //��ɾ� Ÿ�� ���ڿ�
{
	_T("start"),
	_T("echo"),
	_T("exit")
};

class CMD_TYPE_PARSER //��ɾ� Ÿ�� �ļ�
{
public:
	static inline const TCHAR* GetStringFromCmdType(int index);
	static CMD_TYPE GetCmdTypeFromString(const TCHAR* srcCmd);
};
#endif