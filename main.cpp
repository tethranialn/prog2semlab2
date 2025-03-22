/*
Задан текст, представленный массивом строк.
Каждая строка содержит не более N символов.
Текст состоит из предложений, которые могут переноситься на следующую строку.
Предложения заканчиваются точкой.
Одна из строк может содержать 5 пробелов в начале.
Необходимо определить количество предложений в тексте.
*/
#include <iostream>;
#include <fstream>;
using namespace std;
const int N = 100;
struct strL
{
	char str[N][N];
	unsigned L[N];
	unsigned res = 0;
	unsigned S = 0;
};
void main()
{
	strL work;
	ifstream input; ofstream output;
	input.open("text.txt");
	if (!input.is_open())
	{
		cout << "input file is not open";
		return;
	}
	output.open("result.txt");
	if (!output.is_open())
	{
		cout << "output file is not open";
		return;
	}
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
	input.close();
	output.close();
	return;
}
/*
	Разбить на модули: пользовательские в h
	Длина: на каждую строку
	Массив строк: второй тип, массив строк и их кол-во
	Блочное чтение: 5 строк по 20 символов, потом след 20 и тд
*/