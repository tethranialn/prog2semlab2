#pragma once
#include "const.h";
struct strL
{
	char str[N][N];
	unsigned L[N];
};
struct stroka //S
{
	char str[MaxLen];
	unsigned dl;
};
struct text //T
{
	stroka txt[MaxStr];
	unsigned Len;
	unsigned res = 0;
	unsigned S = 0;
};

