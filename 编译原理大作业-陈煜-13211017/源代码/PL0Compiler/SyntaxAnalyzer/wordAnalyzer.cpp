/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 11 of your 30 day trial period.
* 
* This file was produced by an UNREGISTERED COPY of Parser Generator. It is
* for evaluation purposes only. If you continue to use Parser Generator 30
* days after installation then you are required to purchase a license. For
* more information see the online help or go to the Bumble-Bee Software
* homepage at:
* 
* http://www.bumblebeesoftware.com
* 
* This notice must remain present in the file. It cannot be removed.
****************************************************************************/

/****************************************************************************
* wordAnalyzer.cpp
* C++ source file generated from wordAnalyzer.l.
* 
* Date: 12/16/15
* Time: 21:53:01
* 
* ALex Version: 2.07
****************************************************************************/

#include <yywclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\wordAnalyzer.l"

/*Date: 2015��12��14��*/
#include <iostream>
#include <cstring>
#include "syntaxAnalyzer.h"

#line 45 "wordAnalyzer.cpp"
// repeated because of possible precompiled header
#include <yywclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\wordAnalyzer.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYLEXERNAME::YYLEXERNAME()
{
	yytables();
#line 30 ".\\wordAnalyzer.l"

	// place any extra initialisation code here

#line 69 "wordAnalyzer.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYLEXERNAME::~YYLEXERNAME()
{
#line 35 ".\\wordAnalyzer.l"

	// place any extra cleanup code here

#line 81 "wordAnalyzer.cpp"
}

#ifndef YYTEXT_SIZE
#define YYTEXT_SIZE 100
#endif
#ifndef YYUNPUT_SIZE
#define YYUNPUT_SIZE YYTEXT_SIZE
#endif
#ifndef YYTEXT_MAX
#define YYTEXT_MAX 0
#endif
#ifndef YYUNPUT_MAX
#define YYUNPUT_MAX YYTEXT_MAX
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYLEXERNAME error then you have not declared
* the name of the lexical analyser. The easiest way to do this is to use a
* name declaration. This is placed in the declarations section of your Lex
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the lexer mylexer:
* 
* %name mylexer
* 
* For more information see help.
****************************************************************************/

// backwards compatability with lex
#ifdef input
yywint_t YYLEXERNAME::yyinput()
{
	return input();
}
#else
#define input yyinput
#endif

#ifdef output
void YYLEXERNAME::yyoutput(yywint_t ch)
{
	output(ch);
}
#else
#define output yyoutput
#endif

#ifdef unput
void YYLEXERNAME::yyunput(yywint_t ch)
{
	unput(ch);
}
#else
#define unput yyunput
#endif

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn -rch		// <warning: unreachable code> off
#endif
#endif

yywint_t YYLEXERNAME::yyaction(int action)
{
#line 45 ".\\wordAnalyzer.l"

	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;

#line 152 "wordAnalyzer.cpp"
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 51 ".\\wordAnalyzer.l"
/*yylval=installNumber();*/return UINT;
#line 159 "wordAnalyzer.cpp"
		}
		break;
	case 2:
		{
#line 52 ".\\wordAnalyzer.l"
return ADDOPERATOR;
#line 166 "wordAnalyzer.cpp"
		}
		break;
	case 3:
		{
#line 53 ".\\wordAnalyzer.l"
return MULOPERATOR;
#line 173 "wordAnalyzer.cpp"
		}
		break;
	case 4:
		{
#line 54 ".\\wordAnalyzer.l"
return RELOPERATOR;
#line 180 "wordAnalyzer.cpp"
		}
		break;
	case 5:
		{
#line 55 ".\\wordAnalyzer.l"

#line 187 "wordAnalyzer.cpp"
		}
		break;
	case 6:
		{
#line 57 ".\\wordAnalyzer.l"
return CONST;
#line 194 "wordAnalyzer.cpp"
		}
		break;
	case 7:
		{
#line 58 ".\\wordAnalyzer.l"
return VAR;
#line 201 "wordAnalyzer.cpp"
		}
		break;
	case 8:
		{
#line 59 ".\\wordAnalyzer.l"
return	PROCEDURE;
#line 208 "wordAnalyzer.cpp"
		}
		break;
	case 9:
		{
#line 60 ".\\wordAnalyzer.l"
return ODD;
#line 215 "wordAnalyzer.cpp"
		}
		break;
	case 10:
		{
#line 61 ".\\wordAnalyzer.l"
return IF;
#line 222 "wordAnalyzer.cpp"
		}
		break;
	case 11:
		{
#line 62 ".\\wordAnalyzer.l"
return THEN;
#line 229 "wordAnalyzer.cpp"
		}
		break;
	case 12:
		{
#line 63 ".\\wordAnalyzer.l"
return WHILE;
#line 236 "wordAnalyzer.cpp"
		}
		break;
	case 13:
		{
#line 64 ".\\wordAnalyzer.l"
return DO;
#line 243 "wordAnalyzer.cpp"
		}
		break;
	case 14:
		{
#line 65 ".\\wordAnalyzer.l"
return CALL;
#line 250 "wordAnalyzer.cpp"
		}
		break;
	case 15:
		{
#line 66 ".\\wordAnalyzer.l"
return BEGIN;
#line 257 "wordAnalyzer.cpp"
		}
		break;
	case 16:
		{
#line 67 ".\\wordAnalyzer.l"
return END;
#line 264 "wordAnalyzer.cpp"
		}
		break;
	case 17:
		{
#line 68 ".\\wordAnalyzer.l"
return READ;
#line 271 "wordAnalyzer.cpp"
		}
		break;
	case 18:
		{
#line 69 ".\\wordAnalyzer.l"
return WRITE;
#line 278 "wordAnalyzer.cpp"
		}
		break;
	case 19:
		{
#line 71 ".\\wordAnalyzer.l"
/*yylval=installID();*/return IDENTIFIER;
#line 285 "wordAnalyzer.cpp"
		}
		break;
	case 20:
		{
#line 73 ".\\wordAnalyzer.l"
return COMMA;
#line 292 "wordAnalyzer.cpp"
		}
		break;
	case 21:
		{
#line 74 ".\\wordAnalyzer.l"
return SEMICOLON;
#line 299 "wordAnalyzer.cpp"
		}
		break;
	case 22:
		{
#line 75 ".\\wordAnalyzer.l"
return ASSIGN;
#line 306 "wordAnalyzer.cpp"
		}
		break;
	case 23:
		{
#line 76 ".\\wordAnalyzer.l"
return LP;
#line 313 "wordAnalyzer.cpp"
		}
		break;
	case 24:
		{
#line 77 ".\\wordAnalyzer.l"
return RP;
#line 320 "wordAnalyzer.cpp"
		}
		break;
	default:
		yyassert(0);
		break;
	}
	yyreturnflg = yyfalse;
	return 0;
}

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn .rch		// <warning: unreachable code> to the old state
#endif
#endif

void YYLEXERNAME::yytables()
{
	yystext_size = YYTEXT_SIZE;
	yysunput_size = YYUNPUT_SIZE;
	yytext_max = YYTEXT_MAX;
	yyunput_max = YYUNPUT_MAX;

	static const yywmatch_t YYNEARFAR YYBASED_CODE match[] = {
		0
	};
	yymatch = match;

	yytransitionmax = 130;
	static const yywtransition_t YYNEARFAR YYBASED_CODE transition[] = {
		{ 0, 0 },
		{ 3, 1 },
		{ 3, 1 },
		{ 28, 16 },
		{ 3, 4 },
		{ 3, 4 },
		{ 14, 67 },
		{ 14, 67 },
		{ 14, 67 },
		{ 14, 67 },
		{ 14, 67 },
		{ 14, 67 },
		{ 14, 67 },
		{ 14, 67 },
		{ 14, 67 },
		{ 14, 67 },
		{ 30, 17 },
		{ 29, 16 },
		{ 38, 25 },
		{ 31, 18 },
		{ 32, 19 },
		{ 33, 20 },
		{ 34, 21 },
		{ 35, 22 },
		{ 4, 1 },
		{ 36, 23 },
		{ 5, 1 },
		{ 3, 4 },
		{ 39, 25 },
		{ 37, 24 },
		{ 27, 15 },
		{ 40, 27 },
		{ 6, 1 },
		{ 7, 1 },
		{ 8, 1 },
		{ 9, 1 },
		{ 10, 1 },
		{ 9, 1 },
		{ 41, 28 },
		{ 8, 1 },
		{ 11, 1 },
		{ 11, 1 },
		{ 11, 1 },
		{ 11, 1 },
		{ 11, 1 },
		{ 11, 1 },
		{ 11, 1 },
		{ 11, 1 },
		{ 11, 1 },
		{ 11, 1 },
		{ 12, 1 },
		{ 13, 1 },
		{ 5, 1 },
		{ 5, 1 },
		{ 5, 1 },
		{ 14, 67 },
		{ 14, 67 },
		{ 14, 67 },
		{ 14, 67 },
		{ 14, 67 },
		{ 14, 67 },
		{ 14, 67 },
		{ 14, 67 },
		{ 14, 67 },
		{ 14, 67 },
		{ 14, 67 },
		{ 14, 67 },
		{ 14, 67 },
		{ 14, 67 },
		{ 14, 67 },
		{ 14, 67 },
		{ 14, 67 },
		{ 14, 67 },
		{ 14, 67 },
		{ 14, 67 },
		{ 14, 67 },
		{ 14, 67 },
		{ 14, 67 },
		{ 14, 67 },
		{ 14, 67 },
		{ 14, 67 },
		{ 42, 29 },
		{ 43, 31 },
		{ 44, 33 },
		{ 45, 34 },
		{ 46, 35 },
		{ 47, 36 },
		{ 48, 37 },
		{ 49, 38 },
		{ 50, 39 },
		{ 15, 1 },
		{ 16, 1 },
		{ 17, 1 },
		{ 18, 1 },
		{ 51, 40 },
		{ 52, 41 },
		{ 53, 42 },
		{ 19, 1 },
		{ 54, 45 },
		{ 55, 46 },
		{ 56, 47 },
		{ 57, 49 },
		{ 58, 50 },
		{ 20, 1 },
		{ 21, 1 },
		{ 59, 51 },
		{ 22, 1 },
		{ 60, 53 },
		{ 23, 1 },
		{ 61, 54 },
		{ 24, 1 },
		{ 25, 1 },
		{ 62, 57 },
		{ 63, 58 },
		{ 64, 61 },
		{ 65, 64 },
		{ 5, 1 },
		{ 11, 11 },
		{ 11, 11 },
		{ 11, 11 },
		{ 11, 11 },
		{ 11, 11 },
		{ 11, 11 },
		{ 11, 11 },
		{ 11, 11 },
		{ 11, 11 },
		{ 11, 11 },
		{ 66, 65 },
		{ 67, 66 },
		{ 26, 12 }
	};
	yytransition = transition;

	static const yywstate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ 67, -8, 0 },
		{ 1, 0, 0 },
		{ 4, 0, 5 },
		{ 0, -5, 4 },
		{ 0, 0, 4 },
		{ 0, 0, 23 },
		{ 0, 0, 24 },
		{ 0, 0, 3 },
		{ 0, 0, 2 },
		{ 0, 0, 20 },
		{ 0, 69, 1 },
		{ 0, 68, 0 },
		{ 0, 0, 21 },
		{ 67, 0, 19 },
		{ 67, -71, 19 },
		{ 67, -94, 19 },
		{ 67, -95, 19 },
		{ 67, -91, 19 },
		{ 67, -82, 19 },
		{ 67, -79, 19 },
		{ 67, -92, 19 },
		{ 67, -78, 19 },
		{ 67, -79, 19 },
		{ 67, -68, 19 },
		{ 67, -86, 19 },
		{ 0, 0, 22 },
		{ 67, -72, 19 },
		{ 67, -70, 19 },
		{ 67, -29, 19 },
		{ 67, 0, 13 },
		{ 67, -18, 19 },
		{ 67, 0, 10 },
		{ 67, -17, 19 },
		{ 67, -27, 19 },
		{ 67, -12, 19 },
		{ 67, -15, 19 },
		{ 67, -27, 19 },
		{ 67, -17, 19 },
		{ 67, -16, 19 },
		{ 67, -11, 19 },
		{ 67, -13, 19 },
		{ 67, -19, 19 },
		{ 67, 0, 16 },
		{ 67, 0, 9 },
		{ 67, -1, 19 },
		{ 67, -1, 19 },
		{ 67, -10, 19 },
		{ 67, 0, 7 },
		{ 67, -7, 19 },
		{ 67, -14, 19 },
		{ 67, -5, 19 },
		{ 67, 0, 14 },
		{ 67, -9, 19 },
		{ 67, 8, 19 },
		{ 67, 0, 17 },
		{ 67, 0, 11 },
		{ 67, 11, 19 },
		{ 67, 12, 19 },
		{ 67, 0, 15 },
		{ 67, 0, 6 },
		{ 67, 14, 19 },
		{ 67, 0, 12 },
		{ 67, 0, 18 },
		{ 67, -2, 19 },
		{ 67, 13, 19 },
		{ 67, 27, 19 },
		{ 0, -42, 8 }
	};
	yystate = state;

	static const yywbackup_t YYNEARFAR YYBASED_CODE backup[] = {
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	};
	yybackup = backup;
}
#line 79 ".\\wordAnalyzer.l"


int installID()
{
 return 1;
}

int installNumber()
{
 return 1;
}


