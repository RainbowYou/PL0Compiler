#ifndef SYMBOL_H
#define SYMBOL_H

#include<iostream>
#include<cstring>
#include<string>

enum{
	CONST = 1, VAR, PROCEDURE, ODD, IF, THEN, ELSE, WHILE, DO, CALL, BEGIN, END, READ, WRITE, REPEAT, UNTIL,//key words
	IDENTIFIER, UINT,//
	COMMA, SEMICOLON, ASSIGN, LP, RP,
	PLUSO, MULTIPLYO, RELATIONO //operator
};


#endif