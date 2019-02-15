#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	char ch;
	int count = 0;
	char stroka[100];

	ifstream fin("input.txt");

	while ((fin.get(ch)) && (!fin.eof()))
	{
		stroka[count] = ch;
		count++;
	}

	int countOne = 0;
	int One[50];
	int j = 0;
	for (int i = 0; i < count; i++)
	{
		if (stroka[i] == '0')
			countOne++;
		else
		{
			One[j] = countOne;
			countOne = 0;
			j++;
		}
	}


	int max = One[0];
	for (int i = 0; i < j; i++)
	{
		if (One[i] > max)
			max = One[i];
	}

	ofstream fout("output.txt");
	fout << max;

	fin.close();
	fout.close();
	return 0;
}