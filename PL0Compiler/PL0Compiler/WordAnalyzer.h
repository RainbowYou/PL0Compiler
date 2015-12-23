#ifndef WORD_ANALYZER_H
#define WORD_ANALYZER_H

#include<iostream>
#include<cstring>
#include<string>
#include"Symbol.h"

class WordAnalyzer
{
private:
	int type;//词法单元的类型
	int num;//存储整型数
	char* token;//存储的词法单元（即单词值)
	char* symbol;//当前读入的字符串

public:
	WordAnalyzer();//constructor
	~WordAnalyzer();//destructor

public:
	void setType(int t);
	int getType() const;
	void setNum(int n);
	int getNum() const;
	void setToken(char* t);
	string getToken() const;
	void setSymbol(char* s);
	char* getSymbol() const;

	void initialData();

	void analyze();

private:
	bool isPlusOperator();
	bool isMulOperator();
	bool isRelOperator();
	bool isComma();
	bool isColon(char c);
	bool isSemicolon();
	bool isEqual(char c);
	bool isAssign();
	bool isLP();
	bool isRP();

	bool isLetter(char c);
	bool isDigit(char c);


	bool isKeywords(string str,int* t);//Finding if a token is keyword

};


#endif