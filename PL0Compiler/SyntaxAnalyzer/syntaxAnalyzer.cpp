/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 10 of your 30 day trial period.
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
* syntaxAnalyzer.cpp
* C++ source file generated from syntaxAnalyzer.y.
* 
* Date: 12/16/15
* Time: 20:55:23
* 
* AYACC Version: 2.07
****************************************************************************/

#include <yywcpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\syntaxAnalyzer.y"

/*Date: 2015��12��14��*/
#include <iostream>
#include <cstring>
#include "wordAnalyzer.h"

#line 45 "syntaxAnalyzer.cpp"
// repeated because of possible precompiled header
#include <yywcpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\syntaxAnalyzer.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYPARSERNAME::YYPARSERNAME()
{
	yytables();
#line 21 ".\\syntaxAnalyzer.y"

	// place any extra initialisation code here

#line 69 "syntaxAnalyzer.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYPARSERNAME::~YYPARSERNAME()
{
	// allows virtual functions to be called properly for correct cleanup
	yydestroy();
#line 26 ".\\syntaxAnalyzer.y"

	// place any extra cleanup code here

#line 83 "syntaxAnalyzer.cpp"
}

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#ifndef YYSTACK_SIZE
#define YYSTACK_SIZE 100
#endif
#ifndef YYSTACK_MAX
#define YYSTACK_MAX 0
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYPARSERNAME error then you have not declared
* the name of the parser. The easiest way to do this is to use a name
* declaration. This is placed in the declarations section of your YACC
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the parser myparser:
* 
* %name myparser
* 
* For more information see help.
****************************************************************************/

// yyattribute
#ifdef YYDEBUG
void YYFAR* YYPARSERNAME::yyattribute1(int index) const
{
	YYSTYPE YYFAR* p = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + index];
	return p;
}
#define yyattribute(index) (*(YYSTYPE YYFAR*)yyattribute1(index))
#else
#define yyattribute(index) (((YYSTYPE YYFAR*)yyattributestackptr)[yytop + (index)])
#endif

void YYPARSERNAME::yystacktoval(int index)
{
	yyassert(index >= 0);
	*(YYSTYPE YYFAR*)yyvalptr = ((YYSTYPE YYFAR*)yyattributestackptr)[index];
}

void YYPARSERNAME::yyvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltoval()
{
	*(YYSTYPE YYFAR*)yyvalptr = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYPARSERNAME::yyvaltolval()
{
	*(YYSTYPE YYFAR*)yylvalptr = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYFAR* YYPARSERNAME::yynewattribute(int count)
{
	yyassert(count >= 0);
	return new YYFAR YYSTYPE[count];
}

void YYPARSERNAME::yydeleteattribute(void YYFAR* attribute)
{
	delete[] (YYSTYPE YYFAR*)attribute;
}

void YYPARSERNAME::yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count)
{
	for (int i = 0; i < count; i++) {
		((YYSTYPE YYFAR*)dest)[i] = ((YYSTYPE YYFAR*)src)[i];
	}
}

#ifdef YYDEBUG
void YYPARSERNAME::yyinitdebug(void YYFAR** p, int count) const
{
	yyassert(p != NULL);
	yyassert(count >= 1);

	YYSTYPE YYFAR** p1 = (YYSTYPE YYFAR**)p;
	for (int i = 0; i < count; i++) {
		p1[i] = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + i - (count - 1)];
	}
}
#endif

void YYPARSERNAME::yyaction(int action)
{
}

void YYPARSERNAME::yytables()
{
	yyattribute_size = sizeof(YYSTYPE);
	yysstack_size = YYSTACK_SIZE;
	yystack_max = YYSTACK_MAX;

#ifdef YYDEBUG
	static const yywsymbol_t YYNEARFAR YYBASED_CODE symbol[] = {
		{ L"$end", 0 },
		{ L"\'+\'", 43 },
		{ L"\'-\'", 45 },
		{ L"\';\'", 59 },
		{ L"\'=\'", 61 },
		{ L"error", 65536 },
		{ L"IDENTIFIER", 65537 },
		{ L"UINT", 65538 },
		{ L"ADDOPERATOR", 65539 },
		{ L"MULOPERATOR", 65540 },
		{ L"RELOPERATOR", 65541 },
		{ L"CONST", 65542 },
		{ L"VAR", 65543 },
		{ L"PROCEDURE", 65544 },
		{ L"ODD", 65545 },
		{ L"IF", 65546 },
		{ L"THEN", 65547 },
		{ L"WHILE", 65548 },
		{ L"DO", 65549 },
		{ L"CALL", 65550 },
		{ L"BEGIN", 65551 },
		{ L"END", 65552 },
		{ L"READ", 65553 },
		{ L"WRITE", 65554 },
		{ L"COMMA", 65555 },
		{ L"SEMICOLON", 65556 },
		{ L"ASSIGN", 65558 },
		{ L"LP", 65561 },
		{ L"RP", 65562 },
		{ NULL, 0 }
	};
	yysymbol = symbol;

	static const wchar_t* const YYNEARFAR YYBASED_CODE rule[] = {
		L"$accept: prog",
		L"prog: partProg",
		L"partProg: sentence",
		L"partProg: constDec sentence",
		L"partProg: constDec varDec sentence",
		L"partProg: constDec varDec proDec sentence",
		L"constDec: CONST constDef moreConstDef \';\'",
		L"moreConstDef: COMMA constDef",
		L"moreConstDef: COMMA constDef moreConstDef",
		L"moreConstDef:",
		L"constDef: IDENTIFIER \'=\' UINT",
		L"varDec: VAR IDENTIFIER moreIdentifier \';\'",
		L"moreIdentifier: COMMA IDENTIFIER",
		L"moreIdentifier: COMMA IDENTIFIER moreIdentifier",
		L"moreIdentifier:",
		L"proDec: proHead partProg moreProDec \';\'",
		L"proHead: PROCEDURE IDENTIFIER \';\'",
		L"moreProDec: \';\' proDec",
		L"moreProDec: \';\' proDec moreProDec",
		L"moreProDec:",
		L"sentence: assignSen",
		L"sentence: conditionSen",
		L"sentence: whileSen",
		L"sentence: proCallSen",
		L"sentence: reuniteSen",
		L"sentence: readSen",
		L"sentence: writeSen",
		L"sentence:",
		L"assignSen: IDENTIFIER ASSIGN expr",
		L"expr: item moreItem",
		L"expr: \'+\' item moreItem",
		L"expr: \'-\' item moreItem",
		L"moreItem: ADDOPERATOR item",
		L"moreItem: ADDOPERATOR item moreItem",
		L"moreItem:",
		L"item: factor moreFactor",
		L"factor: IDENTIFIER",
		L"factor: UINT",
		L"factor: LP expr RP",
		L"moreFactor: MULOPERATOR factor",
		L"moreFactor: MULOPERATOR factor moreFactor",
		L"moreFactor:",
		L"condition: expr RELOPERATOR expr",
		L"condition: ODD expr",
		L"conditionSen: IF condition THEN sentence",
		L"whileSen: WHILE condition DO sentence",
		L"proCallSen: CALL IDENTIFIER",
		L"reuniteSen: BEGIN sentence moreSentence END",
		L"moreSentence: SEMICOLON sentence",
		L"moreSentence: SEMICOLON sentence moreSentence",
		L"moreSentence:",
		L"readSen: READ LP IDENTIFIER moreIdentifier RP",
		L"writeSen: WRITE LP expr moreExpr RP",
		L"moreExpr: COMMA expr",
		L"moreExpr: COMMA expr moreExpr",
		L"moreExpr:"
	};
	yyrule = rule;
#endif

	static const yywreduction_t YYNEARFAR YYBASED_CODE reduction[] = {
		{ 0, 1, -1 },
		{ 1, 1, -1 },
		{ 2, 1, -1 },
		{ 2, 2, -1 },
		{ 2, 3, -1 },
		{ 2, 4, -1 },
		{ 3, 4, -1 },
		{ 4, 2, -1 },
		{ 4, 3, -1 },
		{ 4, 0, -1 },
		{ 5, 3, -1 },
		{ 6, 4, -1 },
		{ 7, 2, -1 },
		{ 7, 3, -1 },
		{ 7, 0, -1 },
		{ 8, 4, -1 },
		{ 9, 3, -1 },
		{ 10, 2, -1 },
		{ 10, 3, -1 },
		{ 10, 0, -1 },
		{ 11, 1, -1 },
		{ 11, 1, -1 },
		{ 11, 1, -1 },
		{ 11, 1, -1 },
		{ 11, 1, -1 },
		{ 11, 1, -1 },
		{ 11, 1, -1 },
		{ 11, 0, -1 },
		{ 12, 3, -1 },
		{ 13, 2, -1 },
		{ 13, 3, -1 },
		{ 13, 3, -1 },
		{ 14, 2, -1 },
		{ 14, 3, -1 },
		{ 14, 0, -1 },
		{ 15, 2, -1 },
		{ 16, 1, -1 },
		{ 16, 1, -1 },
		{ 16, 3, -1 },
		{ 17, 2, -1 },
		{ 17, 3, -1 },
		{ 17, 0, -1 },
		{ 18, 3, -1 },
		{ 18, 2, -1 },
		{ 19, 4, -1 },
		{ 20, 4, -1 },
		{ 21, 2, -1 },
		{ 22, 4, -1 },
		{ 23, 2, -1 },
		{ 23, 3, -1 },
		{ 23, 0, -1 },
		{ 24, 5, -1 },
		{ 25, 5, -1 },
		{ 26, 2, -1 },
		{ 26, 3, -1 },
		{ 26, 0, -1 }
	};
	yyreduction = reduction;

	yytokenaction_size = 115;

	static const yywtokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 64, YYAT_SHIFT, 1 },
		{ 100, YYAT_SHIFT, 96 },
		{ 97, YYAT_SHIFT, 101 },
		{ 103, YYAT_SHIFT, 25 },
		{ 103, YYAT_SHIFT, 26 },
		{ 64, YYAT_SHIFT, 2 },
		{ 80, YYAT_SHIFT, 23 },
		{ 96, YYAT_SHIFT, 61 },
		{ 80, YYAT_SHIFT, 24 },
		{ 64, YYAT_SHIFT, 3 },
		{ 92, YYAT_SHIFT, 80 },
		{ 64, YYAT_SHIFT, 4 },
		{ 40, YYAT_SHIFT, 1 },
		{ 64, YYAT_SHIFT, 5 },
		{ 64, YYAT_SHIFT, 6 },
		{ 90, YYAT_SHIFT, 78 },
		{ 64, YYAT_SHIFT, 7 },
		{ 64, YYAT_SHIFT, 8 },
		{ 53, YYAT_ERROR, 0 },
		{ 40, YYAT_SHIFT, 61 },
		{ 53, YYAT_ERROR, 0 },
		{ 40, YYAT_SHIFT, 3 },
		{ 83, YYAT_SHIFT, 95 },
		{ 40, YYAT_SHIFT, 4 },
		{ 11, YYAT_SHIFT, 1 },
		{ 40, YYAT_SHIFT, 5 },
		{ 40, YYAT_SHIFT, 6 },
		{ 103, YYAT_SHIFT, 28 },
		{ 40, YYAT_SHIFT, 7 },
		{ 40, YYAT_SHIFT, 8 },
		{ 11, YYAT_SHIFT, 38 },
		{ 82, YYAT_SHIFT, 94 },
		{ 81, YYAT_SHIFT, 93 },
		{ 11, YYAT_SHIFT, 3 },
		{ 0, YYAT_SHIFT, 1 },
		{ 11, YYAT_SHIFT, 4 },
		{ 79, YYAT_SHIFT, 91 },
		{ 11, YYAT_SHIFT, 5 },
		{ 11, YYAT_SHIFT, 6 },
		{ 0, YYAT_SHIFT, 2 },
		{ 11, YYAT_SHIFT, 7 },
		{ 11, YYAT_SHIFT, 8 },
		{ 78, YYAT_SHIFT, 90 },
		{ 0, YYAT_SHIFT, 3 },
		{ 62, YYAT_SHIFT, 1 },
		{ 0, YYAT_SHIFT, 4 },
		{ 76, YYAT_SHIFT, 56 },
		{ 0, YYAT_SHIFT, 5 },
		{ 0, YYAT_SHIFT, 6 },
		{ 74, YYAT_SHIFT, 53 },
		{ 0, YYAT_SHIFT, 7 },
		{ 0, YYAT_SHIFT, 8 },
		{ 72, YYAT_SHIFT, 50 },
		{ 62, YYAT_SHIFT, 3 },
		{ 56, YYAT_SHIFT, 1 },
		{ 62, YYAT_SHIFT, 4 },
		{ 66, YYAT_SHIFT, 43 },
		{ 62, YYAT_SHIFT, 5 },
		{ 62, YYAT_SHIFT, 6 },
		{ 61, YYAT_SHIFT, 83 },
		{ 62, YYAT_SHIFT, 7 },
		{ 62, YYAT_SHIFT, 8 },
		{ 60, YYAT_SHIFT, 78 },
		{ 56, YYAT_SHIFT, 3 },
		{ 55, YYAT_SHIFT, 1 },
		{ 56, YYAT_SHIFT, 4 },
		{ 59, YYAT_SHIFT, 80 },
		{ 56, YYAT_SHIFT, 5 },
		{ 56, YYAT_SHIFT, 6 },
		{ 58, YYAT_SHIFT, 78 },
		{ 56, YYAT_SHIFT, 7 },
		{ 56, YYAT_SHIFT, 8 },
		{ 57, YYAT_SHIFT, 77 },
		{ 55, YYAT_SHIFT, 3 },
		{ 52, YYAT_SHIFT, 1 },
		{ 55, YYAT_SHIFT, 4 },
		{ 48, YYAT_SHIFT, 70 },
		{ 55, YYAT_SHIFT, 5 },
		{ 55, YYAT_SHIFT, 6 },
		{ 46, YYAT_SHIFT, 50 },
		{ 55, YYAT_SHIFT, 7 },
		{ 55, YYAT_SHIFT, 8 },
		{ 45, YYAT_SHIFT, 50 },
		{ 52, YYAT_SHIFT, 3 },
		{ 6, YYAT_SHIFT, 1 },
		{ 52, YYAT_SHIFT, 4 },
		{ 44, YYAT_SHIFT, 67 },
		{ 52, YYAT_SHIFT, 5 },
		{ 52, YYAT_SHIFT, 6 },
		{ 43, YYAT_SHIFT, 21 },
		{ 52, YYAT_SHIFT, 7 },
		{ 52, YYAT_SHIFT, 8 },
		{ 42, YYAT_SHIFT, 65 },
		{ 6, YYAT_SHIFT, 3 },
		{ 38, YYAT_SHIFT, 60 },
		{ 6, YYAT_SHIFT, 4 },
		{ 36, YYAT_SHIFT, 58 },
		{ 6, YYAT_SHIFT, 5 },
		{ 6, YYAT_SHIFT, 6 },
		{ 35, YYAT_SHIFT, 56 },
		{ 6, YYAT_SHIFT, 7 },
		{ 6, YYAT_SHIFT, 8 },
		{ 33, YYAT_SHIFT, 55 },
		{ 32, YYAT_SHIFT, 53 },
		{ 31, YYAT_SHIFT, 52 },
		{ 30, YYAT_SHIFT, 50 },
		{ 29, YYAT_SHIFT, 49 },
		{ 22, YYAT_SHIFT, 43 },
		{ 21, YYAT_SHIFT, 42 },
		{ 9, YYAT_ACCEPT, 0 },
		{ 8, YYAT_SHIFT, 37 },
		{ 7, YYAT_SHIFT, 36 },
		{ 5, YYAT_SHIFT, 34 },
		{ 4, YYAT_SHIFT, 27 },
		{ 1, YYAT_SHIFT, 20 }
	};
	yytokenaction = tokenaction;

	static const yywstateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ -65503, 1, YYAT_REDUCE, 27 },
		{ -65444, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 43 },
		{ 0, 0, YYAT_DEFAULT, 4 },
		{ -65432, 1, YYAT_DEFAULT, 80 },
		{ -65425, 1, YYAT_ERROR, 0 },
		{ -65453, 1, YYAT_REDUCE, 27 },
		{ -65450, 1, YYAT_ERROR, 0 },
		{ -65451, 1, YYAT_ERROR, 0 },
		{ 109, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 2 },
		{ -65513, 1, YYAT_REDUCE, 27 },
		{ 0, 0, YYAT_REDUCE, 1 },
		{ 0, 0, YYAT_REDUCE, 20 },
		{ 0, 0, YYAT_REDUCE, 21 },
		{ 0, 0, YYAT_REDUCE, 22 },
		{ 0, 0, YYAT_REDUCE, 25 },
		{ 0, 0, YYAT_REDUCE, 26 },
		{ 0, 0, YYAT_REDUCE, 24 },
		{ 0, 0, YYAT_REDUCE, 23 },
		{ 0, 0, YYAT_DEFAULT, 80 },
		{ 47, 1, YYAT_ERROR, 0 },
		{ -65448, 1, YYAT_REDUCE, 9 },
		{ 0, 0, YYAT_DEFAULT, 53 },
		{ 0, 0, YYAT_DEFAULT, 53 },
		{ 0, 0, YYAT_REDUCE, 36 },
		{ 0, 0, YYAT_REDUCE, 37 },
		{ 0, 0, YYAT_DEFAULT, 80 },
		{ 0, 0, YYAT_DEFAULT, 80 },
		{ -65435, 1, YYAT_ERROR, 0 },
		{ -65434, 1, YYAT_REDUCE, 34 },
		{ -65443, 1, YYAT_ERROR, 0 },
		{ -65437, 1, YYAT_REDUCE, 41 },
		{ -65447, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 46 },
		{ -65457, 1, YYAT_REDUCE, 50 },
		{ -65441, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 80 },
		{ -65443, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 3 },
		{ -65525, 1, YYAT_REDUCE, 27 },
		{ 0, 0, YYAT_REDUCE, 28 },
		{ -65446, 1, YYAT_ERROR, 0 },
		{ -65448, 1, YYAT_ERROR, 0 },
		{ 27, 1, YYAT_ERROR, 0 },
		{ -65457, 1, YYAT_REDUCE, 34 },
		{ -65460, 1, YYAT_REDUCE, 34 },
		{ 0, 0, YYAT_REDUCE, 43 },
		{ -65486, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 80 },
		{ 0, 0, YYAT_DEFAULT, 53 },
		{ 0, 0, YYAT_REDUCE, 29 },
		{ -65463, 1, YYAT_REDUCE, 27 },
		{ -25, 1, YYAT_DEFAULT, 80 },
		{ 0, 0, YYAT_REDUCE, 35 },
		{ -65473, 1, YYAT_REDUCE, 27 },
		{ -65483, 1, YYAT_REDUCE, 27 },
		{ -65480, 1, YYAT_ERROR, 0 },
		{ -65486, 1, YYAT_REDUCE, 14 },
		{ -65489, 1, YYAT_REDUCE, 55 },
		{ -65493, 1, YYAT_REDUCE, 14 },
		{ -65478, 1, YYAT_ERROR, 0 },
		{ -65493, 1, YYAT_REDUCE, 27 },
		{ 0, 0, YYAT_REDUCE, 4 },
		{ -65537, 1, YYAT_REDUCE, 27 },
		{ 0, 0, YYAT_REDUCE, 10 },
		{ -65499, 1, YYAT_REDUCE, 7 },
		{ 0, 0, YYAT_REDUCE, 6 },
		{ 0, 0, YYAT_REDUCE, 30 },
		{ 0, 0, YYAT_REDUCE, 31 },
		{ 0, 0, YYAT_REDUCE, 38 },
		{ 0, 0, YYAT_REDUCE, 42 },
		{ -65487, 1, YYAT_REDUCE, 32 },
		{ 0, 0, YYAT_REDUCE, 44 },
		{ -65491, 1, YYAT_REDUCE, 39 },
		{ 0, 0, YYAT_REDUCE, 45 },
		{ -65510, 1, YYAT_REDUCE, 48 },
		{ 0, 0, YYAT_REDUCE, 47 },
		{ -65495, 1, YYAT_ERROR, 0 },
		{ -65526, 1, YYAT_ERROR, 0 },
		{ -37, 1, YYAT_DEFAULT, 103 },
		{ -65530, 1, YYAT_ERROR, 0 },
		{ -28, 1, YYAT_ERROR, 0 },
		{ -37, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 5 },
		{ 0, 0, YYAT_DEFAULT, 100 },
		{ 0, 0, YYAT_REDUCE, 8 },
		{ 0, 0, YYAT_REDUCE, 33 },
		{ 0, 0, YYAT_REDUCE, 40 },
		{ 0, 0, YYAT_REDUCE, 49 },
		{ -65540, 1, YYAT_REDUCE, 12 },
		{ 0, 0, YYAT_REDUCE, 51 },
		{ -65545, 1, YYAT_REDUCE, 53 },
		{ 0, 0, YYAT_REDUCE, 52 },
		{ 0, 0, YYAT_REDUCE, 11 },
		{ 0, 0, YYAT_REDUCE, 16 },
		{ -65537, 1, YYAT_ERROR, 0 },
		{ -57, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ 0, 0, YYAT_REDUCE, 54 },
		{ -58, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 15 },
		{ 0, 0, YYAT_REDUCE, 18 },
		{ -65534, 1, YYAT_ERROR, 0 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 60;

	static const yywnontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 64, 85 },
		{ 64, 11 },
		{ 62, -1 },
		{ 62, -1 },
		{ 40, 62 },
		{ 40, 64 },
		{ 100, 102 },
		{ 40, 63 },
		{ 11, 40 },
		{ 64, 10 },
		{ 64, 13 },
		{ 62, 84 },
		{ 80, 92 },
		{ 11, 39 },
		{ 80, 30 },
		{ 92, 99 },
		{ 4, 29 },
		{ 64, 14 },
		{ 64, 15 },
		{ 64, 19 },
		{ 64, 18 },
		{ 4, 33 },
		{ 64, 16 },
		{ 64, 17 },
		{ 96, 100 },
		{ 96, 64 },
		{ 50, 72 },
		{ 50, 32 },
		{ 0, 9 },
		{ 0, 12 },
		{ 90, 98 },
		{ 85, 97 },
		{ 76, 89 },
		{ 74, 88 },
		{ 72, 87 },
		{ 66, 86 },
		{ 60, 82 },
		{ 59, 81 },
		{ 58, 79 },
		{ 56, 76 },
		{ 55, 75 },
		{ 53, 74 },
		{ 52, 73 },
		{ 49, 71 },
		{ 46, 69 },
		{ 45, 68 },
		{ 43, 66 },
		{ 37, 59 },
		{ 35, 57 },
		{ 32, 54 },
		{ 30, 51 },
		{ 28, 48 },
		{ 27, 47 },
		{ 24, 46 },
		{ 23, 45 },
		{ 22, 44 },
		{ 20, 41 },
		{ 6, 35 },
		{ 3, 31 },
		{ 2, 22 }
	};
	yynontermgoto = nontermgoto;

	static const yywstategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ 27, 64 },
		{ 0, -1 },
		{ 54, -1 },
		{ 40, 4 },
		{ 3, 80 },
		{ 0, -1 },
		{ 46, 62 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 2, 62 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 43, 80 },
		{ 0, -1 },
		{ 51, -1 },
		{ 39, 50 },
		{ 38, 50 },
		{ 0, -1 },
		{ 0, -1 },
		{ 39, 80 },
		{ 38, 80 },
		{ 0, -1 },
		{ 36, -1 },
		{ 0, -1 },
		{ 32, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 25, -1 },
		{ 0, -1 },
		{ 34, 80 },
		{ 0, -1 },
		{ 0, -1 },
		{ -4, 62 },
		{ 0, -1 },
		{ 0, -1 },
		{ 41, -1 },
		{ 0, -1 },
		{ 31, -1 },
		{ 30, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 30, 80 },
		{ 11, -1 },
		{ 0, -1 },
		{ 31, 62 },
		{ 25, -1 },
		{ 0, -1 },
		{ 29, 62 },
		{ 28, 62 },
		{ 0, -1 },
		{ 31, -1 },
		{ 11, -1 },
		{ 29, -1 },
		{ 0, -1 },
		{ 0, 64 },
		{ 0, -1 },
		{ -2, -1 },
		{ 0, -1 },
		{ 31, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 20, -1 },
		{ 0, -1 },
		{ 16, -1 },
		{ 0, -1 },
		{ 9, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -1, 50 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 21, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 23, -1 },
		{ 0, -1 },
		{ -11, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 16, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -4, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 }
	};
	yystategoto = stategoto;

	yydestructorptr = NULL;

	yytokendestptr = NULL;
	yytokendest_size = 0;

	yytokendestbaseptr = NULL;
	yytokendestbase_size = 0;
}
#line 129 ".\\syntaxAnalyzer.y"


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


