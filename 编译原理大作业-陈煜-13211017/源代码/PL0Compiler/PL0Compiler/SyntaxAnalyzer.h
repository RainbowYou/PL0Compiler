#ifndef SYNTAXANALYZER_H
#define SYNTAXANALYZER_H

#include "SymbolTableManager.h"

class SyntaxAnalyzer
{
private:
	WordAnalyzer wordAnalyzer;
	/*char* symbol;*/
	SymbolTableManager* tableManager;

public:
	SyntaxAnalyzer();//constructor
	~SyntaxAnalyzer();//destructor

private:
	void program();				//����
	void partialProgram();		//�ֳ���

	void constPart();			//����˵������
	void constDef();			//��������

	bool identifier(int checkStatus);
	void varPart();				//����˵������

	void procedurePart();		//����˵������
	void procedureHeader();		//�����ײ�

	void sentence();			//���
	void assignSentence();		//��ֵ���
	void expression();			//���ʽ
	void item();				//��
	void factor();				//����

	void conditionSentence();	//�������
	void condition();			//����

	void whileSentence();		//��ѭ�����
	void procedureCallSentence();	//���̵������
	void readSentence();		//�����
	void writeSentence();		//д���
	void uniteSentence();		//�������
	void repeatSentence();		//�ظ����

public:
	/*void setSymbol(char* s);
	char* getSymbol() const;*/

	void setWordAnalyzer();
	WordAnalyzer getWordAnalyzer() const;

	void analyze();

	void printSymbleTable();

};

#endif