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
	 * ���ȼ������о�forѭ���������Ķ��Ǳ�povitС��ֵ��������������
	 * �Ĺ���һֱ��ǰ��飬�����ֱ�povit���ֵ��ʱ��ͬ�������ĵط�
	 * ���н���������ֵ�ŵ�����
	 */
	int partition(vector<int>& array,int left,int right);
	void sort(vector<int>& array,int left,int right);
	vector<int> sort_result(vector<int> & array);
};



#endif /* QUICKSORT_H_ */
