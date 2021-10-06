#include "Core.h"

/// <summary>
/// 문자열 내의 모든 대문자를 소문자로 변경
/// </summary>
/// <param name="srcStr">원본 문자열 (editable)</param>
/// <returns>변경 된 문자열</returns>
TCHAR* utils::StrLower(TCHAR* srcStr)
{
	if (srcStr == NULL)
		return NULL;

	TCHAR* result = srcStr; //원본 문자열 시작 주소

	while (*srcStr)
	{
		if (_istupper(*srcStr))
			*srcStr = _totlower(*srcStr);

		srcStr++;
	}

	return result;
}

/// <summary>
/// 자기 자신의 프로세스 이름 (확장자 포함) 반환
/// </summary>
/// <returns>자기 자신의 프로세스 이름 (확장자 포함)</returns>
const TCHAR* utils::GetSelfProcessNameWithExt()
{
	static TCHAR selfProcessName[FILENAME_MAX] = { NULL, };
	static BOOL isSelfProcessNameAssigned = false; //프로세스 이름 할당 여부

	if (!isSelfProcessNameAssigned)
	{
		const TCHAR seps[] = _T("\\"); //구분자
		TCHAR* token = NULL;
		TCHAR* context = NULL; //분리 된 문자열에 대한 두 번째 문자열의 시작 주소

		TCHAR fullPathBuffer[MAX_PATH] = { NULL, }; //전체 경로 버퍼

		// https://docs.microsoft.com/ko-kr/windows/win32/api/psapi/nf-psapi-getprocessimagefilenamea?redirectedfrom=MSDN
		GetProcessImageFileNameW(GetCurrentProcess(), fullPathBuffer, MAX_PATH); //전체 경로를 포함한 이름 할당

		token = _tcstok_s(fullPathBuffer, seps, &context); //구분자로 분리

		while (token != NULL)
		{
			token = _tcstok_s(NULL, seps, &context);

			if ((*context) == NULL) //더 이상 분리 할 문자가 없으면
				break;
		}

		_tcscpy_s(selfProcessName, token);
		isSelfProcessNameAssigned = true;
	}

	return selfProcessName;
}