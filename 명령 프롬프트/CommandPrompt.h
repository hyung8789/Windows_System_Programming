#ifndef _COMMANDPROMPT_H_
#define _COMMANDPROMPT_H_

#include <tchar.h>
#include <locale.h>
#include <windows.h>

/***
	SBCS(Single Byte Character Set)
	: �ƽ�Ű �ڵ� ����� ���ڿ��μ� ���ڸ� ǥ���ϴµ� 1����Ʈ���� ���

	MBCS(Multi Byte Character Set)
	: �ƽ�Ű �ڵ忡 ���� �� ���ڴ� 1����Ʈ�� ó��, �� �� 2����Ʈ�� ó��

	WBCS(Wide Byte Character Set)
	: �����ڵ� ��� ���ڿ��μ� ��� ���ڸ� 2����Ʈ�� ó��
	---
	< WBCS������ ���ڿ� ó�� >
	wchar_t : unsigned short ũ��μ� 2����Ʈ �Ҵ� (NULL���ڵ� 2����Ʈ�� ó��)
	wchar_t a[] = L"test"; �� ���� ���
	LPSTR : CHAR *
	LPCSTR : CONST CHAR *
	LPWSTR : WCHAR *
	LPCWSTR : CONST WCHAR *
	---
	< MBCS�� WBCS(�����ڵ�)�� ���ÿ� �����ϱ� ���� �ڷ��� �� ��ũ�� >
	TCHAR : WCHAR (WBCS), CHAR (MBCS)
	LPTSTR : LPWSTR (WBCS), LPSTR (MBCS)
	LPCTSTR : LPCWSTR (WBCS), LPCSTR (MBCS)
***/

#define MAX_STR_LEN 256 //�ִ� ���ڿ� ����
#define MAX_CMD_TOKEN_COUNT 10 //�ִ� ��ū ����

DWORD CmdProcessing();
TCHAR* StrLower(TCHAR* srcStr);
#endif