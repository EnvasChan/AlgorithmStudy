#include "����.h"

#ifdef acm17608

//today problem: https://www.acmicpc.net/problem/17608

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	int n = 0;

	int block[100001] = { 0 };

	int h = 0;

	vector<int> num = { 0 }; // �迭�� ������ �μ����� ū �� ���� �����ϴ� ����

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> h;
		block[i] = h;
	}

	for (int i = 0; i < n; i++)
	{
		if (block[n -1] < block[i])
		{
			num.push_back(block[i]);
		}
	}

	sort(num.begin(), num.end());

	num.erase(unique(num.begin(), num.end()), num.end());


	for (int i = 0; i < num.size(); i++)
	{
		cout << "  " << num[i] << endl;
	}

	cout << "�� :"<< num.size();

	//complete



	return 0;
}




#endif 