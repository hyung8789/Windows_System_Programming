#include <stdio.h>
#include <tchar.h>
#include <windows.h>


int _tmain(int argc, TCHAR* argv[])
{
	/***
		���μ���, ������, ���� ���� ���ҽ����� �����ϱ� ���� Ŀ�� ������Ʈ�� ����
		- Ŀ�� ������Ʈ�� ���������� ������ �Ұ��� (�ü������ ����)
		- Ŀ�� ������Ʈ�� ������ ���� �ٸ� ����ü ���·� ����
		- Ŀ�� ������Ʈ ������ ���Ͽ� �ü���ּ� HANDLE�� ���Ͽ� ���������� ������ �����ϵ��� API ����

		ex) ������ Ŀ�� ������Ʈ : �Ӽ�(Read, Write, Read&Write) ���� ���� ����
			���μ��� Ŀ�� ������Ʈ : ���μ��� �����ٸ��� ���� �켱���� ���� ��
		---
		Handle�̶� �����ΰ�?
		: winnt.h�� ������ void* �� ���� �� Ŀ�� ������Ʈ�� ���� �� ���� �Ҵ�Ǵ� �Ϸ��� ���� ���ڷμ�,
		Handle�� ���� �ش� Ŀ�� ������Ʈ�� ����

		Handle	|	Kernel Object	|	Resource
		Pipe Handle<->Pipe Kernel Obj<->Pipe
		Process Handle<->Process Kernel Obj<->Process
		etc..
	***/
}
