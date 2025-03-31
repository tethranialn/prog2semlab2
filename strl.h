#pragma once
#include "const.h";
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