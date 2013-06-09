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
	 * 两部分合并方法
	 */
	vector<int> merge(const vector<int> &array_first,const vector<int> &array_second);
	/**
	 * 递归分治
	 */
	vector<int> divide(vector<int> array);
public:
	MergeSort();
	/**
	 * 归并排序的静态方法
	 * 默认symbol是true 为递增排序，否则为递减排序
	 */
	vector<int> sort(vector<int> &array,bool symbol = true);
};



#endif /* MERGESORT_H_ */
