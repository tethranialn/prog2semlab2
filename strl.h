#pragma once
#include "const.h";
struct stroka //S
{
    char str[MaxLen];
    unsigned char dl;
};
struct text //T
{
    stroka txt[MaxStr];
    unsigned int Len = 0;
    unsigned int res = 0;
    int cur = 0;
};
struct bufer
{
    int massiv[MaxStr + 1] = {};
    int index = 0;
    int i = 0;
};