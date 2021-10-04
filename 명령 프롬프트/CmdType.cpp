#include "Core.h"

/// <summary>
/// 명령어 타입의 문자열 반환
/// </summary>
/// <param name="index">명령어 타입의 인덱스</param>
/// <returns>명령어 타입 문자열</returns>
inline const TCHAR* CMD_TYPE_PARSER::GetStringFromCmdType(int index)
{
	if (index >= (int)CMD_TYPE::NUM_OF_CMD_TYPE)
		return NULL;

	return cmdTypeString[index];
}

/// <summary>
/// 명령어 타입 반환
/// </summary>
/// <param name="srcCmd">입력받은 명령어</param>
/// <returns>명령어 타입</returns>
CMD_TYPE CMD_TYPE_PARSER::GetCmdTypeFromString(const TCHAR* srcCmd)
{
	for (int i = 0; i < (int)CMD_TYPE::NUM_OF_CMD_TYPE; i++) //명령어 타입 순차 탐색
	{
		if (_tcscmp(srcCmd, GetStringFromCmdType(i)) == 0)
			return (CMD_TYPE)i;
	}

	return CMD_TYPE::NONE_CMD_TYPE; //명령어 타입이 아닐 경우
}