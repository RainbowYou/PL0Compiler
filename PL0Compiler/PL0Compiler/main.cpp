#include <iostream>
#include <fstream>
#include "WordAnalyzer.h"
#include "SyntaxAnalyzer.h"
using namespace std;

#pragma warning(disable : 4996)

int main(void)
{
	cout << "\n********************13211017-陈煜的编译原理大作业********************\n" << endl;

	SyntaxAnalyzer* syntaxAnalyzer = new SyntaxAnalyzer();
	syntaxAnalyzer->analyze();

	delete syntaxAnalyzer;
}