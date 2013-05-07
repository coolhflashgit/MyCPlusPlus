#include "Compute_express.h"
void Compute_express::set_symbol_priority_array(vector< vector<int> > &array_arg)
{
	symbol_priority_array = array_arg;
}

void Compute_express::set_express(const string &string_arg)
{
express = string_arg;
}

void Compute_express::printtest()
{
	for(int symbol_type_i = 0;symbol_type_i<symbol_priority_array.size();symbol_type_i++)
 	{
		for(int symbol_type_j = 0;symbol_type_j<symbol_priority_array[symbol_type_i].size();symbol_type_j++)
		{
			cout << symbol_priority_array[symbol_type_i][symbol_type_j] << "\t";
 		}
		cout << endl;
	}
}

