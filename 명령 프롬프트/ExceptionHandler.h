#ifndef _EXCEPTIONHANDLER_H_
#define _EXCEPTIONHANDLER_H_

namespace exceptionhandler
{
	typedef enum class EXCEPTION : const int
	{
		NOT_USED_TOKEN_EXIST = -1,
		WRONG_CMD_TYPE_FLAG = -2,
		NOT_ASSIGNED_TOKEN_ACCESS = -3,
		EXPIRED_TOKEN_ACCESS = -4,
		NULL_INPUT_CMD = -5
	}EX;

	void ThrowException(EXCEPTION ex);
}
#endif