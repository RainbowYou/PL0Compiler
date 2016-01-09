#include <iostream>
#include "Generator.h"
using namespace std;

void Generator::operation(int addr)
{
	cout << "OPR\t0\t" << addr << endl;
}

void Generator::load(int l, int addr)
{
	cout << "LOD\t" << l << "\t" << addr << endl;
}

void Generator::store(int l, int addr)
{
	cout << "STO\t" << l << "\t" << addr << endl;
}

void Generator::call(int l, int addr)
{
	cout << "CAL\t" << l << "\t" << addr << endl;
}

void Generator::increaseTop(int addr)
{
	cout << "INT\t0\t" << addr << endl;
}

void Generator::jump(int addr)
{
	cout << "JMP\t0\t" << addr << endl;
}

void Generator::jumpCompare(int addr)
{
	cout << "JPC\t0\t" << addr << endl;
}

void Generator::read(int l, int addr)
{
	cout << "RED\t" << l << "\t" << addr << endl;
}

void Generator::write()
{
	cout << "WRT\t0\t0" << endl;
}