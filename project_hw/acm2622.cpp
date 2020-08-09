#include "선택.h"
#ifdef acm2622
#include <iostream>
using namespace std;
/*
문제 나누기
주어진 성냥개비로 만들수 있는 서로 다른 삼각형을 모두 만들어라

삼각형이 만들어 지는 조건
예각 삼각형 : a^2 + b^2 > c^
둔각 삼각형 a^2 + b^2 < c^2
정삼각형 a = b = c 주어진 n을 3으로 나누면 
이등변 삼각형 a = b !=c 
직각삼각형 a^2 + b^2 = c^2

예외 조건
같은 모양의 삼각형들은 세지 않는다


 - 알고리즘
1. a 정함
2. b를 정해준다( b >= a)
3. c의 값을 정해준다 (c > b)

삼각형이 안 만들어지는 조건!! 수식
--> c > a + b

*/

// 입력을 받아보자
int n = 0; //성냥개비 갯수
//a + b+ c = n이다

//int a = 0;//그냥 변
//int b = 0;//a보다 크거나 a와 값이 같다
int c = 0;//a와 b보다 값이 크다
//규카츠ㅡㅡㅡㅡㅡㅡㅡ

int rn = 0;

int main()
{
	cin >> n;

	for (int a = 1; a <= n; a++)
	{
		// a = i;
		for (int b = a; b <= n; b++)
		{
			c = n - (a + b);
			if (c < b)
			{
				continue;
			}
			if (c > a + b)
			{
				continue;
			}
			else
			{
				// cout << "a:" << a <<"  " << "b:" << b << " " << "c:" << c << endl;
				rn += 1;
			}

		}
		
	}
	cout << rn;
	return 0;
}

#endif