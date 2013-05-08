#include "Compute_express.h"
#include <iostream>
//using namespace std;
int main()
{
	//定义矩阵符号顺序
	vector<char> symbol_sequence;
	symbol_sequence.push_back('+');
	symbol_sequence.push_back('-');
	symbol_sequence.push_back('*');
	symbol_sequence.push_back('/');
	symbol_sequence.push_back('(');
	symbol_sequence.push_back(')');
		
	//行分别为 + - * / （ ）
	//列分别为 + - * / （ ）
	int symbol_array[6][6] = {{1,1,-1,-1,-1,1},
							  {1,1,-1,-1,-1,1},
							  {1,1,1,1,-1,1},
							  {1,1,1,1,-1,1},
							  {-1,-1,-1,-1,-1,1},
							  {1,1,1,1,100,1}};
	Compute_express ce;
	string express = "((54+11)*3/7)*4+2/6";
	ce.set_symbol_sequence(symbol_sequence);
	ce.set_symbol_priority_array(symbol_array);
	ce.set_express(express);
	ce.compute();
	return 0;
}
