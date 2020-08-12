#include "º±≈√.h"

#ifdef TSP_200811
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n = 0;
int a = 0;
vector<double> loc[1001] = { 0 };
int m_dis = 32000;

int tsp(int node, double dis, int num, int start_node)
{
	double final_dis = dis + sqrt((loc[node][0] - loc[start_node][0])^2 + 
		(loc[node][1] - loc[start_node][1]) ^ 2);
	if (node == n)
	{
		if (m_dis > final_dis)
		{
			m_dis + final_dis;
		}
	}

	for (int i = 0; i < n; i++)
	{

	}
}









int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> a;
			loc[i].push_back(a);
		}
	}

}



#endif TSP_200811

