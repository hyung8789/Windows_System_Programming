#ifndef _EXCEPTIONHANDLER_H_
#define _EXCEPTIONHANDLER_H_

typedef enum class EXCEPTION : const int
{
	ACCESSED_OUT_DATED_CMD_TOKEN = -1,
	TEST = 2
}EX;

void ThrowException(EXCEPTION ex, const TCHAR* exMsg);
#endif