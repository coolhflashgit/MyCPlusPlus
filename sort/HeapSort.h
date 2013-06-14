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
	 * 构造函数
	 */
	HeapSort();
	/**
	 * 创建堆
	 */
	void build_heap(vector<int> &array);
	/**
	 * 调正堆
	 */
	void adjust_heap(vector<int> &array,int top,int len);
	/**
	 * 输出结果
	 */
	vector<int> sort(vector<int> array);
};



#endif /* HEAPSORT_H_ */
