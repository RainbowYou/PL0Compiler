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

}

void SyntaxAnalyzer::program()
{
	partialProgram();

	wordAnalyzer.setSymbol();
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
	constPart();
	varPart();
	procedurePart();
	sentence();
}

void SyntaxAnalyzer::constPart()
{
	wordAnalyzer.setSymbol();
	if (wordAnalyzer.getType() == CONST)
	{
		constDef();
		wordAnalyzer.setSymbol();
		if (wordAnalyzer.getType() == COMMA)
		{
			while (wordAnalyzer.getType() == COMMA)
			{
				constDef();
				wordAnalyzer.setSymbol();
			}
		}

		else if (wordAnalyzer.getType() == SEMICOLON)
		{
			//wordAnalyzer.setSymbol();
		}

		else 
		{
			//syntax error,error handlers should be put here!
		}
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
	wordAnalyzer.setSymbol();
	if (wordAnalyzer.getType() == IDENTIFIER)
	{
		wordAnalyzer.setSymbol();
		if (wordAnalyzer.getType() == RELATIONO && wordAnalyzer.getToken() == "=")
		{
			wordAnalyzer.setSymbol();
			if (wordAnalyzer.getType() == UINT)
			{
				
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
	if (wordAnalyzer.getType() == VAR)
	{
		wordAnalyzer.setSymbol();
		if (wordAnalyzer.getType() == IDENTIFIER)
		{
			wordAnalyzer.setSymbol();
			if (wordAnalyzer.getType() == COMMA)
			{
				while (wordAnalyzer.getType() == COMMA)
				{
					wordAnalyzer.setSymbol();
					if (wordAnalyzer.getType() == IDENTIFIER)
					{
						wordAnalyzer.setSymbol();
					}
					else
					{
						//syntax error,error handlers should be put here!
					}

				}
			}
			else if (wordAnalyzer.getType()==SEMICOLON)
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
	else
	{
		//syntax error,error handlers should be put here!
	}
}

void SyntaxAnalyzer::procedurePart()
{
	procedureHeader();
	partialProgram();

	wordAnalyzer.setSymbol();
	if (wordAnalyzer.getType() == SEMICOLON)
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
	if (wordAnalyzer.getType() == PROCEDURE)
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
	else
	{
		//syntax error,error handlers should be put here!
	}
}

void SyntaxAnalyzer::sentence()
{
	assignSentence();
	conditionSentence();
	whileSentence();
	procedureCallSentence();
	readSentence();
	writeSentence();
	uniteSentence();
	repeatSentence();
}

void SyntaxAnalyzer::assignSentence()
{
	wordAnalyzer.setSymbol();
	if (wordAnalyzer.getType() == IDENTIFIER)
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
		factor();
		wordAnalyzer.setSymbol();
	}
}

void SyntaxAnalyzer::factor()
{
	wordAnalyzer.setSymbol();
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
	wordAnalyzer.setSymbol();
	if (wordAnalyzer.getType() == IF)
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
		wordAnalyzer.back();
		expression();
		wordAnalyzer.setSymbol();
		if (wordAnalyzer.getType() == RELATIONO)
		{

		}
		else
		{
			//syntax error,error handlers should be put here!
		}
		expression();
	}
}

void SyntaxAnalyzer::whileSentence()
{
	wordAnalyzer.setSymbol();
	if (wordAnalyzer.getType() == WHILE)
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
	else
	{
		//syntax error,error handlers should be put here!
	}
}

void SyntaxAnalyzer::procedureCallSentence()
{
	wordAnalyzer.setSymbol();
	if (wordAnalyzer.getType() == CALL)
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
	else
	{
		//syntax error,error handlers should be put here!
	}
}

void SyntaxAnalyzer::uniteSentence()
{
	wordAnalyzer.setSymbol();
	if (wordAnalyzer.getType() == BEGIN)
	{
		sentence();
		
		while (wordAnalyzer.getType() == SEMICOLON)
		{
			wordAnalyzer.setSymbol();
			sentence();
		}

		wordAnalyzer.setSymbol();
		if (wordAnalyzer.getType() == END)
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

void SyntaxAnalyzer::repeatSentence()
{
	wordAnalyzer.setSymbol();
	if (wordAnalyzer.getType() == REPEAT)
	{
		sentence();

		while (wordAnalyzer.getType() == SEMICOLON)
		{
			wordAnalyzer.setSymbol();
			sentence();
		}

		wordAnalyzer.setSymbol();
		if (wordAnalyzer.getType() == UNTIL)
		{
			condition();
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

void SyntaxAnalyzer::readSentence()
{
	wordAnalyzer.setSymbol();
	if (wordAnalyzer.getType() == READ)
	{
		wordAnalyzer.setSymbol();
		if (wordAnalyzer.getType() == LP)
		{
			wordAnalyzer.setSymbol();
			if (wordAnalyzer.getType() == IDENTIFIER)
			{
				wordAnalyzer.setSymbol();
				if (wordAnalyzer.getType() == COMMA)
				{
					while (wordAnalyzer.getType() == COMMA)
					{
						wordAnalyzer.setSymbol();
						if (wordAnalyzer.getType() == IDENTIFIER)
						{

						}
						else
						{
							//syntax error,error handlers should be put here!
						}
						wordAnalyzer.setSymbol();
					}
				}
				else if (wordAnalyzer.getType() == RP)
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
	if (wordAnalyzer.getType() == WRITE)
	{
		wordAnalyzer.setSymbol();
		if (wordAnalyzer.getType() == LP)
		{
			wordAnalyzer.setSymbol();
			if (wordAnalyzer.getType() == IDENTIFIER)
			{
				wordAnalyzer.setSymbol();
				if (wordAnalyzer.getType() == COMMA)
				{
					while (wordAnalyzer.getType() == COMMA)
					{
						wordAnalyzer.setSymbol();
						if (wordAnalyzer.getType() == IDENTIFIER)
						{

						}
						else
						{
							//syntax error,error handlers should be put here!
						}
						wordAnalyzer.setSymbol();
					}
				}
				else if (wordAnalyzer.getType() == RP)
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
