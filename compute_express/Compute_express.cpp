#include "Compute_express.h"

//设置操作符顺序向量
void Compute_express::set_symbol_sequence(vector<char> &symbol_sequence_arg)
{
	symbol_sequence = symbol_sequence_arg;
}
//设置优先级矩阵
void Compute_express::set_symbol_priority_array(int(*symbol_priority_array_arg)[6])
{
	symbol_priority_array = symbol_priority_array_arg;
}
//设置待计算的算式
void Compute_express::set_express(string &string_arg)
{
	express = string_arg+"#";
}
//将优先级矩阵转化为优先级map
void Compute_express::symbol_priority_array_to_map()
{
	int x=0;
	for(vector<char>::iterator iterx=symbol_sequence.begin();symbol_sequence.end() != iterx;iterx++)
	{
		int y = 0;
		map<char,int> temp;
		for(vector<char>::iterator itery = symbol_sequence.begin();symbol_sequence.end() != itery;itery++)
		{
			temp[*itery] =symbol_priority_array[x][y];
			y++;
		}
		symbol_priority_map[*iterx] = temp;
		x++;
	}
}
//根据优先级map判断是从符号栈中弹出还是压入
//-1 是push 1是pop 
//100 是出错 不存在对比关系
int Compute_express::push_or_pop_symbol(char symbol)
{
	if(symbol == '#') return 1;
	else
	{
		if(symbol_stack.top() == '#') return -1;
		else
			return symbol_priority_map[symbol_stack.top()][symbol];	
	}
}

//根据算符计算数值
double Compute_express::calculate_value(char symbol,double value1,double value2)
{
	switch (symbol)
	{
		case '+':
			return value1 + value2;
		case '-':
			return value1 - value2;
		case '*':
			return value1 * value2;
		case '/':
			return value1 / value2;
	}
}
//计算最终结果
double Compute_express::compute()
{
	symbol_priority_array_to_map();
	symbol_stack.push('#');
	for(string::size_type i = 0;express.size() != i; i++)
	{
		if(isdigit(express[i]) || express[i] == '.')
		{
			value_string += express[i];
			if(isdigit(express[i+1]) || express[i+1] == '.')
			{
				if(express[i+1] == '.' && value_string.find('.') != string::npos) 
				{
					throw runtime_error("error double format!");
				}	
				else
					continue;
			}
			else		
				digital_stack.push(atof(value_string.c_str()));
		}
		else if(symbol_priority_map.find(express[i]) != symbol_priority_map.end() || express[i] =='#')
		{
			//将存放数字的字符串置空
			value_string = "";

			int pos = push_or_pop_symbol(express[i]);
			if(pos == 100) 
			{
				throw runtime_error("the express is not format,hava error symbol relation!");
			}
			else if(pos == -1)
			{
				symbol_stack.push(express[i]);
			}
			else
			{
				do
				{
					if(symbol_stack.top() == '#') 
					{
						return digital_stack.top();
					}
					else if(symbol_stack.top() == '(')
					{
						symbol_stack.pop();
						break;
					}
					else
					{
						double value2 = digital_stack.top();
						digital_stack.pop();
						double value1 = digital_stack.top();
						digital_stack.pop();
						double value = calculate_value(symbol_stack.top(),value1,value2);
						symbol_stack.pop();
						digital_stack.push(value);
					}
				}
				while(push_or_pop_symbol(express[i]) != -1);
				if(express[i] != ')') symbol_stack.push(express[i]);
			}
		}
		else
		{
			throw runtime_error("the express format is not right!");
		}
	}	
}
