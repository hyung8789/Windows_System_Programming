# Kernel Object HANDLE Ex
---
## < ���μ��� �켱���� ���� >
<b>���μ���, ������, ���� ���� ���ҽ����� �����ϱ� ���� Kernel Object�� ����</b>

	- Kernel Object : Ŀ�ο��� �����ϴ� �߿��� ������ ��Ƶ� ������ ���
	- Kernel Object�� ���������� ������ �Ұ��� (������ �ü������ ����)
	- Kernel Object�� ������ ���� �ٸ� ����ü ���·� ����
	- Kernel Object ������ ���Ͽ� �ü���ּ� HANDLE�� ���Ͽ� ���������� ������ �����ϵ��� API ����

	ex)
		������ Kernel Object : �Ӽ�(Read, Write, Read&Write) ���� ���� ����
		���μ��� Kernel Object : ���μ��� �����ٸ��� ���� �켱���� ���� ��

	---

	- HANDLE : winnt.h�� void* �� ���� �� Kernel Object�� ���� �� ���� �����찡 �Ҵ��ϴ� �Ϸ��� ���� ���ڷμ�, HANDLE�� ���� �ش� Kernel Object�� ����

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
<b>Kernel Object�� Windows �ü���� ������</b>

	- Kernel Object�� �Ҹ� ������ �ü���� ���� ����
	- Kernel Object�� ���μ����� ���ӵǾ� ���� �����Ƿ�, ���� ���μ����� ���� ���� ����
	(��, API ȣ���� ���� ���� ����)

<b>HANDLE�� �ü���� ���������� �ʰ�, ���μ����� ������</b>

https://docs.microsoft.com/en-us/windows/win32/api/processthreadsapi/ns-processthreadsapi-process_information

	(PROCESS_INFORMATION ����ü)
	- ���μ��� �ڵ� (hProcess) : ���μ����� Kernel Object�� ����Ű�� ���� ��
	- ���μ��� ID (dwProcessId) : ���μ��� �� ������ ���� ID
	- ������ �ڵ� �� ID (hThread, dwThreadId) : ���μ��� ���������� �淮 ���μ���(������)�� ���� �ڵ� �� ID 

<p align="center"> <img src="./res/KernelObjShare_result.PNG"></p>
<p align="center"><b><u>Fig 2) Handle�� ���� Kernel Object ���� �� �׽�Ʈ ���</u></b></p>

	1) 'KernelObjShare' �� 'PriorityTest2' �� ���� (���� �ھ� ���� ȯ��)
	2) 'PriorityTest2' �� �ڽ��� ���� ���μ��� �켱������ ���� (���� �� ��)
	3) 'KernelObjShareEx' �� Busy Waiting �� 'PriorityTest2' �� �켱������ ���� �켱������ ����
	4) �� Fig 2) Handle�� ���� Kernel Object ���� �� �׽�Ʈ ����� ����, ���μ��� �����ٸ��� ���� ������ �켱������ �����Ƿ�, ������ ���� �۾��� ������

---
