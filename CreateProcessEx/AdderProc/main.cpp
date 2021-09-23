#include <stdio.h>
#include <tchar.h>
#include <windows.h>

/// <summary>
/// 전달 인자를 통해 덧셈하는 프로그램
/// </summary>
/// <param name="argc">실행 시 인자 개수</param>
/// <param name="argv">실행 시 인자</param>
/// <returns>작업 상태</returns>
int _tmain(int argc, TCHAR* argv[])
{
	DWORD val1, val2;

	//정수로 변환
	val1 = _ttoi(argv[1]);
	val2 = _ttoi(argv[2]);

	_tprintf(_T("%d + %d = %d\n"), val1, val2, val1 + val2);

	_gettchar();

	return EXIT_SUCCESS;
}