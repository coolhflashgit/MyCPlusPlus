/*
 * Parameter.h
 *
 *  Created on: 2013-6-17
 *      Author: Administrator
 */

#ifndef PARAMETER_H_
#define PARAMETER_H_

//左边界
const double g_dLeftPoint = -1;

//右边界
const double g_dRightPoint = 2;

//=====遗传算法相关参数=====//

const int g_iNumGen = 1;       // 每条染色体的编码(基因)个数，这里是 1 个

const int g_iGeneration = 5000;      //进化的代数

const int g_iPopSize = 500;       // 种群的人口数目（就是说你要放多少只袋鼠到山上）

const double g_dMutationRate = 0.8;    //基因变异的概率

const double g_dCrossRate = 0.8; //交叉的概率

const double g_dMaxPerturbation = 0.005;   //基因变异的步长（袋鼠跳的最大距离）


#endif /* PARAMETER_H_ */
