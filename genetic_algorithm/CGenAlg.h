/*
 * CGenAlg.h
 *
 *  Created on: 2013-6-17
 *      Author: Administrator
 */

#ifndef CGENALG_H_
#define CGENALG_H_
#define PI 3.141592653
#include "CGenome.h"
#include <iostream>
#include <vector>
#include<time.h>
#include<stdlib.h>
#include<MATH.H>
#include "Parameter.h"
#include <fstream>
using namespace std;

class CGenAlg{
private:
	inline double RandFloat()
	{
		return rand()%11/10.0;
	}

	inline double CreateFitness(const vector<double>& input)
	{
		double x = input[0];
		double output;
		output = x*sin(10*PI*x)+2.0;
		return output;
	}

public:
	//��Ⱥ�����и���
	vector<CGenome> m_vecPop;
	//���и������Ӧ�������ܺ�
	double m_dTotalFitness;
	//����Ӧ�ĸ������Ӧ������
	double m_dBestFitness;
	//����Ӧ�ĸ���
	CGenome FittestCGenome;
	//���и�����Ӧ������ƽ��ֵ
	double m_dAverageFitness;
	//���Ӧ�ĸ������Ӧ������
	double m_dWorstFitness;
	//���Ӧ�ĸ���
	CGenome NFittestCGenome;

	//���캯��
	CGenAlg():m_dTotalFitness(0),m_dBestFitness(0),m_dAverageFitness(0),m_dWorstFitness(0){};

	//��ʼ��m_dTotalFitness, m_dBestFitness, m_dWorstFitness, m_dAverageFitness�ȱ���
	void reset();

	//��ʼ������
	void init();

	//����m_dTotalFitness, m_dBestFitness, m_dWorstFitness, m_dAverageFitness�ȱ���
	void CalculateBestWorstAvTot(const vector<CGenome> & CurPop);

	//���̶�ѡ����
	CGenome GetChromoRoulette();

	//��Ⱦɫ����ÿһ���������ͻ��
	void Mutate(vector<double> &chromo);

	//������һ��������
	void Epoch(vector<CGenome> &vecNewPop);

	void StartCGenAlg();

	void report(int generation,ofstream & outfile);
};


#endif /* CGENALG_H_ */
