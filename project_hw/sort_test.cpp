#include"º±≈√.h"
#ifdef sort_test

// It is

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct weapon
{
	int str;
	int rare;
	string name;

	void print_info()
	{
		cout << "name is :" << name <<endl
			<<"rare :" << rare << endl
			<< "str :" << str << endl;
	}

};

bool num(int a, int b)
{
	return a < b;
}

int main()
{
	weapon a[3] = { {100,5,"sword"},{1000,8,"axe"},{400,20,"arrow"} };
	for (int i = 0; i < 3; i++)
	{
		a[i].print_info();
	}
	weapon b;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{ 
			if (a[j].rare < a[j+1].rare)
			{
				b = a[j];
				a[j] = a[j + 1];
				a[j + 1] = b;
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		a[i].print_info();
	}

	vector<int> V;
	V.push_back(1);
	V.push_back(8);
	V.push_back(4);
	
	for (int i = 0; i < 3; i++)
	{
		cout << V[i] << " ";
	}
	cout << endl;
	sort(V.begin(), V.end(),num);
	for (int i = 0; i < 3; i++)
	{
		cout << V[i] << " ";
	}
	return 0;
}
#endif // 