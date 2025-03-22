/*
����� �����, �������������� �������� �����.
������ ������ �������� �� ����� N ��������.
����� ������� �� �����������, ������� ����� ������������ �� ��������� ������.
����������� ������������� ������.
���� �� ����� ����� ��������� 5 �������� � ������.
���������� ���������� ���������� ����������� � ������.
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
	������� �� ������: ���������������� � h
	�����: �� ������ ������
	������ �����: ������ ���, ������ ����� � �� ���-��
	������� ������: 5 ����� �� 20 ��������, ����� ���� 20 � ��
*/