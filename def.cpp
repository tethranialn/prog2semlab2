#include "functions.h";
void inputStr(ifstream& input, stroka& str1)
{
	char j = 0, sim;
	while (!input.eof() && (j < MaxLen))
	{
		input >> sim; if (sim == '\n') break;
		str1.str[j] = sim; j++;
	}
	if (input.eof()) j--;
	str1.dl = j;
	if ((sim != '\n') && (!input.eof()))
		while (!input.eof()) { input >> sim; if (sim == '\n') break; }
}
void read(ifstream& input, text* txt1)
{
	char i = 0;
	while (!input.eof() && (i < MaxStr))
	{
		inputStr(input, (*txt1).txt[i]); i++;
	}
	txt1->Len = i;
}
void OutStr(ofstream& output, stroka str1)
{
	char j;
	for (j = 0; j < str1.dl; j++) output << str1.str[j];
	output << endl;
}
void out(ofstream& output, text txt1)
{
	unsigned i;
	output << "\nreaded text block:" << endl;
	for (i = 0; i < txt1.Len; i++) OutStr(output, txt1.txt[i]);
}
void result(ofstream& output, text txt1)
{
	output << "\nnumber of sentences: " << txt1.res;
}
void ProcessStr(stroka& str1, text& txt1)
{
	char j, tmp;
	for (j = 0; j < str1.dl; j++)
	{
		tmp = str1.str[j];
		if (tmp == '.') txt1.res++;
	}
}
void process(text& txt1)
{
	unsigned i;
	for (i = 0; i < txt1.Len; i++)
	{
		ProcessStr(txt1.txt[i], txt1);
	}
}