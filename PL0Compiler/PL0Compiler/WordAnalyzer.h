#ifndef WORD_ANALYZER_H
#define WORD_ANALYZER_H

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include "Symbol.h"

class WordAnalyzer
{
private:
	int type;//�ʷ���Ԫ������
	int num;//�洢������
	char* token;//�洢�Ĵʷ���Ԫ��������ֵ)
	char* symbol;//��ǰ������ַ���
	vector<string> symbols;
	static int cur;
	
public:
	WordAnalyzer();//constructor
	//WordAnalyzer(int&, int&, char* &, char* &);//copy constructor
	~WordAnalyzer();//destructor

public:
	void setType(int t);
	void setNum(int n);
	void setSymbol();

	int getType() const;
	int getNum() const;
	string getToken() const;
	string getSymbol() const;
	
	
	bool fillSymbols();

	void initialData();

	void analyze();

	void back();

	//int getCurPtr() const { return cur; }
	//vector<string> getSymbols() const { return symbols; }

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
	bool isPoint();
	bool isLetter(char c);
	bool isDigit(char c);

	void setSymbol(char* s);
	void setToken(char* t);

	bool isKeywords(string str,int* t);//Finding if a token is keyword

};


#endif