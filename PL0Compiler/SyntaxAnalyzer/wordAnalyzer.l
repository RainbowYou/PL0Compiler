%{
/****************************************************************************
wordAnalyzer.l
ParserWizard generated Lex file.

Date: 2015Äê12ÔÂ14ÈÕ
****************************************************************************/

#include "syntaxAnalyzer.h"
%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

letter [a-z]
digit  [0-9]

// lexical analyser name
%name wordAnalyzer

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

// place any declarations here

%%

/////////////////////////////////////////////////////////////////////////////
// rules section

%{
	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;
%}

// place your Lex rules here

%%

/////////////////////////////////////////////////////////////////////////////
// programs section

