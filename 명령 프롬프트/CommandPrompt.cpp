#include "Core.h"

/// <summary>
/// 
/// </summary>
/// <param name="argc"></param>
/// <param name="argv"></param>
/// <returns></returns>
DWORD CmdArgvProc(int argc, TCHAR** argv)
{


	return 0;
}

/// <summary>
/// ��ɾ� �Է¹޾� ��ū �и� �۾� ���� �� ���������� �и� �� ��ū �ε��� ��ȯ
/// </summary>
/// <returns>���������� �и� �� ��ū �ε���</returns>
void CmdReadTokenizeProc()
{
	static const TCHAR seps[] = _T(" ,\t\n"); //������
	
	TCHAR inputCmdString[MAX_STR_LEN] = { NULL, }; //�Է¹��� ��ɾ�
	TCHAR* token = NULL;
	TCHAR* context = NULL; //�и� �� ���ڿ��� ���� �� ��° ���ڿ��� ���� �ּ�

	_fputts(_T("Enter Command >>"), stdout);
	_getts_s(inputCmdString, MAX_STR_LEN - 1);
	token = _tcstok_s(inputCmdString, seps, &context); //�����ڷ� �и�

	while (token != NULL)
	{
		_tcscpy_s(cmdTokenList[cmdTokenIndex++], StrLower(token));
		token = _tcstok_s(NULL, seps, &context);
	}
}

/// <summary>
/// �ش� ��ɾ ������ ����� ����
/// exit ��ɿ� ���� COMPLETE ��ȯ �� ���α׷� ����
/// </summary>
/// <returns>exit ��ɿ� ���� COMPLETE ��ȯ, �� �� SUCCESS ��ȯ</returns>
DWORD CmdProc()
{
	static const TCHAR ERROR_MSG[] = _T("'%s'��(��) ������ �� �ִ� ���α׷��� �ƴմϴ�.\n");
	TCHAR cmdStringWithOptions[MAX_STR_LEN] = { NULL, };
	TCHAR subArgs[MAX_STR_LEN] = { NULL, };

	STARTUPINFO sInfo = { 0, };
	PROCESS_INFORMATION pInfo;
	BOOL processCreationState = false;

	sInfo.cb = sizeof(sInfo);
	

	if (_tcscmp(cmdTokenList[0], _T("exit")) == 0) //����
	{
		return COMPLETE;
	}
	else if (_tcscmp(cmdTokenList[0], _T("start")) == 0)
	{
		if (cmdTokenIndex > 1)
		{
			for (int i = 1; i < cmdTokenIndex; i++)
			{
				_stprintf_s(subArgs, _T("%s %s"), subArgs, cmdTokenList[i]);

			}

			_stprintf_s(cmdStringWithOptions, _T("%s %s"), selfProcessName, subArgs);
		}
		else //start�� �Է�
		{
			_stprintf_s(cmdStringWithOptions, _T("%s"), selfProcessName);
		}

		processCreationState =
			CreateProcess(
				NULL, cmdStringWithOptions, NULL, NULL,
				TRUE, 0, NULL, NULL,
				&sInfo, &pInfo
			); //�ش� ��ɾ� ����

		CloseHandle(pInfo.hProcess);
		CloseHandle(pInfo.hThread);
	}
	else if (_tcscmp(cmdTokenList[0], _T("echo")) == 0)
	{

	}
	else //���μ��� ����
	{
		// https://docs.microsoft.com/en-us/windows/win32/api/processthreadsapi/ns-processthreadsapi-startupinfow
		// https://docs.microsoft.com/en-us/windows/win32/procthread/process-creation-flags
	

		processCreationState =
			CreateProcess(
				NULL, cmdTokenList[0], NULL, NULL, 
				TRUE, 0, NULL, NULL,
				&sInfo, &pInfo
			); //�ش� ��ɾ� ����

		CloseHandle(pInfo.hProcess);
		CloseHandle(pInfo.hThread);

		if(processCreationState == FALSE) //���μ��� ���� ���� ��
			_tprintf(ERROR_MSG, cmdTokenList[0]);
	}

	return SUCCESS;
}

/// <summary>
/// ���ڿ� ���� ��� �빮�ڸ� �ҹ��ڷ� ����
/// </summary>
/// <param name="srcStr">���� ���ڿ� (editable)</param>
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
/// ��ū ��� �� �ε��� �ʱ�ȭ
/// </summary>
void ClearToken()
{
	for (int i = 0; i < MAX_CMD_TOKEN_COUNT; i++)
		memset(cmdTokenList[i], NULL, sizeof(TCHAR) * MAX_STR_LEN);

	cmdTokenIndex = 0;
}