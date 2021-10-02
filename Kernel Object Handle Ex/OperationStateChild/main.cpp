#include <stdio.h>
#include <tchar.h>
#include <windows.h>

/// <summary>
/// 작업 상태 반환 자식 프로그램
/// </summary>
/// <param name="argc">실행 시 인자 개수</param>
/// <param name="argv">실행 시 인자</param>
/// <returns>작업 상태</returns>
int _tmain(int argc, TCHAR* argv[])
{
	float num1, num2;
	_tscanf_s(_T("%f %f"), &num1, &num2);

	if (num2 == 0)
	{
		_fputts(_T("Arithmetic Exception : Division by 0\n"), stdout);
		return EXIT_FAILURE;
	}

	_tprintf(_T("%f / %f = %f\n"), num1, num2, num1 / num2);
	system("pause");

	return EXIT_SUCCESS; //자식 프로세스가 종료 됨에 따라 Kernel Object의 Usage Count 1 감소
}