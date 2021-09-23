#include <stdio.h>
#include <tchar.h>
#include <windows.h>

#define DIR_LENGTH MAX_PATH + 1

/// <summary>
/// 전달 인자를 통한 AdderProc 실행 프로그램
/// </summary>
/// <param name="argc">실행 시 인자 개수</param>
/// <param name="argv">실행 시 인자</param>
/// <returns>작업 상태</returns>
int _tmain(int argc, TCHAR* argv[])
{
	STARTUPINFO sInfo = { 0 };
	PROCESS_INFORMATION pInfo;

	// https://docs.microsoft.com/en-us/windows/win32/api/processthreadsapi/ns-processthreadsapi-startupinfow
	sInfo.cb = sizeof(sInfo);
	sInfo.dwFlags = STARTF_USEPOSITION | STARTF_USESIZE; //좌표와 길이 사용
	sInfo.dwX = 100; //프로세스 윈도우의 x 좌표
	sInfo.dwY = 200; //프로세스 윈도우의 y 좌표
	sInfo.dwXSize = 300; //가로 길이
	sInfo.dwYSize = 200; //세로 길이
	sInfo.lpTitle = (LPWSTR)_T("This is Title");

	TCHAR command[] = _T("AdderProc.exe 10 20");
	TCHAR currentDirPath[DIR_LENGTH]; //현재 디렉터리 경로
	BOOL processCreationState;

	GetCurrentDirectory(DIR_LENGTH, currentDirPath); //현재 디렉터리 확인
	_fputts(currentDirPath, stdout);
	_fputts(_T("\n"), stdout);

	SetCurrentDirectory(_T("C:\\test")); //현재 디렉토리 변경

	GetCurrentDirectory(DIR_LENGTH, currentDirPath); //현재 디렉터리 확인
	_fputts(currentDirPath, stdout);
	_fputts(_T("\n"), stdout);

	GetSystemDirectory(currentDirPath, DIR_LENGTH); //시스템 디렉토리 (sys32)
	_tprintf(_T("sysdir : %s\n"), currentDirPath);

	GetWindowsDirectory(currentDirPath, DIR_LENGTH); //윈도우 디렉토리 (windows)
	_tprintf(_T("windir : %s\n"), currentDirPath);

	/***
	* 표준 검색경로에 따라 먼저 현재 실행 중인 프로세스의 실행파일이 존재하는 디렉터리를 기준으로 실행파일을 찾고,
	* 존재하지 않을 경우 현재 실행 중인 프로세스의 현재 디렉터리(SetCurrentDirectory에 의해 설정 된 디렉터리)에서 찾음
	* 그 다음, sysdir -> windir -> 환경변수 PATH에 지정 된 디렉터리 순
	***/

	// https://docs.microsoft.com/en-us/windows/win32/procthread/process-creation-flags
	processCreationState = CreateProcess(
		NULL, //실행파일 이름
		command, //전달 될 명령어
		NULL,
		NULL,
		TRUE, //Handle 상속 여부
		CREATE_NEW_CONSOLE, //새 콘솔 창으로 생성
		NULL,
		NULL,
		&sInfo,
		&pInfo
	);
	
	if (processCreationState != 0)
		_fputts(_T("Success\n"), stdout);
	else
		_fputts(_T("Fail\n"), stdout);

	_gettchar();

	return EXIT_SUCCESS;
}