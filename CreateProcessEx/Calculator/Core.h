#ifndef _CORE_H_
#define _CORE_H_
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <tchar.h>
#include <windows.h>

#define DIR_LENGTH MAX_PATH + 1

enum OP 
{
	DIVIDE = 0,
	MULTIPLE,
	ADD,
	MINUS,
	ELSE, //��Ÿ �۾� ����
	EXIT,
	NUM_OF_OP, //��ü �۾� ����
	NOP //no operation
};

//CalcProc.cpp
void DispMenu();
DWORD InputMenu();

//CalcProc.cpp
void Divide(double, double);
void Multiple(double, double);
void Add(double, double);
void Minus(double, double);
#endif