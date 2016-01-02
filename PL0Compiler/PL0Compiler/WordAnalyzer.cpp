#include <fstream>
#include "WordAnalyzer.h"
#include "Symbol.h"
using namespace std;

#pragma warning(disable : 4996)

int WordAnalyzer::cur = -1;

WordAnalyzer::WordAnalyzer()
{
	initialData();
}

WordAnalyzer::~WordAnalyzer()
{
	delete token;
	delete symbol;
}

void WordAnalyzer::initialData()
{
	setToken("");
	setSymbol("");
	setNum(-1);
	setType(-1);
}

bool WordAnalyzer::fillSymbols()
{
	ifstream sourceFile("test2.txt", ios::in);

	if (!sourceFile)
	{
		cerr << "File could not be opened!" << endl;
		return false;
	}

	string c;
	while (sourceFile >> c)
	{
		symbols.push_back(c);
	}
	return true;
}

void WordAnalyzer::setType(int t)
{
	type = t;
}

int WordAnalyzer::getType() const
{
	return type;
}

void WordAnalyzer::setSymbol(char* s)
{
	int len = strlen(s);
	symbol = new char[len+1];
	for (int i = 0; i < len; i++)
	{
		symbol[i] = s[i];
	}
	symbol[len] = '\0';
}

void WordAnalyzer::setSymbol()
{
	cur++;
	//Analyzing complete!
	if (cur >= symbols.size()) { cout << "\nanalyze complete!" << endl; exit(1); }

	string curSymbol(symbols[cur]);
	int length = symbols[cur].length();

	char str[20] = { " " };
	symbols[cur].copy(str, length, 0);

	setSymbol(str);
	analyze();
}


string WordAnalyzer::getSymbol() const
{
	string str(symbol);
	return str;
}

void WordAnalyzer::setNum(int n)
{
	num = n;
}

int WordAnalyzer::getNum() const
{
	return num;
}

void WordAnalyzer::setToken(char* t)
{
	int len = strlen(t);
	token = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		token[i] = t[i];
	}
	token[len] = '\0';
}

string WordAnalyzer::getToken() const
{
	string str(token);
	return str;
}

void WordAnalyzer::back()
{
	cur--;
	if (cur < 0) return;
}

bool WordAnalyzer::isMulOperator()
{
	int length = strlen(symbol);
	if (length == 1)
	{
		if ((*symbol == '*') || (*symbol == '/'))
			return true;
		return false;
	}
	return false;
}

bool WordAnalyzer::isPlusOperator()
{
	int length = strlen(symbol);
	if (length == 1)
	{
		if ((*symbol == '+') || (*symbol == '-'))
			return true;
		return false;
	}
	return false;
}

bool WordAnalyzer::isRelOperator()
{
	int length = strlen(symbol);
	if (length == 1)
	{
		if (isEqual(*symbol) || (*symbol=='<') || (*symbol=='>'))
		{
			return true;
		}
		return false;
	}

	else if (length == 2)
	{
		if (((*symbol == '<') && (*(symbol + 1) == '>')) || 
			((*symbol == '<') && (*(symbol + 1) == '=')) || 
			((*symbol == '>') && (*(symbol + 1) == '=')))
		{
			return true;
		}
		return false;
	}

	return false;
}

bool WordAnalyzer::isColon(char c)
{
	if (c == ':')
		return true;
	return false;
}

bool WordAnalyzer::isEqual(char c)
{
	if (c == '=') return true;
	return false;
}

bool WordAnalyzer::isAssign()
{
	int length = strlen(symbol);
	if (length == 2)
	{
		if (isColon(*symbol) && isEqual(*(symbol + 1)))
			return true;
		return false;
	}
	return false;
}

bool WordAnalyzer::isComma()
{
	int length = strlen(symbol);
	if (length == 1)
	{
		if (*symbol == ',')
			return true;
		return false;
	}
	return false;
}

bool WordAnalyzer::isLP()
{
	int length = strlen(symbol);
	if (length == 1)
	{
		if (*symbol == '(')
			return true;
		return false;
	}
	return false;
}

bool WordAnalyzer::isRP()
{
	int length = strlen(symbol);
	if (length == 1)
	{
		if (*symbol == ')')
			return true;
		return false;
	}
	return false;
}

bool WordAnalyzer::isSemicolon()
{
	int length = strlen(symbol);
	if (length == 1)
	{
		if (*symbol == ';')
			return true;
		return false;
	}
	return false;
}

bool WordAnalyzer::isPoint()
{
	int length = strlen(symbol);
	if (length == 1)
	{
		if (*symbol == '.')
			return true;
		return false;
	}
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
	if (c >= '0' && c <= '9')
		return true;
	return false;
}

bool WordAnalyzer::isKeywords(string str,int* t)
{
	for (int i = 0; i < keywordsLen; i++)
	{
		if (str == keywords[i])
		{
			*t = i + 1;
			return true;
			break;
		}
	}
	return false;
}


void WordAnalyzer::analyze()
{
	if (isPlusOperator()) { setType(PLUSO); setToken(symbol); }

	else if (isMulOperator()) { setType(MULTIPLYO); setToken(symbol); }

	else if (isRelOperator()) { setType(RELATIONO); setToken(symbol); }

	else if (isComma()) { setType(COMMA); setToken(symbol); }

	else if (isSemicolon()) { setType(SEMICOLON); setToken(symbol); }

	else if (isAssign()) { setType(ASSIGN); setToken(symbol); }

	else if (isLP()) { setType(LP); setToken(symbol); }

	else if (isRP()) { setType(RP); setToken(symbol); }

	else if (isLetter(*symbol))
	{
		int length = strlen(symbol);
		bool flag = true;
		for (int i = 1; i < length; i++)
		{
			if (isLetter(symbol[i]) || isDigit(symbol[i])) flag = true;
			else { flag = false; break; }
		}

		if (flag)
		{
			//Finding if identifier is keyword
			string str(symbol);
			int* t = new int(0);
			if (isKeywords(str,t)) setType(*t);
			else setType(IDENTIFIER);

			setToken(symbol);
		}
		else //Not correct identifier ,token error !
		{
			cout << "\nerror:token " << this->getSymbol()<< " declaration is invalid\n" << endl;
		}
	}

	else if (isDigit(*symbol))
	{
		int length = strlen(symbol);
		bool flag = true;
		for (int i = 1; i < length; i++)
		{
			if (isDigit(symbol[i])) flag == true;
			else 
			{
				flag = false;
				break;
			}
		}

		if (flag)
		{
			setType(UINT);
			setToken(symbol);
		}
		else //Not integer,token error!
		{
			cout << "\nerror: token \" " << this->getSymbol() << " \" declaration is invalid\n" << endl;
		}
	}
	else
	{
		cout << "\nerror:token \" " << this->getSymbol() << " \" declaration is invalid\n" << endl;
	}
	//cout << "( " << this->getType() << " , " << this->getToken() << " )\n";
}