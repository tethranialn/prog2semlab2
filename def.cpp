#include "functions.h"
#include <iostream>



void inputStr(std::ifstream& input, stroka& str1, bufer& B) 
{
    char sim;
    unsigned char j = 0;
    if(B.index == 0) input.seekg(+B.massiv[B.index], ios::beg);
    else
    {
        B.massiv[B.index] = B.massiv[B.index] - 1;
        input.seekg(+B.massiv[B.index], ios::beg);
    }
    for (j = 0; j < BLOCK_SIZE; ++j)
    {
        input >> sim;
        if (sim == '\n' || input.eof()) break;
        str1.str[j] = sim;
    }
    str1.dl = j;
    B.massiv[B.index] = input.tellg();
}
void bufInp(std::ifstream& input, bufer& B)
{
    char sim = ' ', i = 0;
    if (B.i != 0)
    {
        for (int j = 0; j < B.i; ++j)
        {
            while (sim != '\n' && !input.eof()) input.get(sim);
            if (input.eof()) break;
        }
    }
    while (i < 6 && !input.eof())
    {
        B.massiv[B.index + i] = input.tellg();
        while (sim != '\n' && !input.eof()) input.get(sim);
        if (!input.eof()) 
        {
            input.get(sim);
            if (input.eof()) break;
        }
        i++;
    }
}
void read(std::ifstream& input, text* txt1, bufer& B) {
    char sim = ' ';
    txt1->Len = 0;
    B.index = 0;
    for (int i = 0; i < MaxStr; ++i)
    {
        inputStr(input, txt1->txt[i], B);
        B.index++;
        if (txt1->txt[i].dl == 0) 
        { 
            break;
        }
        txt1->Len++;
    }
}

void OutStr(std::ofstream& output, stroka str1)
{
    for (unsigned char j = 0; j < str1.dl; ++j) 
    {
        output << str1.str[j];
    }
    output << std::endl;
}

void out(std::ofstream& output, text txt1) 
{
    output << "\nreaded text block:" << std::endl;
    for (unsigned int i = 0; i < txt1.Len; ++i)
    {
        OutStr(output, txt1.txt[i]);
    }
}

void ProcessStr(stroka& str1, text& txt1, char* sentence, int& sentence_len) 
{
    for (unsigned char j = 0; j < str1.dl; ++j) 
    {
        sentence[sentence_len++] = str1.str[j];
        sentence[sentence_len] = '\0';

        if (str1.str[j] == '.')
        {
            int start = 0;
            while (sentence[start] == ' ') 
            {
                start++;
            }
            if (start < sentence_len) 
            { 
                txt1.res++;
            }
            sentence_len = 0;
        }
    }
}

void process(text& txt1) 
{
    char sentence[100];
    int sentence_len = 0;

    for (unsigned int i = 0; i < txt1.Len; ++i) 
    {
        ProcessStr(txt1.txt[i], txt1, sentence, sentence_len);
    }
}

void result(std::ofstream& output, text txt1)
{
    output << "\nnumber of sentences: " << txt1.res << std::endl;
}