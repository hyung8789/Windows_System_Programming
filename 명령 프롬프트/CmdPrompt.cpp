#include "Core.h"

CMD_PROMPT::CMD_PROMPT()
{
	this->ClearTokenList();
}

CMD_PROMPT::~CMD_PROMPT()
{
}

void CMD_PROMPT::Run()
{
	//TODO : ����� �Է� �� ��ū �и�, ��ɾ� ��ū ���� �� �̺�Ʈ ȣ��

	static const TCHAR seps[] = _T(" ,\t\n"); //������

	TCHAR inputCmdString[MAX_STR_LEN] = { NULL, }; //�Է¹��� ��ɾ�
	TCHAR* token = NULL;
	TCHAR* context = NULL; //�и� �� ���ڿ��� ���� �� ��° ���ڿ��� ���� �ּ�

	CMD_TOKEN cmdToken;

	_fputts(_T("Enter Command >>"), stdout);
	_getts_s(inputCmdString, MAX_STR_LEN - 1);
	token = _tcstok_s(inputCmdString, seps, &context); //�����ڷ� �и�

	/***
		< ����ڷκ����� ��ɾ� �Է� ���� >

		1) echo test
		: ȭ�鿡 test ���

		2) start echo test
		: ���ο� ��ɾ� ������Ʈ�� ���� �� �ش� ��� ������Ʈ���� ȭ�鿡 test ���

		3) start start echo test
		: ���ο� ��� ������Ʈ ����, �ش� ��� ������Ʈ���� �ٽ� ���ο� ��� ������Ʈ ����
		������ ��� ������Ʈ���� ȭ�鿡 test ���

		4) echo test start
		: ȭ�鿡 test ��� �� ���ο� ��� ������Ʈ ����
	 ***/

	while (token != NULL)
	{
		_tcscpy_s(this->_cmdTokenList[this->_lastCmdTokenIndex], StrLower(token));
		cmdToken.GenerateToken(this->_cmdTokenList[this->_lastCmdTokenIndex]);
	//start start �Է� �� ���� start�� �������ڷ� ó������ �ʰ� ���� ��ū ó���� �Ѱܾ� ��
		_lastCmdTokenIndex++;

		token = _tcstok_s(NULL, seps, &context);
	}
}

void CMD_PROMPT::CmdArgvProc(int argc, TCHAR** argv)
{
	//TODO : ���� ���� ó��
}

/// <summary>
/// ��ɾ� �̺�Ʈ ó��
/// </summary>
/// <param name="srcCmdToken">��ɾ� ��ū</param>
void CMD_PROMPT::CmdEventProc(CMD_TOKEN srcCmdToken)
{
	//TODO : ��ɾ� �̺�Ʈ ó��

	static const TCHAR ERROR_MSG[] = _T("'%s'��(��) ������ �� �ִ� ���α׷��� �ƴմϴ�.\n");
	TCHAR cmdStringWithOptions[MAX_STR_LEN] = { NULL, };
	TCHAR subArgs[MAX_STR_LEN] = { NULL, };

	STARTUPINFO sInfo = { 0, };
	PROCESS_INFORMATION pInfo;
	BOOL processCreationState = false;

	sInfo.cb = sizeof(sInfo);

	switch(srcCmdToken.GetCmdTypeOnce())
	{
	case CMD_TYPE::EXIT:
		_fputts(_T("��ɾ� ó���� �����մϴ�.\n"), stdout);
		exit(EXIT_SUCCESS);

	case CMD_TYPE::START:
		break;

	case CMD_TYPE::ECHO:
		break;

	default:
		break;
	}


	//if (_tcscmp(_cmdTokenList[0], _T("start")) == 0)
	//{
	//	if (cmdTokenIndex > 1)
	//	{
	//		for (int i = 1; i < cmdTokenIndex; i++)
	//		{
	//			_stprintf_s(subArgs, _T("%s %s"), subArgs, _cmdTokenList[i]);

	//		}

	//		//_stprintf_s(cmdStringWithOptions, _T("%s %s"), selfProcessName, subArgs);
	//	}
	//	else //start�� �Է�
	//	{
	//		//	_stprintf_s(cmdStringWithOptions, _T("%s"), selfProcessName);
	//	}

	//	processCreationState =
	//		CreateProcess(
	//			NULL, cmdStringWithOptions, NULL, NULL,
	//			TRUE, 0, NULL, NULL,
	//			&sInfo, &pInfo
	//		); //�ش� ��ɾ� ����

	//	CloseHandle(pInfo.hProcess);
	//	CloseHandle(pInfo.hThread);
	//}
	//else //���μ��� ����
	//{
	//	// https://docs.microsoft.com/en-us/windows/win32/api/processthreadsapi/ns-processthreadsapi-startupinfow
	//	// https://docs.microsoft.com/en-us/windows/win32/procthread/process-creation-flags


	//	processCreationState =
	//		CreateProcess(
	//			NULL, _cmdTokenList[0], NULL, NULL,
	//			TRUE, 0, NULL, NULL,
	//			&sInfo, &pInfo
	//		); //�ش� ��ɾ� ����

	//	CloseHandle(pInfo.hProcess);
	//	CloseHandle(pInfo.hThread);

	//	if (processCreationState == FALSE) //���μ��� ���� ���� ��
	//		_tprintf(ERROR_MSG, _cmdTokenList[0]);
	//}
}

/// <summary>
/// ��ū ��� �� �ε��� �ʱ�ȭ
/// </summary>
void CMD_PROMPT::ClearTokenList()
{
	for (int i = 0; i < MAX_CMD_TOKEN_COUNT; i++)
		memset(this->_cmdTokenList[i], NULL, sizeof(TCHAR) * MAX_STR_LEN);

	this->_lastCmdTokenIndex = 0;
}