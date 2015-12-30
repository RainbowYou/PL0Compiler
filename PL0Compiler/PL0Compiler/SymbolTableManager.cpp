#include "SymbolTableManager.h"
#include <exception>

SymbolTableManager::SymbolTableManager()
{
	//table = new vector<SymbolTable*>();
}

bool SymbolTableManager::insert(SymbolTable* t)
{
	try
	{
		table.push_back(t);
		curName = " ";
	}

	catch (exception e)
	{
		return false;
	}
	return true;
}

bool SymbolTableManager::remove(int index)
{
	if (index > table.size()) return false;

	table.erase(table.begin() + index);
	return true;
}

void SymbolTableManager::setCurrentName(string s)
{
	curName = s;
}

void SymbolTableManager::setCurrentType(int t)
{
	curType = t;
}

void SymbolTableManager::setCurrentValue(string v)
{
	curValue = v;
}