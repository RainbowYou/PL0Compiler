#include "WordAnalyzer.h"
#include "Symbol.h"

WordAnalyzer::WordAnalyzer()
{

}

WordAnalyzer::~WordAnalyzer()
{

}

void WordAnalyzer::setType(int t)
{
	type = t;
}

int WordAnalyzer::getType()
{
	return type;
}

void WordAnalyzer::setSymbol(char s)
{
	symbol = s;
}

char WordAnalyzer::getSymbol()
{
	return symbol;
}

void WordAnalyzer::setNum(int n)
{
	num = n;
}

int WordAnalyzer::getNum()
{
	return num;
}

void WordAnalyzer::setToken(char* t)
{
	strcpy(token, t);
}

char* WordAnalyzer::getToken()
{
	return token;
}

bool WordAnalyzer::isMulOperator(char c)
{
	if (c == '*' || c == '/') 
		return true;

	return false;
}

bool WordAnalyzer::isPlusOperator(char c)
{
	if (c == '+' || c == '-') 
		return true;

	return false;
}

bool WordAnalyzer::isRelOperator(char c)
{
	if (c == '=' || c == '<>' || c == '<' || c == '<=' || c == '>' || c == '>=') 
		return true;

	return false;
}

bool WordAnalyzer::isColon(char c)
{
	if (c == ':')
		return true;
	return false;
}


bool WordAnalyzer::isAssign(char c)
{
	if (c == '=')
		return true;
	return false;
}

bool WordAnalyzer::isComma(char c)
{
	if (c == ',')
		return true;
	return false;
}

bool WordAnalyzer::isLP(char c)
{
	if (c == '(')
		return true;
	return false;
}

bool WordAnalyzer::isRP(char c)
{
	if (c == ')')
		return true;
	return false;
}

bool WordAnalyzer::isSemicolon(char c)
{
	if (c == ';')
		return true;
	return false;
}

bool WordAnalyzer::isLetter(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return true;
	return false;
}

bool WordAnalyzer::isDigit(char c)
{
	if (c > '0' && c < '9')
		return true;
	return false;
}