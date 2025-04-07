/*
				  Версия программы: 1.0

 Задание:
	Задан текст, представленный массивом строк.
	Каждая строка содержит не более N символов.
	Текст состоит из предложений, которые могут переноситься на следующую строку.
	Предложения заканчиваются точкой.
	Одна из строк может содержать 5 пробелов в начале.
	Необходимо определить количество предложений в тексте.

	Автор: Чучалин Иван Валентинович	      Группа: 4354
	Дата начала: 22.03.2025		Дата окончания: 06.04.2025
*/
#include "functions.h"
#include <iostream>

int main() {
    std::ifstream input;
    std::ofstream output;
    text txt1;
    open(input, output);
    unsigned int x, y{};
    for (;;)
    {
        x = 0;
        if (!read(input, &txt1, x, y) && input.eof())
            break;
        for (;;)
        {
            process(txt1);
            out(output, txt1);
            if (!read(input, &txt1, ++x, y))
                break;
        }
        ++y;
    }
    result(output, txt1);
    close(input, output);
    return 0;
}