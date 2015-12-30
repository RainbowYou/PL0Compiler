#ifndef SYMBOLTABLEMANAGER_H
#define SYMBOLTABLEMANAGER_H

#include <vector>
#include "SymbolTable.h"
using namespace std;

class SymbolTableManager
{
private:
	vector<SymbolTable> manager;
	string curName;
	int curType;
	string curValue;

public:
	bool insert(SymbolTable);
	bool remove(int);

public:
	void setCurrentName(string n);
	void setCurrentType(int t);
	void setCurrentValue(string v);

	string getCurrentName() const { return curName; }
	int getCurrentType() const { return curType; }
	string getCurrentValue() const { return curValue; }

};

#endif