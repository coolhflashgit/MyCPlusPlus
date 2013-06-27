/*
 * CGenAlg.cpp
 *
 *  Created on: 2013-6-17
 *      Author: Administrator
 */
#include "CGenAlg.h"

void CGenAlg::reset(){
	m_dTotalFitness = 0;
	m_dBestFitness = 0;
	m_dAverageFitness = 0;
	m_dWorstFitness = 99999;
}

void CGenAlg::CalculateBestWorstAvTot(const vector<CGenome> & CurPop){
	for(int i = 0;i < g_iPopSize;i++)
	{
		m_dTotalFitness += CurPop[i].dFitness;
		if(CurPop[i].dFitness > m_dBestFitness)
		{
			m_dBestFitness = CurPop[i].dFitness;
			FittestCGenome = CurPop[i];
		}
		if(CurPop[i].dFitness < m_dWorstFitness)
		{
			m_dWorstFitness = CurPop[i].dFitness;
			NFittestCGenome = CurPop[i];
		}
	}
	m_dAverageFitness = m_dTotalFitness / g_iPopSize;
}

void CGenAlg::init()
{
	m_dTotalFitness = 0;
	m_dBestFitness = 0;
	m_dWorstFitness = 0;
	m_dAverageFitness = 0;

	//���������
	m_vecPop.clear();

	for(int i = 0; i<g_iPopSize; i++)
	{
		m_vecPop.push_back(CGenome());

		for(int j = 0;j<g_iNumGen;j++)
		{
			m_vecPop[i].vecWeight.push_back(RandFloat()*(g_dRightPoint-g_dLeftPoint)+g_dLeftPoint);
		}
	}
}

CGenome CGenAlg::GetChromoRoulette()
{
	double slice = RandFloat()*m_dTotalFitness;
	double fitnessSoFar = 0;
	CGenome theChosen;

	for(int i = 0;i < g_iPopSize;i++)
	{
		fitnessSoFar += m_vecPop[i].dFitness;
		if(fitnessSoFar >= slice )
		{
			theChosen = m_vecPop[i];
			break;
		}
	}

	return theChosen;
}

void CGenAlg::Mutate(vector<double> &chromo)
{
	for(int i = 0;i<chromo.size();i++)
	{
		if(RandFloat() < g_dMutationRate)
		{
			chromo[i] += ((RandFloat()-0.5)*g_dMaxPerturbation);

			if(chromo[i] < g_dLeftPoint)
				chromo[i] = g_dRightPoint;

			else if(chromo[i] > g_dRightPoint)
				chromo[i] = g_dLeftPoint;
		}
	}
}

void CGenAlg::Epoch(vector<CGenome> &vecNewPop)
{
	m_vecPop = vecNewPop;
	vecNewPop.clear();
	while(vecNewPop.size() < g_iPopSize)
	{
		CGenome mm = GetChromoRoulette();
		CGenome dd = GetChromoRoulette();

		vector<double> baby1 = mm.vecWeight;
		vector<double> baby2 = dd.vecWeight;

		Mutate(baby1);
		Mutate(baby2);

		vecNewPop.push_back(CGenome(baby1,0));
		vecNewPop.push_back(CGenome(baby2,0));
	}

	if(vecNewPop.size() != g_iPopSize)
	{
		cout<<"�����õ��˿�����Ϊ�����������˿ڼ���һ��"<<endl;
		return;
	}
}

void CGenAlg::report(int generation,ofstream & outfile)
{

	outfile <<"=======��"<<generation<<"��======"<<endl;
	outfile << "�����Ӧ����:" << m_dBestFitness<<endl;
	outfile << "ƽ����Ӧ����:" << m_dAverageFitness << endl;

}

void CGenAlg::StartCGenAlg()
{
	srand((unsigned)time(NULL));
	init();

	vector<CGenome> m_population;
	m_population.clear();
	m_population = m_vecPop;

	//���ļ���
	string FileName = "report.txt";
	ofstream outfile(FileName.c_str());
	if(!outfile)
	{
		cout << "���ļ�ʧ�ܣ�"<<endl;
	}

	for(int generation = 0; generation < g_iGeneration;generation++)
	{
		//��ÿһ������Ӧ�Խ�������
		for(int i=0;i<g_iPopSize;i++)
		{
			m_population[i].dFitness = CreateFitness(m_population[i].vecWeight);
		}

		reset();
		CalculateBestWorstAvTot(m_population);

		report(generation+1,outfile);

		//�����Ӵ�
		Epoch(m_population);

	}

	outfile.clear();
	outfile.close();

	cout << "�������" <<endl;

}



