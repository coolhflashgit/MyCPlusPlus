/*
 * ShellSort.h
 *
 *  Created on: 2013-7-10
 *      Author: Administrator
 */

#ifndef SHELLSORT_H_
#define SHELLSORT_H_
#include<vector>

using namespace std;
class ShellSort{
public:
	void sort(vector<int> & array,vector<int> step);
	vector<int> sort_result(vector<int>& array);
};



#endif /* SHELLSORT_H_ */
