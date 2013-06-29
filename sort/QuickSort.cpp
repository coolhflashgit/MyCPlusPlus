/*
 * QuickSort.cpp
 *
 *  Created on: 2013-6-29
 *      Author: Administrator
 */

#include "QuickSort.h"


int QuickSort::partition(vector<int>& array,int left,int right)
{
	int povit = array.at(left);
	int index = right;
	for(int i = right;i>left;i--)
	{
		if(array.at(i) > povit)
			swap(array[index--],array[i]);
	}
	swap(array[index],array[left]);
	return index;
}

void QuickSort::sort(vector<int>& array,int left,int right)
{
	if(left >= right)
		return;
	else
	{
		int index = partition(array,left,right);
		sort(array,left,index-1);
		sort(array,index+1,right);
	}
}

vector<int> QuickSort::sort_result(vector<int>& array)
{
	sort(array,0,array.size()-1);
	return array;
}




