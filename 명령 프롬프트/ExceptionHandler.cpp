#include "Core.h"

void ThrowException(EXCEPTION ex, const TCHAR* exMsg)
{
	if (exMsg != NULL)
		_tprintf_s(_T("%s\n"), exMsg);

	exit((const int)ex);
}