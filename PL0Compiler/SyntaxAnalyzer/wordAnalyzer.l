%{
/****************************************************************************
wordAnalyzer.l
ParserWizard generated Lex file.

Date: 2015Äê12ÔÂ14ÈÕ
****************************************************************************/
#include <iostream>
#include <cstring>
#include "syntaxAnalyzer.h"
%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

delim		[ \t\n]
whitespace	{delim}+
letter		[a-z]
digit		[0-9]
unit		{digit}+
identifier	letter{letter|digit}*
addOperator	[\+\-]
mulOperator	[\*\/]
relOperator "="| "<>" | "<" | "<=" | ">" | ">="

const		"const"
var			"var"
procedure	"procedure"
odd			"odd"
if			"if"
then		"then"
while		"while"
do			"do"
call		"call"
begin		"begin"
end			"end"
read		"read"
write		"write"

comma		","
semicolon	";"
equal		"="
assign		":="
plus		"+"
minus		"-"
lp			"("
rp			")"

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
{identifier} {}
{uint} {}
{addOperator} {}
{mulOperator} {}
{relOperator} {}
{whitespace} {}//do nothing

{const} {return CONST;}
{var} {return VAR;}
{procedure} {return	PROCEDURE;}
{odd} {return ODD;}
{if} {return IF;}
{then} {return THEN;}
{while} {return WHILE;}
{do} {return DO;}
{call} {return CALL;}
{begin} {return BEGIN;}
{end} {return END;}
{read} {return READ;}
{write} {return WRITE;}

{comma} {return COMMA;}
{semicolon} {return SEMICOLON;}
{equal} {return EQUAL;}
{assign} {return ASSIGN;}
{plus} {return PLUS;}
{minus} {return MINUS;}
{lp} {return LP;}
{rp} {return RP;}

%%

/////////////////////////////////////////////////////////////////////////////
// programs section

