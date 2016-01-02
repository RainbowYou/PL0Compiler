#include "SymbolTableManager.h"
#include <exception>

SymbolTableManager::SymbolTableManager()
{
	setCurrentLevel(0);
	setCurrentOffset(3);
}

bool SymbolTableManager::insert(SymbolTable* t)
{
	try
	{
		table.push_back(t);
		curName = " ";
		//curType = -1;
		curValue = " ";
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

bool SymbolTableManager::find(string s)
{
	int len = table.size();
	for (int i = 0; i < len; i++)
	{
		if (s == table[i]->getName()) return true;
	}
	return false;
}

void SymbolTableManager::setCurrentName(string s)
{
	curName = s;
}

void SymbolTableManager::setCurrentType(int t)
{
	curType = t;
}

void SymbolTableManager::setCurrentLevel(int l)
{
	curLevel = l;
}

void SymbolTableManager::setCurrentOffset(int os)
{
	curOffset = os;
}

void SymbolTableManager::setCurrentValue(string v)
{
	curValue = v;
}