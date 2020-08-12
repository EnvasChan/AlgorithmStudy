#include "º±≈√.h"

#ifdef TSP_200811
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n = 0;
int a = 0;
vector<double> loc[1001];
int m_dis = 32000;
bool gate[1001] = { false };

void tsp(int node, double dis, int num, int start_node)
{
	if (node == n-1)
	{
		double final_dis = dis + sqrt(pow(loc[node][0] - loc[start_node][0], 2) +
			pow(loc[node][1] - loc[start_node][1], 2));
		if (m_dis > final_dis)
		{
			m_dis = final_dis;
		}
		return;
	}


	for (int i = 0; i < n; i++)
	{

		if (gate[i] == true)
		{
			continue;
		}

		gate[i] = true;
		tsp(i, dis + sqrt(pow(loc[node][0] - loc[i][0], 2) +
			pow(loc[node][1] - loc[i][1], 2)), num + 1, start_node);
		gate[i] = false;
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

	for (int i = 0; i < n; i++)
	{
		gate[i] = true;
		tsp(i, 0, 0, i);
		gate[i] = false;
	}
	cout << m_dis;


}



#endif

