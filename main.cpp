/*
����� �����, �������������� �������� �����.
������ ������ �������� �� ����� N ��������.
����� ������� �� �����������, ������� ����� ������������ �� ��������� ������.
����������� ������������� ������.
���� �� ����� ����� ��������� 5 �������� � ������.
���������� ���������� ���������� ����������� � ������.
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
	������� �� ������: ���������������� � h
	�����: �� ������ ������
	������ �����: ������ ���, ������ ����� � �� ���-��
	������� ������: 5 ����� �� 20 ��������, ����� ���� 20 � ��
*/