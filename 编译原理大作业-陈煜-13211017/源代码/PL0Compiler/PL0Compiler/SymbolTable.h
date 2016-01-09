#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <string>
using namespace std;

class SymbolTable
{
public:
	SymbolTable();
	SymbolTable(string = NULL, int = -1, string = NULL, int = -1, int = -1);
	~SymbolTable();

private:
	string name;
	int kind;
	string value;
	int level;
	int address;

public:
	void setName(string n);
	void setKind(int k);
	void setValue(string v);
	void setLevel(int l);
	void setAddress(int addr);

	string getName() const { return name; }
	int getKind() const { return kind; }
	string getValue() const { return value; }
	int getLevel() const { return level; }
	int getAddress() const{ return address; }
};

#endif