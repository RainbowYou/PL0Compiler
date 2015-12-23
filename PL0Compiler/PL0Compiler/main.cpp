#include <iostream>
#include <fstream>
#include"WordAnalyzer.h"
using namespace std;

#pragma warning(disable : 4996)

int main(void)
{
	WordAnalyzer wordAnalyzer;
	ifstream sourceFile("test1.txt", ios::in);
	ofstream outputFile;

	outputFile.open("output1.txt", ios::out);
	if (!sourceFile)
	{
		cerr << "File could not be opened!" << endl;
		exit(1);
	}

	string c;
	while (sourceFile >> c)
	{
		int length = c.length();

		//Transfer type string to type char*
		char* str = new char[length + 1];
		c.copy(str, length, 0);
		str[length] = '\0';

		//Setting current reading string
		wordAnalyzer.setSymbol(str);
		wordAnalyzer.analyze();
		outputFile << "( " << wordAnalyzer.getType() << ",";
		if (wordAnalyzer.getNum() != -1) outputFile << wordAnalyzer.getNum() << " )" << endl;
		else outputFile << wordAnalyzer.getToken() << " )" << endl;
		wordAnalyzer.initialData();
	}
	outputFile.close();
}