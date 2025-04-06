#pragma once
#include "strl.h";
#include "file.h";
const int BLOCK_SIZE = 10;
void inputStr(std::ifstream& input, stroka& str1, bufer& B);
void read(std::ifstream& input, text* txt1, bufer& B);
void OutStr(std::ofstream& output, stroka str1);    
void out(std::ofstream& output, text txt1);        
void result(std::ofstream& output, text txt1);     
void ProcessStr(stroka& str1, text& txt1, char* sentence, int& sentence_len);
void process(text& txt1);
void bufInp(std::ifstream& input, bufer& B);
