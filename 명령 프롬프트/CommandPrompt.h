#ifndef _COMMANDPROMPT_H_
#define _COMMANDPROMPT_H_

#include <tchar.h>
#include <locale.h>
#include <windows.h>

/***
	SBCS(Single Byte Character Set)
	: 아스키 코드 기반의 문자열로서 문자를 표현하는데 1바이트만을 사용

	MBCS(Multi Byte Character Set)
	: 아스키 코드에 정의 된 문자는 1바이트로 처리, 그 외 2바이트로 처리

	WBCS(Wide Byte Character Set)
	: 유니코드 기반 문자열로서 모든 문자를 2바이트로 처리
	---
	< WBCS에서의 문자열 처리 >
	wchar_t : unsigned short 크기로서 2바이트 할당 (NULL문자도 2바이트로 처리)
	wchar_t a[] = L"test"; 와 같이 사용
	LPSTR : CHAR *
	LPCSTR : CONST CHAR *
	LPWSTR : WCHAR *
	LPCWSTR : CONST WCHAR *
	---
	< MBCS와 WBCS(유니코드)를 동시에 지원하기 위한 자료형 및 매크로 >
	TCHAR : WCHAR (WBCS), CHAR (MBCS)
	LPTSTR : LPWSTR (WBCS), LPSTR (MBCS)
	LPCTSTR : LPCWSTR (WBCS), LPCSTR (MBCS)
***/

#define MAX_STR_LEN 256 //최대 문자열 길이
#define MAX_CMD_TOKEN_COUNT 10 //최대 토큰 개수

DWORD CmdProcessing();
TCHAR* StrLower(TCHAR* srcStr);
#endif