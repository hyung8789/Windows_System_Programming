#ifndef _CMDTOKEN_H_
#define _CMDTOKEN_H_

// CmdToken.cpp

class CMD_TOKEN //��ɾ� ��ū
{
public:
	CMD_TOKEN();
	~CMD_TOKEN();

	void ClearAll();
	
	void GenerateToken(void* args);

	enum CMD_TYPE GetCmdType();
	const TCHAR* GetCmdSubArgs();

private:
	BOOL isCmdSubArgsAssigned;
	BOOL isCmdTypeAssigned;

	enum CMD_TYPE _cmdType; //��ɾ� Ÿ��
	TCHAR _cmdSubArgs[MAX_STR_LEN]; //�ش� ��ɾ ���� ���� ����
};
#endif