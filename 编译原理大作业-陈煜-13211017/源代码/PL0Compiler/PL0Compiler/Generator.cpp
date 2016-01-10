#include <iostream>
#include "Generator.h"
using namespace std;


void Generator::operation(int addr)
{
	ofstream objectCode("../Debug/output.txt", ios::app);
	objectCode << "OPR\t0\t" << addr << endl;
}

void Generator::load(int l, int addr)
{
	ofstream objectCode("../Debug/output.txt", ios::app);
	objectCode << "LOD\t" << l << "\t" << addr << endl;
}

void Generator::store(int l, int addr)
{
	ofstream objectCode("../Debug/output.txt", ios::app);
	objectCode << "STO\t" << l << "\t" << addr << endl;
}

void Generator::call(int l, int addr)
{
	ofstream objectCode("../Debug/output.txt", ios::app);
	objectCode << "CAL\t" << l << "\t" << addr << endl;
}

void Generator::increaseTop(int addr)
{
	ofstream objectCode("../Debug/output.txt", ios::app);
	objectCode << "INT\t0\t" << addr << endl;
}

void Generator::jump(int addr)
{
	ofstream objectCode("../Debug/output.txt", ios::app);
	objectCode << "JMP\t0\t" << addr << endl;
}

void Generator::jumpCompare(int addr)
{
	ofstream objectCode("../Debug/output.txt", ios::app);
	objectCode << "JPC\t0\t" << addr << endl;
}

void Generator::read(int l, int addr)
{
	ofstream objectCode("../Debug/output.txt", ios::app);
	objectCode << "RED\t" << l << "\t" << addr << endl;
}

void Generator::write()
{
	ofstream objectCode("../Debug/output.txt", ios::app);
	objectCode << "WRT\t0\t0" << endl;
}