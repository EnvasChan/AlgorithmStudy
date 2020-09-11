#include "선택.h"

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

	vector<int> num = { 0 }; // 배열의 마지막 인수보다 큰 수 들을 저장하는 벡터

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

	cout << "답 :"<< num.size();

	//complete



	return 0;
}




#endif 