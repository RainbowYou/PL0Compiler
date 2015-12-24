#include "WordAnalyzer.h"
#include "SyntaxAnalyzer.h"

SyntaxAnalyzer::SyntaxAnalyzer()
{
	setSymbol("");
	setWordAnalyzer();
}

SyntaxAnalyzer::~SyntaxAnalyzer()
{
	delete symbol;
}

void SyntaxAnalyzer::setSymbol(char* s)
{
	int len = strlen(s);
	symbol = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		symbol[i] = s[i];
	}
	symbol[len] = '\0';
}

char* SyntaxAnalyzer::getSymbol() const
{
	return symbol;
}

void SyntaxAnalyzer::setWordAnalyzer()
{
	wordAnalyzer.fillSymbols();
}

WordAnalyzer SyntaxAnalyzer::getWordAnalyzer() const
{
	return wordAnalyzer;
}

void SyntaxAnalyzer::analyze()
{
	wordAnalyzer.setSymbol();
	program();
}

void SyntaxAnalyzer::program()
{
	partialProgram();

	if (wordAnalyzer.getType() == POINT)
	{

	}

	else //syntax error,at the end of the program must exsit a point
	{
		//error handlers should be put here!
	}
}

void SyntaxAnalyzer::partialProgram()
{
	if (wordAnalyzer.getType() == CONST) constPart();

	else if (wordAnalyzer.getType() == VAR) varPart();

	else if (wordAnalyzer.getType() == PROCEDURE) procedurePart();

	else sentence();
	
	wordAnalyzer.setSymbol();
}

void SyntaxAnalyzer::constPart()
{
	wordAnalyzer.setSymbol();
	constDef();
		
	while (wordAnalyzer.getType() == COMMA)
	{
		wordAnalyzer.setSymbol();
		constDef();		
	}

	if (wordAnalyzer.getType() == SEMICOLON)
	{
		//wordAnalyzer.setSymbol();
	}

	else 
	{
		//syntax error,error handlers should be put here!
	}
}

void SyntaxAnalyzer::identifier()
{
	if (wordAnalyzer.getType() == IDENTIFIER)
	{
		wordAnalyzer.setSymbol();
	}
}

void SyntaxAnalyzer::constDef()
{
	if (wordAnalyzer.getType() == IDENTIFIER)
	{
		wordAnalyzer.setSymbol();
		if (wordAnalyzer.getType() == RELATIONO && wordAnalyzer.getToken() == "=")
		{
			wordAnalyzer.setSymbol();
			if (wordAnalyzer.getType() == UINT)
			{
				wordAnalyzer.setSymbol();
			}
			else 
			{//syntax error,error handlers should be put here!
			}
		}
		else
		{
			//syntax error,error handlers should be put here!
		}
	}
	else
	{
		//syntax error,error handlers should be put here!
	}
}

void SyntaxAnalyzer::varPart()
{
	wordAnalyzer.setSymbol();
	identifier();
	while (wordAnalyzer.getType() == COMMA)
	{
		wordAnalyzer.setSymbol();
		identifier();
	}

	if (wordAnalyzer.getType()==SEMICOLON)
	{
				
	}
	else
	{
		//syntax error,error handlers should be put here!
	}
}

void SyntaxAnalyzer::procedurePart()
{
	procedureHeader();

	if(wordAnalyzer.getType() == SEMICOLON)
	{

	}
	else
	{
		//syntax error,error handlers should be put here!
	}
}

void SyntaxAnalyzer::procedureHeader()
{
	wordAnalyzer.setSymbol();
	if (wordAnalyzer.getType() == IDENTIFIER)
	{
		wordAnalyzer.setSymbol();
		if (wordAnalyzer.getType() == SEMICOLON)
		{
			wordAnalyzer.setSymbol();
			partialProgram();
		}
		else
		{
			//syntax error,error handlers should be put here!
		}
	}
	else
	{
		//syntax error,error handlers should be put here!
	}
}

void SyntaxAnalyzer::sentence()
{
	if (wordAnalyzer.getType() == IDENTIFIER) assignSentence();
	
	else if(wordAnalyzer.getType()==IF) conditionSentence();

	else if (wordAnalyzer.getType() == WHILE) whileSentence();

	else if (wordAnalyzer.getType() == CALL) procedureCallSentence();

	else if (wordAnalyzer.getType() == READ) readSentence();

	else if (wordAnalyzer.getType() == WRITE) writeSentence();

	else if (wordAnalyzer.getType() == BEGIN) uniteSentence();

	else if (wordAnalyzer.getType() == REPEAT) repeatSentence();

	wordAnalyzer.setSymbol();
}

void SyntaxAnalyzer::assignSentence()
{
	wordAnalyzer.setSymbol();
	if (wordAnalyzer.getType() == ASSIGN)
	{
		expression();
	}
	else
	{
		//syntax error,error handlers should be put here!
	}
}

void SyntaxAnalyzer::expression()
{
	wordAnalyzer.setSymbol();
	bool isPlus = wordAnalyzer.getType() == PLUSO ? true : false;
	if (!isPlus) wordAnalyzer.back();

	wordAnalyzer.setSymbol();
	item();

	while (wordAnalyzer.getType() == RELATIONO)
	{
		item();
		wordAnalyzer.setSymbol();
	}

}

void SyntaxAnalyzer::item()
{
	factor();
	while (wordAnalyzer.getType() == MULTIPLYO)
	{
		wordAnalyzer.setSymbol();
		factor();	
	}
}

void SyntaxAnalyzer::factor()
{
	if (wordAnalyzer.getType() == LP)
	{
		expression();
		wordAnalyzer.setSymbol();
		if (wordAnalyzer.getType() == RP)
		{
			wordAnalyzer.setSymbol();
		}
		else
		{
			//syntax error,error handlers should be put here!
		}
	}

	else if (wordAnalyzer.getType()==IDENTIFIER)
	{
		wordAnalyzer.setSymbol();
	}

	else if (wordAnalyzer.getType() == UINT)
	{
		wordAnalyzer.setSymbol();
	}

	else
	{
		//syntax error,error handlers should be put here!
	}
}

void SyntaxAnalyzer::conditionSentence()
{
	condition();
	wordAnalyzer.setSymbol();
	if (wordAnalyzer.getType() == THEN)
	{
		sentence();
		if (wordAnalyzer.getType() == ELSE)
		{
			wordAnalyzer.setSymbol();
			sentence();
		}
	}
	else
	{
		//syntax error,error handlers should be put here!
	}
}

void SyntaxAnalyzer::condition()
{
	wordAnalyzer.setSymbol();
	if (wordAnalyzer.getType() == ODD)
	{
		expression();
	}
	else
	{
		expression();
		wordAnalyzer.setSymbol();
		if (wordAnalyzer.getType() == RELATIONO)
		{
			expression();
		}
		else
		{
			//syntax error,error handlers should be put here!
		}
	}
}

void SyntaxAnalyzer::whileSentence()
{
	condition();
	wordAnalyzer.setSymbol();
	if (wordAnalyzer.getType() == DO)
	{
		sentence();
	}
	else
	{
		//syntax error,error handlers should be put here!
	}
}

void SyntaxAnalyzer::procedureCallSentence()
{
	wordAnalyzer.setSymbol();
	if (wordAnalyzer.getType() == IDENTIFIER)
	{

	}
	else
	{
		//syntax error,error handlers should be put here!
	}
}

void SyntaxAnalyzer::uniteSentence()
{
	sentence();
		
	while (wordAnalyzer.getType() == SEMICOLON)
	{
		wordAnalyzer.setSymbol();
		sentence();
	}

	if (wordAnalyzer.getType() == END)
	{

	}
	else
	{
			//syntax error,error handlers should be put here!
	}
}

void SyntaxAnalyzer::repeatSentence()
{
	sentence();

	while (wordAnalyzer.getType() == SEMICOLON)
	{
		wordAnalyzer.setSymbol();
		sentence();
	}

	if (wordAnalyzer.getType() == UNTIL)
	{
		condition();
	}
	else
	{
		//syntax error,error handlers should be put here!
	}

}

void SyntaxAnalyzer::readSentence()
{
	wordAnalyzer.setSymbol();
	if (wordAnalyzer.getType() == LP)
	{
		wordAnalyzer.setSymbol();
		identifier();
		while (wordAnalyzer.getType() == COMMA)
		{
			wordAnalyzer.setSymbol();
			identifier();
		}
			
		if (wordAnalyzer.getType() == RP)
		{

		}
		else
		{
			//syntax error,error handlers should be put here!
		}
	}
	else
	{
		//syntax error,error handlers should be put here!
	}
}

void SyntaxAnalyzer::writeSentence()
{
	wordAnalyzer.setSymbol();
	if (wordAnalyzer.getType() == LP)
	{
		wordAnalyzer.setSymbol();
		identifier();
		while (wordAnalyzer.getType() == COMMA)
		{
			wordAnalyzer.setSymbol();
			identifier();
		}

		if (wordAnalyzer.getType() == RP)
		{

		}
		else
		{
			//syntax error,error handlers should be put here!
		}
	}
	else
	{
		//syntax error,error handlers should be put here!
	}
}
