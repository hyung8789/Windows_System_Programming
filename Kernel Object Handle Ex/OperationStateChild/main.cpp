#include <stdio.h>
#include <tchar.h>
#include <windows.h>

/// <summary>
/// �۾� ���� ��ȯ �ڽ� ���α׷�
/// </summary>
/// <param name="argc">���� �� ���� ����</param>
/// <param name="argv">���� �� ����</param>
/// <returns>�۾� ����</returns>
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

	return EXIT_SUCCESS; //�ڽ� ���μ����� ���� �ʿ� ���� Kernel Object�� Usage Count 1 ����
}