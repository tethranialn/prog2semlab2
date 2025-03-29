#include "file.h";
#include <iostream>;
using namespace std;
void open(ifstream& input, ofstream& output)
{
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
}
void close(ifstream& input, ofstream& output)
{
	input.close();
	output.close();
}