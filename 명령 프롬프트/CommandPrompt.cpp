#include "Core.h"

/// <summary>
/// 
/// </summary>
/// <param name="argc"></param>
/// <param name="argv"></param>
/// <returns></returns>
DWORD CmdArgvProcessing(int argc, TCHAR** argv)
{
	return 0;
}

/// <summary>
/// ��ɾ� ��ūȭ �и� �۾� ���� �� �и� �� ��ū ���� ��ȯ
/// </summary>
/// <returns>�и� �� ��ū ����</returns>
DWORD CmdReadTokenize()
{
	static TCHAR seps[] = _T(" ,\t\n"); //������
	static TCHAR ERROR_MSG[] = _T("'%s'��(��) ������ �� �ִ� ���α׷��� �ƴմϴ�.\n");

	TCHAR inputCmdString[MAX_STR_LEN] = { NULL, }; //�Է¹��� ��ɾ�
	TCHAR* token = NULL;
	TCHAR* context = NULL; //�и� �� ���ڿ��� ���� �� ��° ���ڿ��� ���� �ּ�

	int cmdTokenIndex = 0;

	_fputts(_T("Enter Command >>"), stdout);
	_getts_s(inputCmdString, MAX_STR_LEN - 1);
	token = _tcstok_s(inputCmdString, seps, &context); //�����ڷ� �и�

	while (token != NULL)
	{
		_tcscpy_s(cmdTokenList[cmdTokenIndex++], StrLower(token));
		token = _tcstok_s(NULL, seps, &context);
	}

	return 0;
}

/// <summary>
/// ��ҹ��� ���� ���� ��ɾ �Է¹޾� �ش� ��ɾ ������ ����� ����
/// exit �Է� �� COMPLETE ��ȯ �� ���α׷� ����
/// </summary>
/// <returns>if exit entered return COMPLETE, else return SUCCESS</returns>
DWORD CmdProcessing()
{
	static TCHAR seps[] = _T(" ,\t\n"); //������
	static TCHAR ERROR_MSG[] = _T("'%s'��(��) ������ �� �ִ� ���α׷��� �ƴմϴ�.\n");

	TCHAR inputCmdString[MAX_STR_LEN] = { NULL, }; //�Է¹��� ��ɾ�
	TCHAR* token = NULL;
	TCHAR* context = NULL; //�и� �� ���ڿ��� ���� �� ��° ���ڿ��� ���� �ּ�

	int cmdTokenIndex = 0;

	_fputts(_T("Enter Command >>"), stdout);
	_getts_s(inputCmdString, MAX_STR_LEN - 1);
	token = _tcstok_s(inputCmdString, seps, &context); //�����ڷ� �и�

	while (token != NULL)
	{
		_tcscpy_s(cmdTokenList[cmdTokenIndex++], StrLower(token));
		token = _tcstok_s(NULL, seps, &context);
	}

	if (_tcscmp(cmdTokenList[0], _T("exit")) == 0) //����
	{
		return COMPLETE;
	}
	else if (1==0)
	{
		///dummy
	}
	else //���μ��� ����
	{
		// https://docs.microsoft.com/en-us/windows/win32/api/processthreadsapi/ns-processthreadsapi-startupinfow
		// https://docs.microsoft.com/en-us/windows/win32/procthread/process-creation-flags
		STARTUPINFO sInfo = { 0, };
		PROCESS_INFORMATION pInfo;
		sInfo.cb = sizeof(sInfo);

		BOOL processCreationState =
			CreateProcess(
				NULL, cmdTokenList[0], NULL, NULL, 
				TRUE, 0, NULL, NULL,
				&sInfo, &pInfo
			); //�ش� ��ɾ� ����

		if(processCreationState == FALSE) //���μ��� ���� ���� ��
			_tprintf(ERROR_MSG, cmdTokenList[0]);
	}

	return SUCCESS;
}

/// <summary>
/// ���ڿ� ���� ��� �빮�ڸ� �ҹ��ڷ� ����
/// </summary>
/// <param name="srcStr">���� ���ڿ�</param>
/// <returns>���� �� ���ڿ�</returns>
TCHAR* StrLower(TCHAR* srcStr)
{
	if (srcStr == NULL)
		return NULL;

	TCHAR* result = srcStr;

	while (*srcStr)
	{
		if (_istupper(*srcStr))
			*srcStr = _totlower(*srcStr);

		srcStr++;
	}

	return result;
}

/// <summary>
/// ��ū ��� �ʱ�ȭ
/// </summary>
void ClearTokenList()
{
	for (int i = 0; i < MAX_CMD_TOKEN_COUNT; i++)
		memset(cmdTokenList[i], NULL, sizeof(TCHAR) * MAX_STR_LEN);
}
