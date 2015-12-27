#include "SymbolTable.h"

void SymbolTable::setName(char *s)
{
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