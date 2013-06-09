/*
 * Date_File.cpp
 *
 *  Created on: 2013-5-14
 *      Author: Administrator
 */
#include "datafile.h"
#include<ctime>
#include<string>
#include<fstream>
#include<algorithm>

using namespace std;

Date_File_Operate::Date_File_Operate(const string &file_name):file_name(file_name){};

vector<int> Date_File_Operate::get_file_content(){
	vector<int> data;
	string file_data;
	string::size_type begin = 0;
	ifstream infile(file_name.c_str());
	if(!infile)
	{
		cout << "Open file faild" << endl;
	}
	else
	{
		getline(infile,file_data);
		while(begin != file_data.length()){
			string::size_type end = file_data.find_first_of(" ",begin);
			int temp =  atoi(file_data.substr(begin,end).c_str());
			data.push_back(temp);
			begin = end+1;
		}

		infile.clear();
		infile.close();

	}
	return data;
}

bool Date_File_Operate::write_to_file_random(){
	ofstream outfile(file_name.c_str());
	if(!outfile)
	{
		cout << "Open file faild" << endl;
		return false;
	}
	else
	{
		srand((unsigned)time(NULL));
		for(int i = 0;i<MAX;i++){
			outfile << rand() << " ";
		}
		outfile.clear();
		outfile.close();
		return true;
	}
}

bool Date_File_Operate::write_to_file_result(const string &file_name,const vector<int> &result)
{
	ofstream outfile(file_name.c_str());
	if(!outfile)
	{
		cout << "open result file error!" <<endl;
		return false;
	}
	else
	{
		for(vector<int>::const_iterator i = result.begin();i != result.end();i++)
		{
			outfile << *i << endl;
		}
		outfile.clear();
		outfile.close();
		return true;
	}
}



