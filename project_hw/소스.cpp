#include "선택.h"


#ifdef 소스

#include<iostream>
#include<math.h>
using namespace std;

// https://www.acmicpc.net/problem/2960
int main()
{
	int j = 0;
	int N, K;
	cin >> N;
	cin >> K;
	int num[1000] = { 0 };
	// STEP 1
	for (int i = 2; i <= N; i++)
	{
		num[i] = i;
		
	}
	
	bool sol_found = false;

	while (sol_found == false)
	{
		// STEP 2
		int P = 2;
		for (int i = 0; i <= N; i++)
		{
			if (num[i] != 0)
			{
				P = i;
				break;
			}
		}
		//STEP3
		for (int i = 1; P * i <= N; i++)
		{
			// P * i
			if (num[P * i] == 0)
			{
				continue;
			}
			num[P * i] = 0;
			j += 1;
			if (K == j)
			{
				cout << P * i;
				sol_found == true;
				break;
			}
		}		
	}//개불쌍

	return 0;
}

/*
int main()
{
	int num[100] = { 0 };
	int num1[100] = { 0 };
	int n = 0;
	int a = 0;
	int num2 = 0;//맞으면 올라가는 놈
	cin >> a;//바구니 갯수
	
	
	for (int i = 0; i < a; i++)
	{
		cin >> n;
		num[i] = n;
	}

	cin >> a;//바구니 갯수

	for (int i = 0; i < a; i++)
	{
		cin >> n;
		num1[i] = n;
		for (int c = 0; c < a; c++)
		{
			if (num[i] == num1[c])
			{
				num2 = 1;
			}
			else
			{
				num2 = 0;
			}	
			cout << "정답" << num2 << endl;
		}
		
		
	}
	return 0;
}
*/
/*
int main()
{
	int n = 0;
	cin >> n;
	int a = (n*(n-1)*(n-2)*(n-3)) / 24;

	cout << a;
	return 0;
}
/*
//a층의 b호에 사려면 a -1층의 1호부터 b호 까지 사람들의 수의 합만큼 데려와 살아야 한다.
int main()
{
	int T;
	int k[14] = { 0 };//층수
	int n;//호수


	int num[14] = { 0 };//사람의 인원
	int num1 = 0;//사람의 인원을 저장함

	cin >> k[0];
	cin >> n;



	for (int i = 1; i <= n; i++) //0 층에 입력한 호수
	{
		num1 += 1;
		num[i] = num1;
		
		cout << num1 << endl;
	}
	cout << num1;
	return 0;
}






/*
int main()
{

	int x, y, w, h;
	int num = 0;

	cin >> x;
	cin >> y;
	cin >> w;
	cin >> h;
	
	int length[4];

	length[0] = abs(w - x);
	length[1] = abs(h - y);
	length[2] = abs(x);
	length[3] = abs(y);
	
	num = length[0];
	for (int i = 1; i < 4; i++)
	{
		if (length[i] < num)
		{
			num = length[i];
		}
		}

		cout << num;

		/*
		// 위쪽, 오른쪽 변과의 거리
	int w2 = abs(w - x);
	int h2 = abs(h - y);

	// 아래쪽 왼쪽 변과의 거리
	int w1 = abs(x);
	int h1 = abs(y);

	if (abs(x) - abs(w) > abs(y) - abs(h))
	{
		cout << abs(num);
	}
	else
	{
		cout << abs(num2); 
	}
	*/





/*
int main()
{
	int n = 0;
	int num = 1;
	
	cin >> n;

	for (int i = 1; i < n; i++)
	{
		num *= i;	
	}

	cout << num;
	return 0;
}
*/

#endif 