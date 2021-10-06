#include "Core.h"

void exceptionhandler::ThrowException(EXCEPTION ex)
{
	exit((const int)ex);
}