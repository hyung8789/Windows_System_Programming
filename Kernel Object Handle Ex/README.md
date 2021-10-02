# Kernel Object HANDLE Ex
---
## < ���μ��� �켱���� ���� >
<b>- ���μ���, ������, ���� ���� ���ҽ����� �����ϱ� ���� Kernel Object</b>

	- Kernel Object : Ŀ�ο��� �����ϴ� �߿��� ������ ��Ƶ� ������ ���
	- Kernel Object�� ���������� ������ �Ұ��� (������ �ü������ ����)
	- Kernel Object�� ������ ���� �ٸ� ����ü ���·� ����
	- Kernel Object ������ ���Ͽ� �ü���ּ� HANDLE�� ���Ͽ� ���������� ������ �����ϵ��� API ����

	ex)
		������ Kernel Object : �Ӽ�(Read, Write, Read&Write) ���� ���� ����
		���μ��� Kernel Object : ���μ��� �����ٸ��� ���� �켱���� ���� ��

	---

	- HANDLE : winnt.h�� void* �� ���� �� Kernel Object�� ���� �� ���� �����찡 �Ҵ��ϴ� �Ϸ��� ���� ���ڷμ�, HANDLE�� ���� �ش� Kernel Object�� ����
	- HANDLE (HANDLE ���̺�)�� �ü���� ���������� �ʰ� ���μ����� ������

	HANDLE			Kernel Object 			Resource
	Pipe HANDLE	<->	Pipe Kernel Obj		<->	Pipe
	Process HANDLE	<->	Process Kernel Obj	<->	Process
	Thread HANDLE	<->	Thread Kernel Obj	<->	Thread
	etc..

<p align="center"> <img src="./res/PriortyTest_result.PNG"></p>
<p align="center"><b><u>Fig 1) ���μ��� �����ٸ� �׽�Ʈ ���</u></b></p>

	1) 'PriortyTest1' �� 'PriorityTest2' �� ���� �ھ� ���� ȯ�濡���� �۵��ϵ��� ����
	(���� �ھ�� �۵� ��ų ��� ���� ó���� ���� �켱���� �׽�Ʈ�� ����� �Ұ���)
	2) 'PriorityTest1' �� 'PriorityTest2'�� ����
	3) 'PriorityTest2' �� �ڽ��� ���� ���μ��� �켱������ ����
	4) 'PriorityTest1' �� 'PriorityTest2' �� ���� ȭ�鿡 ����ϱ� ���� �۾��� ����
	5) �� Fig 1) ���μ��� �����ٸ� �׽�Ʈ ����� ����, ���μ��� �����ٸ��� ���� 'Priority1' �� 'Priority2' ���� �켱������ �����Ƿ�, ���� �Ҵ� ���� ����

---
## < Kernel Object�� HANDLE�� ���� ���� >
<b>- Kernel Object�� Windows �ü���� ������</b>

	- Kernel Object�� �Ҹ� ������ �ü���� ���� ����
	- Kernel Object�� ���μ����� ���ӵǾ� ���� �����Ƿ�, ���� ���μ����� ���� ���� ����
	(��, API ȣ���� ���� ���� ����)
	
<b>- HANDLE�� �ü���� ���������� �ʰ�, ���μ����� ������</b>

	(PROCESS_INFORMATION ����ü)
	https://docs.microsoft.com/en-us/windows/win32/api/processthreadsapi/ns-processthreadsapi-process_information

	- ���μ��� �ڵ� (hProcess) : ���μ����� Kernel Object�� ����Ű�� ���� ��
	- ���μ��� ID (dwProcessId) : ���μ��� �� ������ ���� ID
	- ������ �ڵ� �� ID (hThread, dwThreadId) : ���μ��� ���������� �淮 ���μ���(������)�� ���� �ڵ� �� ID 

<p align="center"> <img src="./res/KernelObjShare_result.PNG"></p>
<p align="center"><b><u>Fig 2) Handle�� ���� Kernel Object ���� �� �׽�Ʈ ��� 1</u></b></p>

	1) 'KernelObjShare' �� 'PriorityTest2' �� ���� (���� �ھ� ���� ȯ��)
	2) 'PriorityTest2' �� �ڽ��� ���� ���μ��� �켱������ ���� (���� �� ��)
	3) 'KernelObjShareEx' �� Busy Waiting �� 'PriorityTest2' �� �켱������ ���� �켱������ ����
	4) �� Fig 2) Handle�� ���� Kernel Object ���� �� �׽�Ʈ ��� 1�� ����, ���μ��� �����ٸ��� ���� ������ �켱������ �����Ƿ�, ������ ���� �۾��� ������

<p align="center"> <img src="./res/CloseHandleTest_result.PNG"></p>
<p align="center"><b><u>Fig 3) Handle�� ���� Kernel Object ���� �� �׽�Ʈ ��� 2</u></b></p>

    1) 'CloseHandleTest1' �� 'CloseHandleTest2' �� ����
    2) 'CloseHandleTest1' �� 'CloseHandleTest2' ���μ����� ����Ǳ� �� 'CloseHandleTest2' �ڵ� ��ȯ
    3) �� Fig 3) Handle�� ���� Kernel Object ���� �� �׽�Ʈ ��� 2�� ����, �ڵ��� �ü���� ��ȯ�Ͽ����� 'CloseHandleTest2' ���μ����� �ڽ��� �۾��� ��� ��ġ�� �Ҹ���
    4) ��, �ڵ��� ��ȯ�Ѵٰ� �ؼ� Kernel Object�� �Ҹ���� �ʾ����� �ǹ���

---
## < Kernel Object�� Usage Count >
<b>- Windows �ü���� Kernel Object �Ҹ� �ñ� ����</b>

    - �ռ� Kernel Object�� �Ҹ� ������ �ü���� ���� �����ȴٰ� �Ͽ��� ��, ���μ����� ���� �� �ش� ���μ����� ���� �� Kernel Object�� ���ÿ� �Ҹ�Ǵ°�?
    - �ڽ� ���μ����� ����� �� Kernel Object�� ���ÿ� �Ҹ�� �� �θ� ���μ����� �ڽ� ���μ����� ���� �ڵ带 ���� �� ����.
    - Windows�� Kernel Object �Ҹ�ñ⸦ ���� �� �ش� Kernel Object�� �����ϴ� ��� �� �ϳ��� ���� �� �Ҹ��Ų��.
	
	---
	
    - Usage Count : Kernel Object �Ҹ�ñ⸦ ���� ���� ���� ���� Ƚ��
    - Kernel Object�� ���� ������ HANDLE ������ �����Կ� ���� Usage Count�� ����
    - �� �̻� Kernel Object�� �����ϴ� ���μ����� ���� ���� ���� ��(Usage Count = 0) �ش� Kernel Object �Ҹ�

<p align="center"> <img src="./res/OperationState_result1.PNG"></p>
<p align="center"> <img src="./res/OperationState_result2.PNG"></p>
<p align="center"><b><u>Fig 4) Handle�� ���� Kernel Object ���� �� �׽�Ʈ ��� 3</u></b></p>

	1) �θ� ���μ����� 'OperationStateParent' �� �ڽ� ���μ����� 'OperationStateChild' �� ����
	(CreateProcess ������ �θ� ���μ����� �ڽ� ���μ��� Kernel Object ������ ���� HANDLE�� ������, �ڽ� ���μ����� �ڱ� �ڽ��� Kernel Object�� �����ϹǷ� �ڽ� ���μ��� ���� ������ �ڽ� ���μ����� Usage Count : 2)
	2) 'OperationStateChild' �� ����ڷκ��� �Է��� �޾� ���� ���� �� ȭ�鿡 ��� �� �۾����� ��ȯ
	3) 'OperationStateParent' �� 'OperationStateChild' �� ���� �� ���� ��� �� �۾� ���� ���
	(�ڽ� ���μ����� 'OperationStateChild' �� ���� �Ǿ�����, �θ� ���μ����� 'OperationStateParent'�� Handle�� ���� �ڽ� ���μ����� ���� Ŀ�� ������Ʈ�� ���� �������̹Ƿ�, Usage Count = 1 �� ��, Handle ��ȯ �� Usage Count = 0)
	
---
