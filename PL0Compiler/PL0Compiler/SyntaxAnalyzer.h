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
	void program();				//����
	void partialProgram();		//�ֳ���

	void constPart();			//����˵������
	void constDef();			//��������

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
	void analyze();
};

#endif