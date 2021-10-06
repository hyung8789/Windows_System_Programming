#ifndef _CMDTYPE_H_
#define _CMDTYPE_H_

// CmdType.cpp

enum class CMD_TYPE : const int //��ɾ� Ÿ��
{
	START = 0, //���μ��� ����
	ECHO, //���ڿ� ���
	EXIT, //���α׷� ����
	NUM_OF_CMD_TYPE, //��ü ��ɾ��� ��
	NONE_CMD_TYPE, //��ɾ �ƴ� ���
	OUT_OF_RANGE //��ɾ� ���� �ʰ�
};

static const TCHAR* cmdTypeString[] = //��ɾ� Ÿ�� ���ڿ� (��ɾ� Ÿ�԰� 1:1 ����)
{
	_T("start"),
	_T("echo"),
	_T("exit")
};

class CmdTypeParser //��ɾ� Ÿ�� �ļ�
{
public:
	static inline const TCHAR* GetStringFromCmdType(CMD_TYPE srcCmdType);
	static CMD_TYPE GetCmdTypeFromString(const TCHAR* srcCmd);
};
#endif