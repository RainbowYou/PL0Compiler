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
* syntaxAnalyzer.h
* C++ header file generated from syntaxAnalyzer.y.
* 
* Date: 12/16/15
* Time: 21:21:59
* 
* AYACC Version: 2.07
****************************************************************************/

#ifndef _SYNTAXANALYZER_H
#define _SYNTAXANALYZER_H

#include <yywcpars.h>

#define IDENTIFIER 65537
#define UINT 65538
#define ADDOPERATOR 65539
#define MULOPERATOR 65540
#define RELOPERATOR 65541
#define CONST 65542
#define VAR 65543
#define PROCEDURE 65544
#define ODD 65545
#define IF 65546
#define THEN 65547
#define WHILE 65548
#define DO 65549
#define CALL 65550
#define BEGIN 65551
#define END 65552
#define READ 65553
#define WRITE 65554
#define COMMA 65555
#define SEMICOLON 65556
#define EQUAL 65557
#define ASSIGN 65558
#define PLUS 65559
#define MINUS 65560
#define LP 65561
#define RP 65562
/////////////////////////////////////////////////////////////////////////////
// syntaxAnalyzer

#ifndef YYEXPPARSER
#define YYEXPPARSER
#endif

class YYEXPPARSER YYFAR syntaxAnalyzer : public _YL yywfparser {
public:
	syntaxAnalyzer();
	virtual ~syntaxAnalyzer();

protected:
	void yytables();
	virtual void yyaction(int action);
#ifdef YYDEBUG
	void YYFAR* yyattribute1(int index) const;
	void yyinitdebug(void YYFAR** p, int count) const;
#endif

	// attribute functions
	virtual void yystacktoval(int index);
	virtual void yyvaltostack(int index);
	virtual void yylvaltoval();
	virtual void yyvaltolval();
	virtual void yylvaltostack(int index);

	virtual void YYFAR* yynewattribute(int count);
	virtual void yydeleteattribute(void YYFAR* attribute);
	virtual void yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count);

public:
#line 16 ".\\syntaxAnalyzer.y"

	// place any extra class members here

#line 95 "syntaxAnalyzer.h"
};

#ifndef YYPARSERNAME
#define YYPARSERNAME syntaxAnalyzer
#endif

#line 31 ".\\syntaxAnalyzer.y"

#ifndef YYSTYPE
#define YYSTYPE int
#endif

#line 108 "syntaxAnalyzer.h"
#endif
