/*
 * run.cpp
 *
 *  Created on: 2013-5-14
 *      Author: Administrator
 */
#include<iostream>
#include "datafile.h"
#include "MergeSort.h"
using namespace std;
int main(){
	vector<int> ramdom_number,merge_sort_result;

	//���ɳ�ʼ������
	Date_File_Operate dfo("ramdom.txt");
//	dfo.write_to_file_random(); //�����������
	ramdom_number = dfo.get_file_content();

	//�鲢���������
	MergeSort ms;
	merge_sort_result = ms.sort(ramdom_number,false);
	dfo.write_to_file_result("mergesortresult.txt",merge_sort_result);

	return 0;
}



