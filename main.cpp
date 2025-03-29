/*
Задан текст, представленный массивом строк.
Каждая строка содержит не более N символов.
Текст состоит из предложений, которые могут переноситься на следующую строку.
Предложения заканчиваются точкой.
Одна из строк может содержать 5 пробелов в начале.
Необходимо определить количество предложений в тексте.
*/
#include "const.h";
#include "strl.h";
#include "file.h";
using namespace std;
strL work; ifstream input; ofstream output;
void main()
{
	open(input, output);
	output << "readed text:\n";
	while (!input.eof() && work.S < N)
	{
		int i = 0;
		while (!input.eof() && i < N && work.str[work.S][i] != '\n')
		{
			input >> noskipws >> work.str[work.S][i];
			output << work.str[work.S][i];
			work.L[work.S] = i;
			if (work.str[work.S][i] == '.') work.res++; //remove
			if (work.str[work.S][i] == '\n') break;
			i++;
		} 
		work.S++;
	}
	output << endl << "\nnumber of sentences: " << work.res << "\nnumber of rows: " << work.S << endl << "number of symbols in each row:";
	for (int i = 0; i < work.S; i++)
	{
		output << endl << i+1 << '.' << work.L[i];
	}
	close(input, output);
	return;
}
/*
	Разбить на модули: пользовательские в h
	Длина: на каждую строку
	Массив строк: второй тип, массив строк и их кол-во
	Блочное чтение: 5 строк по 20 символов, потом след 20 и тд
*/