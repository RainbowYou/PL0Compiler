#include "WordAnalyzer.h"
#include "Symbol.h"

WordAnalyzer::WordAnalyzer()
{
	token = "";
	symbol = "";
}

WordAnalyzer::~WordAnalyzer()
{
	delete token;
	delete symbol;
}

void WordAnalyzer::setType(int t)
{
	type = t;
}

int WordAnalyzer::getType()
{
	return type;
}

void WordAnalyzer::setSymbol(char* s)
{
	//strcpy(symbol, s);
	int len = strlen(s);
	symbol = new char[len+1];
	for (int i = 0; i < len; i++)
	{
		symbol[i] = s[i];
	}
	symbol[len] = '\0';
}

char* WordAnalyzer::getSymbol()
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
	//strcpy(token, t);
	int len = strlen(t);
	token = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		token[i] = t[i];
	}
	token[len] = '\0';
}

string WordAnalyzer::getToken()
{
	string str(token);
	return str;
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
			//type = RELATIONO;
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
			//type = RELATIONO;
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

bool WordAnalyzer::isKeywords(string str,int* t)
{
	for (int i = 0; i < keywordsLen; i++)
	{
		if (str == keywords[i])
		{
			*t = i;
			return true;
			break;
		}
	}
	return false;
}


void WordAnalyzer::analyze()
{
	if (isPlusOperator())
	{
		setType(PLUSO);
		setToken(symbol);
	}

	else if (isMulOperator())
	{
		setType(MULTIPLYO);
		setToken(symbol);
	}

	else if (isRelOperator())
	{
		setType(RELATIONO);
		setToken(symbol);
	}

	else if (isComma())
	{
		setType(COMMA);
		setToken(symbol);
	}

	else if (isSemicolon())
	{
		setType(SEMICOLON);
		setToken(symbol);
	}

	else if (isAssign())
	{
		setType(ASSIGN);
		setToken(symbol);
	}

	else if (isLP())
	{
		setType(LP);
		setToken(symbol);
	}

	else if (isRP())
	{
		setType(RP);
		setToken(symbol);
	}

	else if (isLetter(*symbol))
	{
		int length = strlen(symbol);
		bool flag = true;
		for (int i = 1; i < length; i++)
		{
			if (isLetter(symbol[i]) || isDigit(symbol[i])) flag = true;
			else { flag = false; break; }
			//symbol++;
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
			//Error handler should be put here!
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
			//symbol++;
		}

		if (flag)
		{
			setType(UINT);
			//Transfer string to integer
			setNum((*symbol) - '\0');
		}
		else //Not integer,token error!
		{
			//Error handler should be put here!
		}
	}

}