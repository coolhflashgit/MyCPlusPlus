#include "Compute_express.h"
#include <iostream>
//using namespace std;
int main()
{
	//行分别为 + - * / （ ）
	//列分别为 + - * / （ ）
	int symbol_array[6][6] = {{1,1,-1,-1,-1,1},
							  {1,1,-1,-1,-1,1},
							  {1,1,1,1,-1,1},
							  {1,1,1,1,-1,1},
							  {-1,-1,-1,-1,-1,0},
							  {1,1,1,1,100,1}};
	Compute_express ce;
	vector< vector<int> > temp_arg;
	for(int i = 0;i < 6;i++)
	{
		vector<int> inner_temp_arg;
		for(int j = 0;j < 6;j++)
		{
			inner_temp_arg.push_back(symbol_array[i][j]);
		}
		temp_arg.push_back(inner_temp_arg);
	}
	ce.set_symbol_priority_array(temp_arg);
	ce.printtest();
//	cout << "1" <<endl;
	return 0;
}
