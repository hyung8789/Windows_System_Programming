#include "Core.h"

void exceptionhandler::ThrowException(EXCEPTION ex)
{
#ifdef DEBUG_MODE
	_tprintf_s(_T("EXCEPTION : %d\n"), (const int)ex);
#else
	exit((const int)ex);
#endif
}