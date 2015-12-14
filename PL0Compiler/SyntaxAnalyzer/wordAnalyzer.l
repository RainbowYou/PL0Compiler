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

delim		[ \t\n]
whitespace	{delim}+
letter		[a-z]
digit		[0-9]

const		"const"
var			"var"
procedure	"procedure"
if			"if"
then		"then"
while		"while"
do			"do"
call		"call"
begin		"begin"
end			"end"
read		"read"
write		"write"

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

