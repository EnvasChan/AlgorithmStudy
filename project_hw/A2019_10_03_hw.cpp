#include "º±≈√.h"
#ifdef A2019_10_03_hw
#include<iostream>
using namespace std;
int main()
{
	int a = 7;
	int b = 0;
	int c = 0;

	int k = 39;
	int l = 42;

	int rem = k % l;
	int i;
	for (i = 0; i < a; i++)
	{
		if (a - 3 * (i + 1) < 0)
		{
			break;
		}
	}
	c = a - 3 * i;
	for (int i = 0; i < a; i++)
	{
		b += 3;
		c += 1;
		if (b >= a)
		{
			break;
		}
	}
	if (a != b)
	{
		b -= 3;
	}
	cout << a - b;
	return 0;
}




#endif 