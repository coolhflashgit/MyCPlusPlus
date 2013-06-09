/*
 * MergeSort.cpp
 *
 *  Created on: 2013-6-8
 *      Author: Administrator
 */
#include "MergeSort.h"

using namespace std;
MergeSort::MergeSort(){};

vector<int> MergeSort::merge(const vector<int> &array_first,const vector<int> &array_second){
	vector<int> array_merged;
	array_merged.reserve(array_first.size()+array_second.size());
	vector<int>::const_iterator first_pos = array_first.begin();
	vector<int>::const_iterator second_pos = array_second.begin();
	while(first_pos != array_first.end() && second_pos != array_second.end())
	{
		if(*first_pos < *second_pos)
			array_merged.push_back(static_cast<int>(*first_pos++));
		else
			array_merged.push_back(static_cast<int>(*second_pos++));
	}

	while(first_pos != array_first.end())
		array_merged.push_back(static_cast<int>(*first_pos++));
	while(second_pos != array_second.end())
		array_merged.push_back(static_cast<int>(*second_pos++));

	return array_merged;
}

vector<int> MergeSort::divide(vector<int> array){
	if(array.size() == 1) return array;
	else
	{
		vector<int> first;
		vector<int> second;
		first.assign(array.begin(),array.begin()+(array.end()-array.begin())/2);
		second.assign(array.begin()+(array.end()-array.begin())/2,array.end());
		vector<int> first_sorted = divide(first);
		vector<int> second_sorted = divide(second);
		return merge(first_sorted,second_sorted);
	}
}

vector<int> MergeSort::sort(vector<int> &array,bool symbol)
{
	vector<int> array_sorted;
	array_sorted = divide(array);

	if(symbol == true)
		return array_sorted;
	else
	{
		int temp  = 0;
		temp = *(array_sorted.begin());
		for(vector<int>::iterator i = array_sorted.begin(),j = (array_sorted.end()-1);i < j;i++,j--)
		{
			temp = *i;
			*i = *j;
			*j = temp;
		}
		return array_sorted;
	}

}
