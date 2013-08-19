/*
 * run.cpp
 *
 *  Created on: 2013-5-14
 *      Author: Administrator
 */
#include<iostream>
#include "datafile.h"
#include "MergeSort.h"
#include "HeapSort.h"
#include "QuickSort.h"
#include "ShellSort.h"
using namespace std;
int main(){
	vector<int> random_number,sort_result;

	//���ɳ�ʼ������
	Date_File_Operate dfo("ramdom.txt");
	dfo.write_to_file_random(); //�����������
	random_number = dfo.get_file_content();
/*
	//�鲢���������
	MergeSort ms;
	sort_result = ms.sort(ramdom_number,false);
	dfo.write_to_file_result("mergesortresult.txt",sort_result);
*/
/*
	//������������
	HeapSort hs;
	sort_result = hs.sort(random_number);
	dfo.write_to_file_result("heapsortresult.txt",sort_result);
	return 0;
*/
/*
	QuickSort qs;
	sort_result = qs.sort_result(random_number);
	dfo.write_to_file_result("quicksortresult.txt",sort_result);
	cout << "�������!" <<endl;
*/
	ShellSort ss;
	sort_result = ss.sort_result(random_number);
	dfo.write_to_file_result("shellsortresult.txt",sort_result);
	cout << "���������" <<endl;
}


