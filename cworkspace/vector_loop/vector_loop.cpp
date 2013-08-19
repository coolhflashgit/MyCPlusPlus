#include<iostream>
#include "file_operate.h"
#define LENGTH 15
#define LOOPTIME 3 
using namespace std;

//不支持min_num第一次调用时为0
int gcd(int max_num,int min_num)
{
	if(max_num < min_num ) return -1;
	if(min_num ==0) return max_num; 
	return gcd(min_num,max_num%min_num);

}

int* vector_loop1(int* array,int len,int loop_num)
{
	int i=0,j=0,temp;
	int d = gcd(len,loop_num);
	while(d)
	{
		temp = array[i];
		while((i+loop_num)%len != j)
		{
			array[i] = array[(i+loop_num)%len];
			i = (i+loop_num)%len;
		}
		array[i] = temp;
		j++;
		i=j;
		d--;
	}
	return array;
}

int* vector_loop2(int* array,int len,int loop_num)
{
	int i=0,j=0,temp;
	temp = array[i];
	for(int k=0;k<len;k++)
	{
		if((i+loop_num)%len == j)
		{
			array[i] = temp;
			j++;
			i=j;
		}
		else
		{
			array[i] = array[(i+loop_num)%len];
			i = (i+loop_num)%len;
		}
	}
	return array;
}

int main()
{
	int* loop_vector;
	FileOperate f;
	int temp;
	loop_vector = f.random_number(LENGTH,10);
	f.file_write("vector",loop_vector,LENGTH);
	int* re = vector_loop1(loop_vector,LENGTH,LOOPTIME);
//	int* re = vector_loop2(loop_vector,LENGTH,LOOPTIME);
/*	for(int i=0;i<LENGTH;i++)
	{
		cout << re2[i] << endl;
	}
*/
	f.file_write("new_vector",re,LENGTH);	
	return 0;	
}
