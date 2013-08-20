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

void reverse(int* array,int begin,int end)
{
	if(begin >= end) return;
	else
	{
//		int temp;
		for(;begin <end;begin++,end--)
		{
			//通过按位异或进行交换
			array[begin] = array[begin]^array[end];
			array[end] = array[begin]^array[end];
			array[begin] = array[begin]^array[end];
//			temp = array[begin];
//			array[begin] = array[end] ;
//			array[end] = temp;
		}
	}
}

//想把ab变为ba，可对a求逆，b求逆 然后整体求逆
int* vector_loop3(int* array,int len,int loop_num)
{
	if(loop_num ==0) return array;
	if(loop_num ==len) return array;
	reverse(array,0,loop_num-1);
	reverse(array,loop_num,len-1);
	reverse(array,0,len-1);
	return array;
}

void swap(int* array,int left,int right,int len)
{
	for(int i=0;i<len;i++)
	{
		array[left+i] = array[left+i]^array[right+i];
		array[right+i] = array[left+i]^array[right+i];
		array[left+i] = array[left+i]^array[right+i];
	}
}

//以loop_num为中心，左右交换
int* vector_loop4(int* array,int len,int loop_num)
{
	int left = loop_num;
	int right = len - left;
	while(left != right)
	{
		if(left < right)
		{
			swap(array,loop_num-left,loop_num+right-left,left);
			right-=left;
		}
		else
		{
			swap(array,loop_num-left,loop_num,right);
			left-=right;
		}

	}
	swap(array,loop_num-left,loop_num,left);
	return array;
}

int main()
{
	int* loop_vector;
	FileOperate f;
	int temp;
	loop_vector = f.random_number(LENGTH,10);
	f.file_write("vector",loop_vector,LENGTH);
//	int* re = vector_loop1(loop_vector,LENGTH,LOOPTIME);
//	int* re = vector_loop2(loop_vector,LENGTH,LOOPTIME);
//	int* re = vector_loop3(loop_vector,LENGTH,LOOPTIME);
	int* re = vector_loop4(loop_vector,LENGTH,LOOPTIME);
	for(int i=0;i<LENGTH;i++)
	{
		cout << re[i] << endl;
	}

//	f.file_write("new_vector",re,LENGTH);	
	return 0;	
}
