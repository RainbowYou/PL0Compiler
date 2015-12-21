#ifndef WORD_ANALYZER_H
#define WORD_ANALYZER_H

#include<iostream>
#include<cstring>
#include<string>
#include"Symbol.h"
using namespace std;

class WordAnalyzer
{
private:
	int type;
	int num;
	char* token;
	char symbol;

public:
	void setType(int t);
	int getType();
	void setNum(int n);
	int getNum();
	void setToken(char* t);
	char* getToken();
	void setSymbol(char s);
	char getSymbol();

public:
	WordAnalyzer();//constructor
	//WordAnalyzer();
	~WordAnalyzer();//destructor

	bool isPlusOperator(char c);
	bool isMulOperator(char c);
	bool isRelOperator(char c);
	bool isComma(char c);
	bool isColon(char c);
	bool isSemicolon(char c);
	//bool isEqual(char c);
	bool isAssign(char c);
	bool isLP(char c);
	bool isRP(char c);

	bool isLetter(char c);
	bool isDigit(char c);

};


#endif