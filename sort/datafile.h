/*
 * Data_File.h
 *
 *  Created on: 2013-5-14
 *      Author: Administrator
 */

#ifndef DATA_FILE_H_
#define DATA_FILE_H_
#include<iostream>
#include<vector>
using namespace std;

class Date_File_Operate{
private:
	string file_name;
	const static int MAX = 1000;
public:
	Date_File_Operate(const string &file_name);

	/**
	 *���ļ���д���������
	 */
	bool write_to_file_random();
	/**
	 * ��ָ���ļ���д��������
	 */
	bool write_to_file_result(const string &file_name,const vector<int> &result);
	/**
	 * vector �����ļ�������
	 */
	vector<int> get_file_content();
};



#endif /* DATA_FILE_H_ */
