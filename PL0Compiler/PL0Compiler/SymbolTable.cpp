#include "SymbolTable.h"

SymbolTable::SymbolTable()
{
	setKind(NULL);
	setValue(-1);
	setLevel(-1);
	setAddress(-1);
}

SymbolTable::SymbolTable(char* s, string k, int v, int l, int addr)
{
	setName(s);
	setKind(k);
	setValue(v);
	setLevel(l);
	setAddress(addr);
}

SymbolTable::~SymbolTable()
{
	delete name;
	setKind(NULL);
	setValue(-1);
	setLevel(-1);
	setAddress(-1);
}

void SymbolTable::setName(char *s)
{
	int len = strlen(s);
	name = new char[len + 1];
	strcpy(name, s);
}

void SymbolTable::setKind(string k)
{
	kind = k;
}

void SymbolTable::setValue(int v)
{
	value = v;
}

void SymbolTable::setLevel(int l)
{
	level = l;
}

void SymbolTable::setAddress(int addr)
{
	address = addr;
}