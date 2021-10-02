#include "Core.h"

/// <summary>
/// 사용자에게 메뉴를 출력한다.
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
/// 사용자에게 메뉴를 입력받아 해당하는 작업을 수행한다.
/// </summary>
/// <returns>
/// OP::EXIT : 프로그램 종료를 위한 반환 값
/// OP::NOP : 다음 작업 수행을 위한 반환 값
/// </returns>
DWORD InputMenu()
{
	STARTUPINFO sInfo = { 0, };
	PROCESS_INFORMATION pInfo;
	sInfo.cb = sizeof(sInfo);

	TCHAR command[] = _T("calc.exe");
	TCHAR sys32Path[DIR_LENGTH] = { NULL, }; //sys32 경로

	GetSystemDirectory(sys32Path, DIR_LENGTH);
	SetCurrentDirectory(sys32Path); //계산기 실행을 위해 sys32 경로로 현재 경로 설정

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
			sizeof(pInfo)); //프로세스 정보 초기화

		/***
			계산기 프로세스 실행 시점에 해당 계산기의 Kernel Object의 Usage Count : 2
			그 뒤 핸들을 바로 반환하므로, Usage Count : 1
			계산기 종료 시 Usage Count : 0이 되므로, Kernel Object는 바로 소멸
		***/

		CreateProcess(
			NULL, command, NULL, NULL,
			TRUE, 0, NULL, NULL,
			&sInfo, &pInfo
		);

		CloseHandle(pInfo.hProcess);
		CloseHandle(pInfo.hThread);

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
/// 나누기 연산 수행 및 결과 값 출력
/// </summary>
/// <param name="a">연산 수행 위한 값 1</param>
/// <param name="b">연산 수행 위한 값 2</param>
void Divide(double a, double b)
{
	_tprintf(_T("%f / %f = %f\n"), a, b, a / b);
}

/// <summary>
/// 곱하기 연산 수행 및 결과 값 출력
/// </summary>
/// <param name="a">연산 수행 위한 값 1</param>
/// <param name="b">연산 수행 위한 값 2</param>
void Multiple(double a, double b)
{
	_tprintf(_T("%f * %f = %f\n"), a, b, a * b);
}

/// <summary>
/// 더하기 연산 수행 및 결과 값 출력
/// </summary>
/// <param name="a">연산 수행 위한 값 1</param>
/// <param name="b">연산 수행 위한 값 2</param>
void Add(double a, double b)
{
	_tprintf(_T("%f + %f = %f\n"), a, b, a + b);
}

/// <summary>
/// 빼기 연산 수행 및 결과 값 출력
/// </summary>
/// <param name="a">연산 수행 위한 값 1</param>
/// <param name="b">연산 수행 위한 값 2</param>
void Minus(double a, double b)
{
	_tprintf(_T("%f - %f = %f\n"), a, b, a - b);
}
