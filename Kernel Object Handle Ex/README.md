# Kernel Object Handle Ex
---
#### < 프로세스 우선순위 변경 >
프로세스, 스레드, 파일 등의 리소스들을 관리하기 위해 커널 오브젝트가 존재

	- 커널 오브젝트 : 커널에서 관리하는 중요한 정보를 담아둔 데이터 블록
	- 커널 오브젝트는 직접적으로 접근이 불가능 (윈도우 운영체제에서 관리)
	- 커널 오브젝트는 종류에 따라 다른 구조체 형태로 생성
	- 커널 오브젝트 조작을 위하여 운영체제애서 HANDLE을 통하여 간접적으로 접근이 가능하도록 API 제공

	ex) 파일의 커널 오브젝트 : 속성(Read, Write, Read&Write) 등의 정보 저장
		프로세스 커널 오브젝트 : 프로세스 스케줄링을 위한 우선순위 정보 등
	---
	(Handle이란 무엇인가?)
	: winnt.h에 void* 로 정의 된 커널 오브젝트가 생성 시 마다 윈도우가 할당하는 일련의 고유 숫자로서,
	Handle을 통해 해당 커널 오브젝트에 접근

	Handle			Kernel Object 			Resource
	Pipe Handle	<->	Pipe Kernel Obj		<->	Pipe
	Process Handle	<->	Process Kernel Obj	<->	Process
	Thread Handle	<->	Thread Kernel Obj	<->	Thread
	etc..

<p align="center"> <img src="./res/PriortyTest_result.PNG"></p>
<p align="center"><b><u>Fig 1) 프로세스 스케줄링 테스트 결과</u></b></p>

	1) 'PriortyTest1' 과 'PriorityTest2' 를 단일 코어 실행 환경에서만 작동하도록 설정
	(다중 코어로 작동 시킬 경우 병렬 처리에 의해 우선순위 테스트가 제대로 불가능)
	2) 'PriorityTest1' 는 'PriorityTest2'를 실행
	3) 'PriorityTest2' 는 자신을 높은 프로세스 우선순위로 변경
	4) 'PriorityTest1' 과 'PriorityTest2' 는 각각 화면에 출력하기 위한 작업을 수행
	5) 위 Fig 1) 프로세스 스케줄링 테스트 결과에 따라, 프로세스 스케줄링에 의해 'Priority1' 은 'Priority2' 보다 우선순위가 낮으므로, 거의 할당 받지 못함

---
#### < test2 >