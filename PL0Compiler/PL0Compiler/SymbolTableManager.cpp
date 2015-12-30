#include "SymbolTableManager.h"
#include <exception>

bool SymbolTableManager::insert(SymbolTable table)
{
	try
	{
		tableManager.push_back(table);
	}

	catch (exception e)
	{
		return false;
	}
	return true;
}

bool SymbolTableManager::remove(int index)
{
	if (index > tableManager.size()) return false;

	tableManager.erase(tableManager.begin() + index);
	return true;
}