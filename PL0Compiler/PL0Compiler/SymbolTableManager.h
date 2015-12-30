#ifndef SYMBOLTABLEMANAGER_H
#define SYMBOLTABLEMANAGER_H

#include <vector>
#include "SymbolTable.h"
using namespace std;

class SymbolTableManager
{
private:
	vector<SymbolTable> tableManager;

public:
	bool insert(SymbolTable);
	bool remove(int);

};

#endif