#include <iostream>
#include <fstream>
#include "WordAnalyzer.h"
#include "SyntaxAnalyzer.h"
using namespace std;

#pragma warning(disable : 4996)

int main(void)
{
	SyntaxAnalyzer* syntaxAnalyzer = new SyntaxAnalyzer();
	syntaxAnalyzer->analyze();
	cout << "Syntax analyzes complete!" << endl;
	//delete syntaxAnalyzer;
}