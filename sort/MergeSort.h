/*
 * MergeSort.h
 *
 *  Created on: 2013-6-8
 *      Author: Administrator
 */

#ifndef MERGESORT_H_
#define MERGESORT_H_

#include<vector>
using namespace std;

class MergeSort{
private:
	vector<int> array;
	/**
	 * �����ֺϲ�����
	 */
	vector<int> merge(const vector<int> &array_first,const vector<int> &array_second);
	/**
	 * �ݹ����
	 */
	vector<int> divide(vector<int> array);
public:
	MergeSort();
	/**
	 * �鲢����ľ�̬����
	 * Ĭ��symbol��true Ϊ�������򣬷���Ϊ�ݼ�����
	 */
	vector<int> sort(vector<int> &array,bool symbol = true);
};



#endif /* MERGESORT_H_ */
