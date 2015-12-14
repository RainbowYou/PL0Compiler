%{
/****************************************************************************
syntaxAnalyzer.y
ParserWizard generated YACC file.

Date: 2015Äê12ÔÂ14ÈÕ
****************************************************************************/

#include "wordAnalyzer.h"
%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

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

// place your YACC rules here (there must be at least one)

Grammar
	prog: partProg
	; 
	partProg: sentence
	| constDec sentence
	| constDec varDec sentence
	| constDec varDec proDec sentence 
	;
	constDec: CONST constDef moreoConstDef ';'
	;
	moreConstDef: ',' constDef
	| ',' constDef moreConstDef
	|
	;
	constDef: identifier '=' uint
	;
	uint: digit
	| digit unit
	;
	identifier: letter
	| letter identifier
	| letter digit
	;
	varDec: VAR identifier moreIdentifier ';'
	;
	moreIdentifier: ',' identifier
	|',' identifier moreIdentifier
	|
	;
	proDec: proHead partProg moreProDec ';'
	proHead: PROCEDURE identifier ';'
	moreProDec: ';' proDec
	| ';' proDec moreProDec
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
	assignSen: identifier ':''=' expr
	;
	expr: item moreItem
	| '+' item moreItem
	| '-' item moreItem
	;
	moreItem: addOperator item
	| addOperator item moreItem
	|
	;
	item: factor moreFactor
	;
	factor: identifier
	| uint
	| '(' expr ')'
	;
	moreFactor: mulOperator factor
	| mulOperator factor
	|
	;
	addOperator: '+'
	| '-'
	;
	mulOperator: '*'
	| '/'
	;
	contidition: expr relOperator expr
	| 'o''d''d' expr
	;
	relOperator: '='
	| '<''>'
	| '<'
	| '<''='
	| '>'
	| '>''='
	;
	conditionSen: IF condition THEN sentence
	;
	whileSen: WHILE condition DO sentence
	;
	proCallSen: CALL identifier
	reuniteSen: BEGIN sentence moreSentence END
	;
	moreSentence: ';' sentence
	| ';' sentence moreSentence
	|
	;
	readSen: READ '(' identifier moreIdentifier ')'
	;
	writeSen: WRITE '(' expr moreExpr ')'
	;
	moreExpr: ',' expr
	| ',' expr moreExpr
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

