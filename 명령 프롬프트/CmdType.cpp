#include "Core.h"

/// <summary>
/// ��ɾ� Ÿ���� ���ڿ� ��ȯ
/// </summary>
/// <param name="srcCmdType">��ɾ� Ÿ��</param>
/// <returns>��ɾ� Ÿ�� ���ڿ�</returns>
inline const TCHAR* CmdTypeParser::GetStringFromCmdType(CMD_TYPE srcCmdType)
{
	if (srcCmdType < CMD_TYPE::START || srcCmdType >= CMD_TYPE::NUM_OF_CMD_TYPE)
		return NULL;

	return cmdTypeString[(const int)srcCmdType]; //��ɾ� Ÿ�Կ� �ش��ϴ� ���ڿ� ��ȯ
}

/// <summary>
/// ��ɾ� Ÿ�� ��ȯ
/// </summary>
/// <param name="srcCmd">�Է¹��� ��ɾ�</param>
/// <returns>��ɾ� Ÿ��</returns>
CMD_TYPE CmdTypeParser::GetCmdTypeFromString(const TCHAR* srcCmd)
{
	if (srcCmd == NULL)
		exceptionhandler::ThrowException(exceptionhandler::EX::NULL_INPUT_CMD);

	for (int i = (int)CMD_TYPE::START; i < (int)CMD_TYPE::NUM_OF_CMD_TYPE; i++) //��ɾ� Ÿ�� ���� Ž��
	{
		if (_tcscmp(srcCmd, GetStringFromCmdType((CMD_TYPE)i)) == 0)
			return (CMD_TYPE)i;
	}

	return CMD_TYPE::NONE_CMD_TYPE; //��ɾ �ƴ� ���
}