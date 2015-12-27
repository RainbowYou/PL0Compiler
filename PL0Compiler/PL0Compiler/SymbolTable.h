#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <string>
using namespace std;

class SymbolTable
{
private:
	char* name;
	string kind;
	int value;
	int level;
	int address;
public:
	void setName(char* n);
	void setKind(string k);
	void setValue(int v);
	void setLevel(int l);
	void setAddress(int addr);

	char* getName() const { return name; }
	string getKind() const { return kind; }
	int getValue() const { return value; }
	int getLevel() const { return level; }
	int getAddress() const{ return address; }
};

#endif