#include <iostream>
#include <fstream>
#include "WordAnalyzer.h"
#include "SyntaxAnalyzer.h"
using namespace std;

#pragma warning(disable : 4996)

int main(void)
{
	cout << "\n********************13211017-���ϵı���ԭ�����ҵ********************\n" << endl;

	SyntaxAnalyzer* syntaxAnalyzer = new SyntaxAnalyzer();
	syntaxAnalyzer->analyze();

	delete syntaxAnalyzer;
}