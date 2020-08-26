#include "º±≈√.h"

#ifdef TSP_200811
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;

int n = 0;
int a = 0;
vector<double> loc[1001];
double m_dis = 32000;
bool gate[1001] = { false };


/*

f(x) = 7x + 8
y = f(x) + 3


double f(double x)
{
	return 7 * x + 8;
}

*/


void tsp(int node, double dis, int num, int start_node)
{
	double best_dis = dis + sqrt(pow(loc[node][0] - loc[start_node][0], 2) +
		pow(loc[node][1] - loc[start_node][1], 2));

	if (best_dis > m_dis)
	{
		return;
	}

	if (num == n-1)
	{
		if (m_dis > best_dis)
		{
			m_dis = best_dis;
		}
		return ;
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
	cout << std::setprecision(std::numeric_limits<double>::digits10 + 1) <<
		m_dis << endl;
}


#endif

