/*
 * QuickSort.h
 *
 *  Created on: 2013-6-29
 *      Author: Administrator
 */

#ifndef QUICKSORT_H_
#define QUICKSORT_H_
#include<vector>
using namespace std;

class QuickSort{
private:
	inline void swap(int& a,int& b)
	{
		int temp;
		temp = a;
		a = b;
		b = temp;
	}

public:
	/**
	 * 首先假设所有经for循环遍历过的都是比povit小的值，并按照所假设
	 * 的规律一直向前检查，当出现比povit大的值得时候，同遍历过的地方
	 * 进行交换，将大值放到后面
	 */
	int partition(vector<int>& array,int left,int right);
	void sort(vector<int>& array,int left,int right);
	vector<int> sort_result(vector<int> & array);
};



#endif /* QUICKSORT_H_ */
