#ifndef COMPUTE_EXPRESS.H
#define COMPUTE_EXPRESS.H
#include<iostream>
#include<vector>
using namespace std;
class Compute_express
{
	private:
		//符号优先级数组，大于号是1 等于号是0 小于号是-1
		//不存在对比关系是 100
		vector< vector<int> > symbol_priority_array;
		//表达式字符串
		string express;
	public:
//		vector< vector<int> > get_symbol_priority_array();
		void set_symbol_priority_array(vector< vector<int> > &array_arg);
//		string get_express();
		void set_express(const string &string_arg);
		void printtest();
};
#endif
