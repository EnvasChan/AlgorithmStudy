

#include "선택.h"
/*
일단 한 명을 정하고
주변 칸에 다른 닿지 않는 애를 하나 더 둠

따지고 보면

여덟방향이구나

칸에 한 명을 두고

두 명의 여덟 칸 사이에 또 두고


1. 개념설계
2. 알고리즘 설계


a. 하나를 둔다
b. 8방향 검사한다
c. 빗나가는 칸에 다음 것을 둔다
d. 반복? 어떤걸?


가정 생성:
a.n번쨰 줄에 퀸이 생성되면 다음퀸은 n + 1줄에 반드시 생성됨

*/
#ifdef C200118

#include <iostream>
using namespace std;

int n = 0;
int k = 0;
int col[15] = { 0 };
int rd[30] = { 0 };
int ld[30] = { 0 };



viod 복습(int r = 0;)
{
	if (r == n)
	{
		k += 1;//줄이 끝까지 갔을떄  경우의 수 하나 늘려준다
		return;// 그리고 값을 리턴해준다 종료조건
	}

	for (int i = 0; i < n; i++)
	{
		if (col[i] == 1 || id[r + i] || rd[(n - 1) + i - r] == 1)
		{
			continue;// 범위안에 있을경우 옆칸 검사
		}
	}
	//설정 



	// 다음 경우의 수를 구하기 위해 초기화
}














int main()
{
	cin >> n;
	solve(0);
	cout << k;

	return 0;
}

/*
void solve(int r)
{

	if (r == n)
	{
		k += 1;
		return;
	}

	for (int i = 0; i < n; i++)// 경우의 수 for문
	{
		// 종료 조건
		if (col[i] == 1 || ld[r + i] == 1 || rd[(n - 1) + (i - r)] == 1)
		{
			continue;
		}
		// 설정
		col[i] = 1;
		ld[r + i] = 1;
		rd[(n - 1) + (i - r)] = 1;

		solve(r + 1);

		// 복구
		col[i] = 0;
		ld[r + i] = 0;
		rd[(n - 1) + (i - r)] = 0;
		//세로 i번 i +1 은 오른쪽 대각선 세로 i번  i -1 은 왼쪽 대각선
	}
}
*/

#endif