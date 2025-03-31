/*
Задан текст, представленный массивом строк.
Каждая строка содержит не более N символов.
Текст состоит из предложений, которые могут переноситься на следующую строку.
Предложения заканчиваются точкой.
Одна из строк может содержать 5 пробелов в начале.
Необходимо определить количество предложений в тексте.
*/
//#include "const.h";
//#include "strl.h";
//#include "file.h";
#include "functions.h";
ifstream input; ofstream output;
stroka str1; text txt1;
void main()
{
	open(input, output);
	input.unsetf(ios::skipws);
	read(input, &txt1);
	process();
	out(output, txt1);
	close(input, output);
	return;
}
/*
	Блочное чтение: 5 строк по 20 символов, потом след 20 и тд
*/