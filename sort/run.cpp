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
using namespace std;
int main(){
	vector<int> random_number,sort_result;

	//生成初始化数据
	Date_File_Operate dfo("ramdom.txt");
	dfo.write_to_file_random(); //生成随机数据
	random_number = dfo.get_file_content();
/*
	//归并排序结果输出
	MergeSort ms;
	sort_result = ms.sort(ramdom_number,false);
	dfo.write_to_file_result("mergesortresult.txt",sort_result);
*/
	HeapSort hs;
	sort_result = hs.sort(random_number);
	dfo.write_to_file_result("heapsortresult.txt",sort_result);
	return 0;
}



