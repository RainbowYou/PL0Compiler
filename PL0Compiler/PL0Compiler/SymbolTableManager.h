#ifndef SYMBOLTABLEMANAGER_H
#define SYMBOLTABLEMANAGER_H

#include <vector>
#include <stack>
#include "SymbolTable.h"
using namespace std;

class SymbolTableManager
{
public:
	SymbolTableManager();

private:
	stack<SymbolTable*> table;
	string curName;
	int curType;
	int curLevel;
	int curOffset;
	string curValue;

public:
	bool insert(SymbolTable*);
	//bool remove(int);
	void pop();
	bool find(string s);

public:
	void setCurrentName(string n);
	void setCurrentType(int t);
	void setCurrentLevel(int l);
	void setCurrentOffset(int os);
	void setCurrentValue(string v);

	string getCurrentName() const { return curName; }
	int getCurrentType() const { return curType; }
	int getCurrentLevel() const { return curLevel; }
	int getCurrentOffset() const{ return curOffset; }
	string getCurrentValue() const { return curValue; }
	stack<SymbolTable*> getSymbolTable() const { return table; }
	
	void increaseLevel() { curLevel++; }
	void increaseOffset() { curOffset++; }

	void decreaseLevel() { curLevel--; }
	void decreaseOffset() { curOffset--; }
};

#endif