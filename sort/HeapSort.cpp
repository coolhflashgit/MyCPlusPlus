/*
 * HeapSort.cpp
 *
 *  Created on: 2013-6-9
 *      Author: Administrator
 */

#include "HeapSort.h"

HeapSort::HeapSort(){};

void HeapSort::build_heap(vector<int> &array)
{
	unsigned int tree_max;
	int temp;
	for(unsigned int pos =array.size()/2;pos >=1;pos--)
	{
		tree_max = pos;
		if(array.at(pos*2-1) > array.at(tree_max-1))
			tree_max = pos*2;

		if((pos*2+1 < array.size()) && array.at(pos*2) > array.at(tree_max-1))
			tree_max = pos*2+1;

		if(tree_max != pos)
		{
			temp = array.at(pos-1);
			array[pos-1] = array.at(tree_max-1);
			array[tree_max-1] = temp;
			//调整堆
			if(tree_max <= array.size()/2)
				adjust_heap(array,tree_max,array.size());
		}
	}
}

void HeapSort::adjust_heap(vector<int> &array,int top,int len)
{
	if(top > len/2)
		cout << "the top of the heap prepared to adjust is error!" << endl;
	else
	{
		int cur_top = top;
		int tree_max = top;
		int temp;
		while(cur_top <= len/2)
		{
			if(array.at(cur_top*2-1) > array.at(tree_max-1))
				tree_max = cur_top*2;
			if(cur_top*2+1 <= len && array.at(cur_top*2) > array.at(tree_max-1))
				tree_max = cur_top*2+1;
			//当出现当前定点比其子女小时，交换，否则停止调整
			if(cur_top != tree_max)
			{
			temp = array.at(cur_top-1);
			array[cur_top-1] = array.at(tree_max-1);
			array[tree_max-1] = temp;
			cur_top = tree_max;
			}
			else
				break;
		}
	}
}

vector<int> HeapSort::sort(vector<int> array)
{
	vector<int> result = array;
	build_heap(result);
	int temp;
	for(vector<int>::reverse_iterator i = result.rbegin();i != result.rend() ;i++)
	{
		if(*i != *result.begin())
		{
			temp = *i;
			*i = *result.begin();
			*result.begin() = temp;
		}
		//调整
		if((result.rend() -i -1) >= 2)
			adjust_heap(result,1,result.rend() - i -1);
	}
	return result;
}


