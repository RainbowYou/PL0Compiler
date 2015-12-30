#include "SymbolTableManager.h"
#include <exception>

bool SymbolTableManager::insert(SymbolTable table)
{
	try
	{
		manager.push_back(table);
	}

	catch (exception e)
	{
		return false;
	}
	return true;
}

bool SymbolTableManager::remove(int index)
{
	if (index > manager.size()) return false;

	manager.erase(manager.begin() + index);
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