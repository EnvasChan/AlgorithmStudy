#include "선택.h"
#ifdef knapsack
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;




// 무게와 만족도를 받는다
// 목록에서 하나하나 다 서로 검사해봄 경우의 수 2^n 
//이중 for문 돌려서 2중 for문 안에 if문으로 무게 초과하면 버림 요거 써놓고
// 목록 쫙 받음
//콜스택
//호출한다  축적



/*
2^n의 탐색이 자동으로 됨


solve
solve - yes or no --> 2 가지
solve - yes or no --> 2 가지의 경우의 수
main
--------
[1 2 3 4]

main
 -> solve(0)
	 -> solve(1) NO
		 -> solve(2) NO
			-> solve(3) NO 
				-> solve(4) NO --> 0
				-> solve(4) YES --> 4
			-> solve(3) YES
				-> solve(4) NO --> 3
				-> solve(4) YES --> 7
		 -> solve(2) YES
			-> solve(3) NO 
				-> solve(4) NO --> 2
				-> solve(4) YES --> 6
			-> solve(3) YES
				-> solve(4) NO --> 5
				-> solve(4) YES --> 9
	 -> solve(1) YES
		 -> solve(2) NO
			-> solve(3) NO 
				-> solve(4) NO --> 0
				-> solve(4) YES --> 4
			-> solve(3) YES
				-> solve(4) NO --> 3
				-> solve(4) YES --> 7
		 -> solve(2) YES
			-> solve(3) NO 
				-> solve(4) NO --> 2
				-> solve(4) YES --> 6
			-> solve(3) YES
				-> solve(4) NO --> 5
				-> solve(4) YES --> 9

				*/
int w, n, a, b;
int max_value = 0;
int current_value = 0;
int current_weight = 0;
int value[22];
int weight[22];

//담지 않을지 담을지


int nax = 0;


int solve(int num)
{
	if (num == n)

	{
		if (current_value > nax)
		{
			nax = current_value;
		}
		return;
	}

	for (int i = 0; i < 2; i++)
	{
		current_value  += i * value[num];
		solve(num + 1);
		current_value  -= i * value[num];
	}
}



int main()

{
	cin >> w >> n;

	
	for (int i = 0; i < n; i++)//입력
	{
		cin >> weight[i] >> value[i];
	}


	return 0;
}






























































#endif