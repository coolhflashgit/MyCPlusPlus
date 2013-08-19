#include "file_operate.h"
int* FileOperate::random_number(int num,int max,int min)
{
	int* result = (int*)malloc(num*sizeof(int));
	srand((unsigned)time(NULL));
	for(int i=0;i<num;i++)
		result[i] = min+rand()%max;
	return result;
}

void FileOperate::file_write(const string filename,int * array,int num)
{
	ofstream outfile(filename.c_str());
	if(!outfile)
		cout << "file:"<<filename<<" open error"<<endl;
	else
	{
		for(int i=0;i<num;i++)
			outfile << array[i] <<endl;
		outfile.clear();
		outfile.close();
	}
}
vector<int> FileOperate::file_read(const string filename)
{

	vector<int> result;
	ifstream infile(filename.c_str());
	if(!infile)
		cout << "file:"<<filename<<" can't open!"<<endl;
	else
	{
		string temp;
		while(getline(infile,temp))
			result.push_back(atoi(temp.c_str()));
	}
	infile.clear();
	infile.close();
	return result;
}


