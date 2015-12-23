#ifndef SYMBOL_H
#define SYMBOL_H
#include <string>
using namespace std;

static enum{
	CONST = 1, VAR, PROCEDURE, ODD, IF, THEN, ELSE, WHILE, DO, CALL, BEGIN, END, READ, WRITE, REPEAT, UNTIL,//key words
	IDENTIFIER, UINT,//
	COMMA, SEMICOLON, ASSIGN, LP, RP, POINT,
	PLUSO, MULTIPLYO, RELATIONO //operator
};

static string keywords[] = {
	"const", "var", "procedure", "odd", "if",
	"then", "else", "while", "do", "call",
	"begin", "end", "read", "write", "repeat", "until" };

static const int keywordsLen = 16;

#endif