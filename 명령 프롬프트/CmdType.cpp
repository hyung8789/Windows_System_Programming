#include "Core.h"

/// <summary>
/// ��ɾ� Ÿ���� ���ڿ� ��ȯ
/// </summary>
/// <param name="index">��ɾ� Ÿ���� �ε���</param>
/// <returns>��ɾ� Ÿ�� ���ڿ�</returns>
inline const TCHAR* CMD_TYPE_PARSER::GetStringFromCmdType(int index)
{
	if (index >= (int)CMD_TYPE::NUM_OF_CMD_TYPE)
		return NULL;

	return cmdTypeString[index];
}

/// <summary>
/// ��ɾ� Ÿ�� ��ȯ
/// </summary>
/// <param name="srcCmd">�Է¹��� ��ɾ�</param>
/// <returns>��ɾ� Ÿ��</returns>
CMD_TYPE CMD_TYPE_PARSER::GetCmdTypeFromString(const TCHAR* srcCmd)
{
	for (int i = 0; i < (int)CMD_TYPE::NUM_OF_CMD_TYPE; i++) //��ɾ� Ÿ�� ���� Ž��
	{
		if (_tcscmp(srcCmd, GetStringFromCmdType(i)) == 0)
			return (CMD_TYPE)i;
	}

	return CMD_TYPE::NONE_CMD_TYPE; //��ɾ� Ÿ���� �ƴ� ���
}