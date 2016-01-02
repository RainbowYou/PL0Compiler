#include "SymbolTableManager.h"
#include <exception>

SymbolTableManager::SymbolTableManager()
{
	setCurrentLevel(1);
	setCurrentOffset(3);
}

bool SymbolTableManager::insert(SymbolTable* t)
{
	try
	{
		//table.push_back(t);
		table.push(t);
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

//bool SymbolTableManager::remove(int index)
//{
//	if (index > table.size()) return false;
//
//	table.erase(table.begin() + index);
//	return true;
//}
void SymbolTableManager::pop()
{
	table.pop();
}

SymbolTable* SymbolTableManager::top() const
{
	SymbolTable* entry = table.top();
	return entry;
}

bool SymbolTableManager::find(string s)
{
	stack<SymbolTable*> tableBuff = table;
	int len = tableBuff.size();
	for (int i = 0; i < len; i++)
	{
		//if (s == table[i]->getName()) return true;
		if (s == tableBuff.top()->getName()) return true;
		tableBuff.pop();
	}
	return false;
}

SymbolTable* SymbolTableManager::getTableEntry(string s)
{
	stack<SymbolTable*> tableBuff = table;
	int len = tableBuff.size();
	for (int i = 0; i < len; i++)
	{
		if (s == tableBuff.top()->getName()) return tableBuff.top();
		tableBuff.pop();
	}
	return NULL;
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