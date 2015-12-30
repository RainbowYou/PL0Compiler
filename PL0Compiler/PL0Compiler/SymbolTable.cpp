#include "SymbolTable.h"

SymbolTable::SymbolTable()
{
	setKind(-1);
	setValue(NULL);
	setLevel(-1);
	setAddress(-1);
}

SymbolTable::SymbolTable(string s, int k, string v, int l, int addr)
{
	setName(s);
	setKind(k);
	setValue(v);
	setLevel(l);
	setAddress(addr);
}

SymbolTable::~SymbolTable()
{
	setName(NULL);
	setKind(-1);
	setValue(NULL);
	setLevel(-1);
	setAddress(-1);
}

void SymbolTable::setName(string s)
{
	name = s;
}

void SymbolTable::setKind(int k)
{
	kind = k;
}

void SymbolTable::setValue(string v)
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