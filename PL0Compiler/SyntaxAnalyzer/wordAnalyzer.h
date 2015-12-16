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
* wordAnalyzer.h
* C++ header file generated from wordAnalyzer.l.
* 
* Date: 12/16/15
* Time: 20:55:23
* 
* ALex Version: 2.07
****************************************************************************/

#ifndef _WORDANALYZER_H
#define _WORDANALYZER_H

#include <yywclex.h>

/////////////////////////////////////////////////////////////////////////////
// wordAnalyzer

#ifndef YYEXPLEXER
#define YYEXPLEXER
#endif

class YYEXPLEXER YYFAR wordAnalyzer : public _YL yywflexer {
public:
	wordAnalyzer();
	virtual ~wordAnalyzer();

	// backards compatibility with lex
#ifdef input
	virtual _YL yywint_t yyinput();
#endif
#ifdef output
	virtual void yyoutput(_YL yywint_t ch);
#endif
#ifdef unput
	virtual void yyunput(_YL yywint_t ch);
#endif

protected:
	void yytables();
	virtual _YL yywint_t yyaction(int action);

public:
#line 25 ".\\wordAnalyzer.l"

	// place any extra class members here

#line 65 "wordAnalyzer.h"
};

#ifndef YYLEXERNAME
#define YYLEXERNAME wordAnalyzer
#endif

#ifndef INITIAL
#define INITIAL 0
#endif

#endif
