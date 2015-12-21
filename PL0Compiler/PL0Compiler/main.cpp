#include <iostream>
#include"WordAnalyzer.h"
using namespace std;

int main(void)
{
	WordAnalyzer wordAnalyzer;
	char* s = new char();
	char c = ' ';
	printf("Please enter some sentences:\n");
	gets(s);
	int length = strlen(s);
	for (int i = 0; i < length; i++)
	{
		wordAnalyzer.setSymbol(*s);
		wordAnalyzer.analyze();
		printf("%d\n", wordAnalyzer.getType());
		s++;
	}
}