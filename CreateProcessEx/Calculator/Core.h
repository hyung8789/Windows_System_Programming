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
	ELSE, //기타 작업 수행
	EXIT,
	NUM_OF_OP, //전체 작업 개수
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