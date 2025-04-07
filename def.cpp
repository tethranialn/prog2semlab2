#include "functions.h"
#include <iostream>
bool inputStr(std::ifstream& input, stroka& str1, unsigned int x)
{
    char s{};

    for (x *= MaxLen; !input.eof() && s != '\n' && x; --x)
        input >> s;

    str1.dl = 0;
    if (!x)
        while (str1.dl < MaxLen)
        {
            input >> s;
            if (input.eof() || s == '\n')
                break;
            str1.str[str1.dl++] = s;
        }
    return input.eof() || s == '\n';
}
bool read(std::ifstream& input, text* txt1, unsigned int x, unsigned int y)
{
    bool result = false;
    input.clear();
    input.seekg(0, ios::beg);
    input.unsetf(ios::skipws);
    char s;
    for (y *= MaxStr; !input.eof() && y; --y)
    {
        do
            input >> s;
        while (!input.eof() && s != '\n');
    }

    txt1->Len = 0;
    if (!y)
        for (; !input.eof() && txt1->Len < MaxStr; ++(txt1->Len))
        {
            if (!inputStr(input, txt1->txt[txt1->Len], x))
            {
                do
                    input >> s;
                while (!input.eof() && s != '\n');
            }
            result |= txt1->txt[txt1->Len].dl > 0;
        }
    return result;
}

void OutStr(std::ofstream& output, stroka str1)
{
    unsigned char j = 0;
    while (j < str1.dl)
        output << str1.str[j++];
    for (; j < MaxLen; ++j)
        output << Filler;
}

void out(std::ofstream& output, text txt1)
{
    output << "Text block read:\n+-";
    unsigned int i = 0;
    for (; i < MaxLen; ++i)
        output << '-';
    output << "-+\n";
    for (i = 0; i < txt1.Len; ++i)
    {
        output << "| ";
        if (i < txt1.Len)
            OutStr(output, txt1.txt[i]);
        else
            for (unsigned int i = 0; i < MaxLen; ++i)
                output << Filler;
        output << " |\n";
    }
    output << "+-";
    for (i = 0; i < MaxLen; ++i)
        output << '-';
    output << "-+\n\n";
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