#ifndef DATA_FILE_H
#define DATA_FILE_H
#include<iostream>
#include<vector>
using namespace std;

class CGenome{
public:

    // ����װ�ػ������������ʵ�ϴ�Ӣ�Ľ���������Weights��Ȩֵ����˼����������ʾ
	// �����ȷ�е�������ʵ���Ǻǡ�����Ҫ����Ϊ��Щ���������� GA-ANN ���棬������
	// ���������ʵ�ʾ����������Ȩֵ������ϰ���Եİ������������ֻ�������ˡ���
	vector<double> vecWeight;
	//�洢��Ӧ��
	double dFitness;

	CGenome();

	CGenome(vector<double> w,double d);
};

#endif
