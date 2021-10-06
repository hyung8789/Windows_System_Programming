#include "Core.h"

/// <summary>
/// 명령어 타입의 문자열 반환
/// </summary>
/// <param name="srcCmdType">명령어 타입</param>
/// <returns>명령어 타입 문자열</returns>
inline const TCHAR* CmdTypeParser::GetStringFromCmdType(CMD_TYPE srcCmdType)
{
	if (srcCmdType < CMD_TYPE::START || srcCmdType >= CMD_TYPE::NUM_OF_CMD_TYPE)
		return NULL;

	return cmdTypeString[(const int)srcCmdType]; //명령어 타입에 해당하는 문자열 반환
}

/// <summary>
/// 명령어 타입 반환
/// </summary>
/// <param name="srcCmd">입력받은 명령어</param>
/// <returns>명령어 타입</returns>
CMD_TYPE CmdTypeParser::GetCmdTypeFromString(const TCHAR* srcCmd)
{
	if (srcCmd == NULL)
		exceptionhandler::ThrowException(exceptionhandler::EX::NULL_INPUT_CMD);

	for (int i = (int)CMD_TYPE::START; i < (int)CMD_TYPE::NUM_OF_CMD_TYPE; i++) //명령어 타입 순차 탐색
	{
		if (_tcscmp(srcCmd, GetStringFromCmdType((CMD_TYPE)i)) == 0)
			return (CMD_TYPE)i;
	}

	return CMD_TYPE::NONE_CMD_TYPE; //명령어가 아닌 경우
}