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
};