#include "Core.h"

/// <summary>
/// ����ڿ��� �޴��� ����Ѵ�.
/// </summary>
void DispMenu()
{
	system("cls");
	_fputts(_T("0 : Divide\n"), stdout);
	_fputts(_T("1 : Multiple\n"), stdout);
	_fputts(_T("2 : Add\n"), stdout);
	_fputts(_T("3 : Minus\n"), stdout);
	_fputts(_T("4 : Other Operations\n"), stdout);
	_fputts(_T("5 : Exit\n"), stdout);
}

/// <summary>
/// ����ڿ��� �޴��� �Է¹޾� �ش��ϴ� �۾��� �����Ѵ�.
/// </summary>
/// <returns>
/// OP::EXIT : ���α׷� ���Ḧ ���� ��ȯ ��
/// OP::NOP : ���� �۾� ������ ���� ��ȯ ��
/// </returns>
DWORD InputMenu()
{
	STARTUPINFO sInfo = { 0, };
	PROCESS_INFORMATION pInfo;
	sInfo.cb = sizeof(sInfo);

	TCHAR command[] = _T("calc.exe");
	TCHAR sys32Path[DIR_LENGTH] = { NULL, }; //sys32 ���

	GetSystemDirectory(sys32Path, DIR_LENGTH);
	SetCurrentDirectory(sys32Path); //���� ������ ���� sys32 ��η� ���� ��� ����

USER_INPUT_LOOP:
	DWORD input = 0;
	double num1 = 0, num2 = 0;

	_fputts(_T(">>"), stdout);
	_tscanf(_T("%d"), &input);

	if (input >= OP::NUM_OF_OP)
	{
		_fputts(_T("out of range\n"), stdout);
		goto USER_INPUT_LOOP;
	}

	switch (input)
	{
	case OP::ELSE:
		// https://docs.microsoft.com/en-us/previous-versions/windows/desktop/legacy/aa366920(v=vs.85)
		ZeroMemory(
			&pInfo, 
			sizeof(pInfo)); //���μ��� ���� �ʱ�ȭ

		CreateProcess(
			NULL,
			command,
			NULL,
			NULL,
			TRUE,
			0, //������ ���� ���� ���α׷��� ����
			NULL,
			NULL,
			&sInfo,
			&pInfo
		);

		break;

	case OP::EXIT:
		return OP::EXIT;

	default:
		_fputts(_T("input num1 num2 >>"), stdout);
		_tscanf(_T("%lf %lf"), &num1, &num2);
		break;
	}

	switch (input)
	{
	case OP::DIVIDE:
		Divide(num1, num2);
		break;

	case OP::MULTIPLE:
		Multiple(num1, num2);
		break;

	case OP::ADD:
		Add(num1, num2);
		break;

	case OP::MINUS:
		Minus(num1, num2);
		break;
	}

	system("pause");
	return OP::NOP;
}

/// <summary>
/// ������ ���� ���� �� ��� �� ���
/// </summary>
/// <param name="a">���� ���� ���� �� 1</param>
/// <param name="b">���� ���� ���� �� 2</param>
void Divide(double a, double b)
{
	_tprintf(_T("%f / %f = %f\n"), a, b, a / b);
}

/// <summary>
/// ���ϱ� ���� ���� �� ��� �� ���
/// </summary>
/// <param name="a">���� ���� ���� �� 1</param>
/// <param name="b">���� ���� ���� �� 2</param>
void Multiple(double a, double b)
{
	_tprintf(_T("%f * %f = %f\n"), a, b, a * b);
}

/// <summary>
/// ���ϱ� ���� ���� �� ��� �� ���
/// </summary>
/// <param name="a">���� ���� ���� �� 1</param>
/// <param name="b">���� ���� ���� �� 2</param>
void Add(double a, double b)
{
	_tprintf(_T("%f + %f = %f\n"), a, b, a + b);
}

/// <summary>
/// ���� ���� ���� �� ��� �� ���
/// </summary>
/// <param name="a">���� ���� ���� �� 1</param>
/// <param name="b">���� ���� ���� �� 2</param>
void Minus(double a, double b)
{
	_tprintf(_T("%f - %f = %f\n"), a, b, a - b);
}
