#include <stdio.h>
#include <tchar.h>
#include <windows.h>

/// <summary>
/// ���� ���ڸ� ���� �����ϴ� ���α׷�
/// </summary>
/// <param name="argc">���� �� ���� ����</param>
/// <param name="argv">���� �� ����</param>
/// <returns>�۾� ����</returns>
int _tmain(int argc, TCHAR* argv[])
{
	DWORD val1, val2;

	//������ ��ȯ
	val1 = _ttoi(argv[1]);
	val2 = _ttoi(argv[2]);

	_tprintf(_T("%d + %d = %d\n"), val1, val2, val1 + val2);

	_gettchar();

	return EXIT_SUCCESS;
}