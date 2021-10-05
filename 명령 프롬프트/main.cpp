#include "Core.h"

/// <summary>
/// ��� ������Ʈ ���α׷�
/// </summary>
/// <param name="argc">���� �� ���� ����</param>
/// <param name="argv">���� �� ����</param>
/// <returns>�۾� ����</returns>
int _tmain(int argc, TCHAR* argv[])
{
	// https://docs.microsoft.com/ko-kr/cpp/c-runtime-library/reference/setlocale-wsetlocale?view=msvc-160
	_tsetlocale(LC_ALL, _T("Korean"));
	
	_tprintf_s(_T("%s\n"), utils::GetSelfProcessNameWithExt());

#ifdef DEBUG_MODE
	RunDebugMode();
#endif

	return EXIT_SUCCESS;
}