#ifndef SYNTAXANALYZER_H
#define SYNTAXANALYZER_H


class SyntaxAnalyzer
{
private:
	WordAnalyzer wordAnalyzer;
	char* symbol;
public:
	SyntaxAnalyzer();//constructor
	~SyntaxAnalyzer();//destructor

private:
	void program();				//程序
	void partialProgram();		//分程序

	void constPart();			//常量说明部分
	void constDef();			//常量定义

	void varPart();				//变量说明部分

	void procedurePart();		//过程说明部分
	void procedureHeader();		//过程首部

	void sentence();			//语句
	void assignSentence();		//赋值语句
	void expression();			//表达式
	void item();				//项
	void factor();				//因子

	void conditionSentence();	//条件语句
	void condition();			//条件

	void whileSentence();		//当循环语句
	void procedureCallSentence();	//过程调用语句
	void readSentence();		//读语句
	void writeSentence();		//写语句
	void uniteSentence();		//复合语句
	void repeatSentence();		//重复语句

public:
	void analyze();
};

#endif