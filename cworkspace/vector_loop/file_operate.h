#ifndef FILEOPERATE_H
#define FILEOPERATE_H
#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<algorithm>
#include<limits>
#include<vector>
#endif
using namespace std;
class FileOperate
{
public:
	int* random_number(int,int,int min=0);
	void file_write(const string,int*,int);
	vector<int> file_read(const string);
};
