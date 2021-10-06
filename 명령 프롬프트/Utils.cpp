#include "Core.h"

/// <summary>
/// ���ڿ� ���� ��� �빮�ڸ� �ҹ��ڷ� ����
/// </summary>
/// <param name="srcStr">���� ���ڿ� (editable)</param>
/// <returns>���� �� ���ڿ�</returns>
TCHAR* utils::StrLower(TCHAR* srcStr)
{
	if (srcStr == NULL)
		return NULL;

	TCHAR* result = srcStr; //���� ���ڿ� ���� �ּ�

	while (*srcStr)
	{
		if (_istupper(*srcStr))
			*srcStr = _totlower(*srcStr);

		srcStr++;
	}

	return result;
}

/// <summary>
/// �ڱ� �ڽ��� ���μ��� �̸� (Ȯ���� ����) ��ȯ
/// </summary>
/// <returns>�ڱ� �ڽ��� ���μ��� �̸� (Ȯ���� ����)</returns>
const TCHAR* utils::GetSelfProcessNameWithExt()
{
	static TCHAR selfProcessName[FILENAME_MAX] = { NULL, };
	static BOOL isSelfProcessNameAssigned = false; //���μ��� �̸� �Ҵ� ����

	if (!isSelfProcessNameAssigned)
	{
		const TCHAR seps[] = _T("\\"); //������
		TCHAR* token = NULL;
		TCHAR* context = NULL; //�и� �� ���ڿ��� ���� �� ��° ���ڿ��� ���� �ּ�

		TCHAR fullPathBuffer[MAX_PATH] = { NULL, }; //��ü ��� ����

		// https://docs.microsoft.com/ko-kr/windows/win32/api/psapi/nf-psapi-getprocessimagefilenamea?redirectedfrom=MSDN
		GetProcessImageFileNameW(GetCurrentProcess(), fullPathBuffer, MAX_PATH); //��ü ��θ� ������ �̸� �Ҵ�

		token = _tcstok_s(fullPathBuffer, seps, &context); //�����ڷ� �и�

		while (token != NULL)
		{
			token = _tcstok_s(NULL, seps, &context);

			if ((*context) == NULL) //�� �̻� �и� �� ���ڰ� ������
				break;
		}

		_tcscpy_s(selfProcessName, token);
		isSelfProcessNameAssigned = true;
	}

	return selfProcessName;
}