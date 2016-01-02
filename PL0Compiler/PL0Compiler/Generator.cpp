#include <iostream>
#include "Generator.h"
using namespace std;

void Generator::operation(int addr)
{
	cout << "OPR 0," << addr << endl;
}

void Generator::load(int l, int addr)
{
	cout << "LOD " << l << "," << addr << endl;
}

void Generator::store(int l, int addr)
{
	cout << "STO " << l << "," << addr << endl;
}

void Generator::call(int l, int addr)
{
	cout << "CAL " << l << "," << addr << endl;
}

void Generator::increaseTop(int addr)
{
	cout << "INT 0," << addr << endl;
}

void Generator::jump(int addr)
{
	cout << "JMP 0," << addr << endl;
}

void Generator::jumpCompare(int addr)
{
	cout << "JPC 0," << addr << endl;
}

void Generator::read(int l, int addr)
{
	cout << "RED " << l << "," << addr << endl;
}

void Generator::write()
{
	cout << "WRT 0,0" << endl;
}