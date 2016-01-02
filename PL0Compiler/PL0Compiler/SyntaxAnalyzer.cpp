#include "WordAnalyzer.h"
#include "SyntaxAnalyzer.h"
#include <vector>

#define DEBUG 1

SyntaxAnalyzer::SyntaxAnalyzer()
{
	//setSymbol("");
	setWordAnalyzer();
	tableManager = new SymbolTableManager();
}

SyntaxAnalyzer::~SyntaxAnalyzer()
{
	//delete symbol;
	delete tableManager;
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
	if (wordAnalyzer.getType() == CONST) { constPart(); partialProgram(); }

	else if (wordAnalyzer.getType() == VAR) { varPart(); partialProgram(); }

	else if (wordAnalyzer.getType() == PROCEDURE) procedurePart();

	else { sentence(); partialProgram(); }

	wordAnalyzer.setSymbol();
}

void SyntaxAnalyzer::constPart()
{
	tableManager->setCurrentType(wordAnalyzer.getType());

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

bool SyntaxAnalyzer::identifier(int checkStatus)
{
	if (wordAnalyzer.getType() == IDENTIFIER)
	{
		tableManager->setCurrentName(wordAnalyzer.getToken());

		if (checkStatus)
		{
			if (!tableManager->find(wordAnalyzer.getToken()))
			{
				cout << "identifier " << wordAnalyzer.getToken() << " not declared!" << endl;
			}
		}

		wordAnalyzer.setSymbol();
		return true;
	}
	else
	{ 
		//If not valid identifier ,pointer still move to next symbol
		wordAnalyzer.setSymbol();
	}

	return false;
}

void SyntaxAnalyzer::constDef()
{
	identifier(0);
	if (wordAnalyzer.getType() == RELATIONO && wordAnalyzer.getToken() == "=")
	{
		wordAnalyzer.setSymbol();
		if (wordAnalyzer.getType() == UINT)
		{
			tableManager->setCurrentValue(wordAnalyzer.getToken());
			wordAnalyzer.setSymbol();

			//Filling symbol table
			if ((tableManager->getCurrentName()) != " ") 
				tableManager->insert(new SymbolTable(tableManager->getCurrentName(),
													tableManager->getCurrentType(),
													tableManager->getCurrentValue(),
													tableManager->getCurrentLevel()));
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
	tableManager->setCurrentType(wordAnalyzer.getType());

	wordAnalyzer.setSymbol();
	identifier(0);

	if ((tableManager->getCurrentName()) != " ")
		tableManager->insert(new SymbolTable(tableManager->getCurrentName(),
		tableManager->getCurrentType(),
		tableManager->getCurrentValue(),
		tableManager->getCurrentLevel(),
		tableManager->getCurrentOffset()));

	while (wordAnalyzer.getType() == COMMA)
	{
		wordAnalyzer.setSymbol();
		identifier(0);
		tableManager->increaseOffset();
		if ((tableManager->getCurrentName()) != " ")
			tableManager->insert(new SymbolTable(tableManager->getCurrentName(),
												tableManager->getCurrentType(),
												tableManager->getCurrentValue(),
												tableManager->getCurrentLevel(),
												tableManager->getCurrentOffset()));
	}
	tableManager->setCurrentOffset(3);

	if (wordAnalyzer.getType()==SEMICOLON)
	{
				
	}
	else
	{
		//syntax error,error handlers should be put here!
	}
#if DEBUG 1
	printSymbleTable();
#endif
}

void SyntaxAnalyzer::procedurePart()
{
	tableManager->setCurrentType(wordAnalyzer.getType());
	
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

	identifier(0);
	if (wordAnalyzer.getType() == SEMICOLON)
	{
		if ((tableManager->getCurrentName()) != " ")
			tableManager->insert(new SymbolTable(tableManager->getCurrentName(),
												tableManager->getCurrentType(),
												tableManager->getCurrentValue(),
												tableManager->getCurrentLevel()));
		tableManager->increaseLevel();
		wordAnalyzer.setSymbol();
		partialProgram();
		tableManager->decreaseLevel();
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
	if (!tableManager->find(wordAnalyzer.getToken()))
	{
		cout << "identifier " << wordAnalyzer.getToken() << " not declared!" << endl;
	}
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
		if (!tableManager->find(wordAnalyzer.getToken()))
		{
			cout << "identifier " << wordAnalyzer.getToken() << " not declared!" << endl;
		}
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
		if (!tableManager->find(wordAnalyzer.getToken()))
		{
			cout << "identifier " << wordAnalyzer.getToken() << " not declared!" << endl;
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
		identifier(1);
		while (wordAnalyzer.getType() == COMMA)
		{
			wordAnalyzer.setSymbol();
			identifier(1);
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
		identifier(1);
		while (wordAnalyzer.getType() == COMMA)
		{
			wordAnalyzer.setSymbol();
			identifier(1);
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

void SyntaxAnalyzer::printSymbleTable()
{
	cout << "\nPrinting Symbol Table...\n";
	cout << "\t名字" << "\t类型" << "\t值" << "\t层次" << "\t偏移" << endl;
	stack<SymbolTable*> ts = tableManager->getSymbolTable();
	int len = ts.size();
	for (int i = 0; i < len; i++)
	{
		SymbolTable* t = ts.top();
		cout << "\t" << t->getName() << "\t" << t->getKind() << "\t" << t->getValue() << "\t"
			<< t->getLevel() << "\t" << t->getAddress() << " \n";
		ts.pop();
	}
	cout << endl;
}
