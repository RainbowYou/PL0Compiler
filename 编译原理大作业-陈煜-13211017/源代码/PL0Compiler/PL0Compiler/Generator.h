#ifndef GENERATOR_H
#define GENERATOR_H

#include <fstream>
using namespace std;

class Generator
{
private:
	//static ofstream objectCode;
public:
	static void operation(int opeType);
	static void load(int l, int addr);
	static void store(int l, int addr);
	static void call(int l, int addr);
	static void increaseTop(int addr);
	static void jump(int addr);
	static void jumpCompare(int addr);
	static void read(int l, int addr);
	static void write();
};

#endif