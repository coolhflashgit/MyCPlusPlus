#ifndef COMPUTE_EXPRESS.H
#define COMPUTE_EXPRESS.H
#include<iostream>
#include<cctype>
#include<vector>
#include<stack>
#include<map>
#include<string>
#include<cstdlib>
using namespace std;

//缺少符号个数常量的定义
class Compute_express
{
	private:
		//符号及其顺序数组
		vector<char> symbol_sequence;
		//定义符号优先级map
		map< char,map<char,int> > symbol_priority_map;
		//符号优先级数组，大于号是1 等于号是0 小于号是-1
		//不存在对比关系是 100
		int(*symbol_priority_array)[6];
		//表达式字符串
		string express;
		//存放数字的字符串
		string value_string;
		//符号栈
		stack<char> symbol_stack;
		//数字栈
		stack<int> digital_stack;
		//将优先级矩阵转化为优先级map	
		void symbol_priority_array_to_map();
		//根据优先级map判断是从符号栈中弹出还是压入
		//-1 是push 1是pop 
		//100 是出错 不存在对比关系
		int push_or_pop_symbol(char symbol);
		//根据算符计算数值
		int calculate_value(char symbol,int value1,int value2);
	public:
		//设置操作符顺序向量
		void set_symbol_sequence(vector<char> &symbol_sequence_arg);
		//设置优先级矩阵
		void set_symbol_priority_array(int(*symbol_priority_array_arg)[6]);
		//设置待计算的算式
		void set_express(string &string_arg);
		//计算最终结果
		int compute();
};
#endif
