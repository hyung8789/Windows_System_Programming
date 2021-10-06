#ifndef _EXCEPTIONHANDLER_H_
#define _EXCEPTIONHANDLER_H_

namespace exceptionhandler
{
	typedef enum class EXCEPTION : const int
	{
		EXPIRED_TOKEN_ACCESS = -1,
		NULL_INPUT_CMD = -2
	}EX;

	void ThrowException(EXCEPTION ex);
}
#endif