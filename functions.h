#pragma once
#include "strl.h";
#include "file.h";
bool inputStr(std::ifstream& input, stroka& str1, unsigned int x);
bool read(std::ifstream& input, text* txt1, unsigned int x, unsigned int y);
void OutStr(std::ofstream& output, stroka str1);
void out(std::ofstream& output, text txt1);
void result(std::ofstream& output, text txt1);
void ProcessStr(stroka& str1, text& txt1, char* sentence, int& sentence_len);
void process(text& txt1);
