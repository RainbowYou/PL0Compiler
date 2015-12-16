%{
/*Date: 2015��12��14��*/
#include <iostream>
#include <cstring>
#include "syntaxAnalyzer.h"
%}

// declarations section

delim		[ \t\n]
whitespace	{delim}+
letter		[a-z]
digit		[0-9]
uint		{digit}+
identifier	{letter}({letter}|{digit})*
addOperator	[\+\-]
mulOperator	[\*\/]
relOperator ["="| "<>" | "<" | "<=" | ">" | ">="]


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

// rules section

%{
	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;
%}


{uint} {yylval=installNumber();return UINT;}
{addOperator} {return ADDOPERATOR;}
{mulOperator} {return MULOPERATOR;}
{relOperator} {return RELOPERATOR;}
{whitespace} {}

const {return CONST;}
var {return VAR;}
procedure {return	PROCEDURE;}
odd {return ODD;}
if {return IF;}
then {return THEN;}
while {return WHILE;}
do {return DO;}
call {return CALL;}
begin {return BEGIN;}
end {return END;}
read {return READ;}
write {return WRITE;}

{identifier} {yylval=installID();return IDENTIFIER;}

"," {return COMMA;}
";" {return SEMICOLON;}
":=" {return ASSIGN;}
"(" {return LP;}
")" {return RP;}

%%

int installID()
{
 return 1;
}

int installNumber()
{
 return 1;
}

