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
	//种群中所有个体
	vector<CGenome> m_vecPop;
	//所有个体的适应性评分总和
	double m_dTotalFitness;
	//最适应的个体的适应性评分
	double m_dBestFitness;
	//最适应的个体
	CGenome FittestCGenome;
	//所有个体适应性评分平均值
	double m_dAverageFitness;
	//最不适应的个体的适应性评分
	double m_dWorstFitness;
	//最不适应的个体
	CGenome NFittestCGenome;

	//构造函数
	CGenAlg():m_dTotalFitness(0),m_dBestFitness(0),m_dAverageFitness(0),m_dWorstFitness(0){};

	//初始化m_dTotalFitness, m_dBestFitness, m_dWorstFitness, m_dAverageFitness等变量
	void reset();

	//初始化函数
	void init();

	//计算m_dTotalFitness, m_dBestFitness, m_dWorstFitness, m_dAverageFitness等变量
	void CalculateBestWorstAvTot(const vector<CGenome> & CurPop);

	//轮盘赌选择函数
	CGenome GetChromoRoulette();

	//对染色体中每一个基因进行突变
	void Mutate(vector<double> &chromo);

	//产生新一代基因函数
	void Epoch(vector<CGenome> &vecNewPop);

	void StartCGenAlg();

	void report(int generation,ofstream & outfile);
};


#endif /* CGENALG_H_ */
