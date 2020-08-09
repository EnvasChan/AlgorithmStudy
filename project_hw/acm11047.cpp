#include "선택.h"
// 값을 받아서 큰값 부터 차례대로 쯕 빋는다
// 큰값부터 받은 값들을 되는대로 다 처박는다
// 그러다가 현재 값이 k가 된다면 지금까지 사용한 동전의 개수를 출력하고 끝낸다.

#ifdef acm11047
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int n;
int k[11] = { 0 };
int num;

int max_value = 0;
int current_value = 0;//동전 값
int current_weight = 0;//동전개수
int value = 0;
int current_money = 0;
int weight[22];

// 1. 최적 부분 문제
// 1,5,10원 있을 때
// 17 -> 1 1 5 10
// 27 -> 1 1 5 10 10

// 2. 욕심쟁이 성질
// 

void solve(int nn,int money)
{
	
	if (money == 0)
	{
		cout << value;
		return;
	}

	//지려 나는 최고야 나란남자 
	
	
	if (k[nn] > money)
	{
		solve(nn + 1,money);//아;; 돈 못쓰네 더 적은 돈 갖고와
	}
	else
	{
		value += 1;
		solve(nn, money - k[nn]);// 어우 딱맞누 여기 돈 있습니다, 잠깐만요 이 돈 한번 더 쓸 수 있나요
	}
}




int main()
{
	cin >> n;
	cin >> current_money;


	for (int i = n - 1; i >= 0; i--)
	{
		cin >> num;
		k[i] = num;
	}
	solve(0, current_money);
	return 0;
}

#endif // {0}