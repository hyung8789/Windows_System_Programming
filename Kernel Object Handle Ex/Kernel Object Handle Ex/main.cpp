#include <stdio.h>
#include <tchar.h>
#include <windows.h>


int _tmain(int argc, TCHAR* argv[])
{
	/***
		프로세스, 스레드, 파일 등의 리소스들을 관리하기 위해 커널 오브젝트가 존재
		- 커널 오브젝트는 직접적으로 접근이 불가능 (운영체제에서 관리)
		- 커널 오브젝트는 종류에 따라 다른 구조체 형태로 생성
		- 커널 오브젝트 조작을 위하여 운영체제애서 HANDLE을 통하여 간접적으로 접근이 가능하도록 API 제공

		ex) 파일의 커널 오브젝트 : 속성(Read, Write, Read&Write) 등의 정보 저장
			프로세스 커널 오브젝트 : 프로세스 스케줄링을 위한 우선순위 정보 등
		---
		Handle이란 무엇인가?
		: winnt.h에 따르면 void* 로 정의 된 커널 오브젝트가 생성 시 마다 할당되는 일련의 고유 숫자로서,
		Handle을 통해 해당 커널 오브젝트에 접근

		Handle	|	Kernel Object	|	Resource
		Pipe Handle<->Pipe Kernel Obj<->Pipe
		Process Handle<->Process Kernel Obj<->Process
		etc..
	***/
}
