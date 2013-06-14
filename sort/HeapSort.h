/*
 * HeapSort.h
 *
 *  Created on: 2013-6-9
 *      Author: Administrator
 */

#ifndef HEAPSORT_H_
#define HEAPSORT_H_
using namespace std;
#include<vector>
#include<iostream>
class HeapSort{
private:

public:
	/**
	 * ���캯��
	 */
	HeapSort();
	/**
	 * ������
	 */
	void build_heap(vector<int> &array);
	/**
	 * ������
	 */
	void adjust_heap(vector<int> &array,int top,int len);
	/**
	 * ������
	 */
	vector<int> sort(vector<int> array);
};



#endif /* HEAPSORT_H_ */
