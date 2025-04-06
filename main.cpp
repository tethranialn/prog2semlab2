/*
				  Версия программы: 0.9

 Задание:
	Задан текст, представленный массивом строк.
	Каждая строка содержит не более N символов.
	Текст состоит из предложений, которые могут переноситься на следующую строку.
	Предложения заканчиваются точкой.
	Одна из строк может содержать 5 пробелов в начале.
	Необходимо определить количество предложений в тексте.

	Автор: Чучалин Иван Валентинович	      Группа: 4354
	Дата начала: 22.03.2025		Дата окончания: 31.03.2025
*/
#include "functions.h"
#include <iostream>

int main() 
{
    std::ifstream input;
    std::ofstream output;
    text txt1; bufer B;
    input.unsetf(ios::skipws);
    open(input, output);
    while (!input.eof())
    {
        B.i = txt1.Len;
        bufInp(input, B);
        while (true)
        {
            read(input, &txt1, B);
            if (txt1.Len == 0) break;
            process(txt1);
            out(output, txt1);
        }
    }
    result(output, txt1);
    close(input, output);
    return 0;
}