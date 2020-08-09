#include "선택.h"
#ifdef acm15649
#include <iostream>
using namespace std;
/*
가정
1. 전체탐색 문제

2. 수열에서 만들고 있는 숫자를 k번째 라고 할때 k 번째 숫자 그다음은 k + 1의 숫자를 만든다

풀이 방식

똑같은 수가 있는지 없는지 확인 

없으면 값 넣고 있으면 2번째 칸으로 넘어감

한줄에 칸 확인이 끝났으면 다음 줄로 넘어감



제한조건
2. 똑같은 수는 한번만 사용될 수 있음

3. 한 수열은 총 m개의 숫자를 가진다.






*/
int result[10] = { 0, };

int n = 4;
int m = 4;

void solve(int k) // r -> k
{
	if (k == m)
	{
		// 만들어진 수열 출력
		for (int i = 0; i < m; i++)
		{
			cout << result[i] << " ";
		}
		cout << endl;
		return;
	}


	for (int i = 1; i <= n; i++)//이미 이 칸에 도장이 있는지 확인
	{
		// 제한 조건
		// 지금 k번째를 검사하고 있다면 1 ~ k -1 까지 중복되는 수가 있는지 검사한다 
		bool found = false;
		for (int j = 0; j < k; j++)
		{
			if (result[j] == i)
			{
				found = true;
				break;
			}
		}
		if (found) continue;
		
		//이 숫자에 들어 왔었다 도장을 찍어주고
		result[k] = i;

		solve(k + 1);

		//도장을 지워준다
		result[k] = 0;
	}
}


int main()
{
	

	solve(0);








	return 0;
}



#endif // acm15649
