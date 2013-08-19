#ifndef DATA_FILE_H
#define DATA_FILE_H
#include<iostream>
#include<vector>
using namespace std;

class CGenome{
public:

    // 定义装载基因的容器（事实上从英文解释来看，Weights是权值的意思，这用来表示
	// 基因的确有点名不符实，呵呵。这主要是因为这些代码来自于 GA-ANN 引擎，所以在
	// 它里面基因实质就是神经网络的权值，所以习惯性的把它引入过来就只好这样了。）
	vector<double> vecWeight;
	//存储适应度
	double dFitness;

	CGenome();

	CGenome(vector<double> w,double d);
};

#endif
