%{
/****************************************************************************
syntaxAnalyzer.y
ParserWizard generated YACC file.

Date: 2015Äê12ÔÂ14ÈÕ
****************************************************************************/
#include <iostream>
#include <cstring>
#include "wordAnalyzer.h"
%}

/////////////////////////////////////////////////////////////////////////////
// declarations section
%token IDENTIFIER UINT DIGIT LETTER ADDOPERATOR MULOPERATOR RELOPERATOR 
		CONST VAR PROCEDURE ODD IF THEN WHILE DO CALL BEGIN END READ WRITE
		COMMA SEMICOLON EQUAL ASSIGN PLUS MINUS LP RP
// parser name
%name syntaxAnalyzer

// class definition
{
	// place any extra class members here
}

// constructor
{
	// place any extra initialisation code here
}

// destructor
{
	// place any extra cleanup code here
}

// attribute type
%include {
#ifndef YYSTYPE
#define YYSTYPE int
#endif
}

// place any declarations here

%%

/////////////////////////////////////////////////////////////////////////////
// rules section

// YACC Rules

Grammar
	prog: partProg
	; 
	partProg: sentence
	| constDec sentence
	| constDec varDec sentence
	| constDec varDec proDec sentence 
	;
	constDec: CONST constDef moreoConstDef SEMICOLON
	;
	moreConstDef: COMMA constDef
	| COMMA constDef moreConstDef
	|
	;
	constDef: IDENTIFIER EQUAL UINT {$$=$3;}
	;
	varDec: VAR IDENTIFIER moreIdentifier SEMICOLON
	;
	moreIdentifier: COMMA IDENTIFIER
	|COMMA IDENTIFIER moreIdentifier
	|
	;
	proDec: proHead partProg moreProDec SEMICOLON
	proHead: PROCEDURE IDENTIFIER SEMICOLON
	moreProDec: SEMICOLON proDec
	| SEMICOLON proDec moreProDec
	|
	;
	sentence: assignSen
	| conditionSen
	| whileSen
	| proCallSen
	| reuniteSen
	| readSen
	| writeSen
	|
	;
	assignSen: IDENTIFIER ASSIGN expr {$1=$3;}
	;
	expr: item moreItem
	| PLUS item moreItem
	| MINUS item moreItem
	;
	moreItem: ADDOPERATOR item
	| ADDOPERATOR item moreItem
	|
	;
	item: factor moreFactor
	;
	factor: IDENTIFIER
	| UINT
	| LP expr RP
	;
	moreFactor: MULOPERATOR factor
	| MULOPERATOR factor
	|
	;
	contidition: expr RELOPERATOR expr
	| ODD expr
	;
	conditionSen: IF condition THEN sentence
	;
	whileSen: WHILE condition DO sentence
	;
	proCallSen: CALL IDENTIFIER
	reuniteSen: BEGIN sentence moreSentence END
	;
	moreSentence: SEMICOLON sentence
	| SEMICOLON sentence moreSentence
	|
	;
	readSen: READ LP IDENTIFIER moreIdentifier RP
	;
	writeSen: WRITE LP expr moreExpr RP
	;
	moreExpr: COMMA expr
	| COMMA expr moreExpr
	|
	;
	

%%

/////////////////////////////////////////////////////////////////////////////
// programs section

int main(void)
{
	int n = 1;
	wordAnalyzer lexer;
	syntaxAnalyzer parser;
	if (parser.yycreate(&lexer)) {
		if (lexer.yycreate(&parser)) {
			n = parser.yyparse();
		}
	}
	return n;
}

void yyerror(char* s)
{
	fprintf(stderr,"%s\n",s);
}

int yywrap()
{
	return 1;
}

