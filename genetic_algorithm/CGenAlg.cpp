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

	//将容器清空
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
		cout<<"你设置的人口总数为单数，导致人口减少一名"<<endl;
		return;
	}
}

void CGenAlg::report(int generation,ofstream & outfile)
{

	outfile <<"=======第"<<generation<<"代======"<<endl;
	outfile << "最高适应度是:" << m_dBestFitness<<endl;
	outfile << "平均适应度是:" << m_dAverageFitness << endl;

}

void CGenAlg::StartCGenAlg()
{
	srand((unsigned)time(NULL));
	init();

	vector<CGenome> m_population;
	m_population.clear();
	m_population = m_vecPop;

	//打开文件流
	string FileName = "report.txt";
	ofstream outfile(FileName.c_str());
	if(!outfile)
	{
		cout << "打开文件失败！"<<endl;
	}

	for(int generation = 0; generation < g_iGeneration;generation++)
	{
		//对每一代的适应性进行评分
		for(int i=0;i<g_iPopSize;i++)
		{
			m_population[i].dFitness = CreateFitness(m_population[i].vecWeight);
		}

		reset();
		CalculateBestWorstAvTot(m_population);

		report(generation+1,outfile);

		//产生子代
		Epoch(m_population);

	}

	outfile.clear();
	outfile.close();

	cout << "程序结束" <<endl;

}



