#include "선택.h"
#ifdef acm2615
#include <iostream>
using namespace std;


/*

문제를 보고 난 소감:
어...... N-Q문제를 제한조건 더 준 느낌, 방대한 느낌, 생각 해야할 변수가 많은 느낌

--> 어... 어떻게 쪼개지??
--> 8방향ㅇ 움직이고 막....


특정 node를 검사한다:
 - 연결된 노드를 탐색한다 (1칸 옆에 있는거, 방향을 모두 탐색)
 --> 방향은
 {
	오른쪽 /오른쪽 아래/ 아래 /오른쪽 위/
	(1,0) / (1, -1) / (0,-1) / (1,1)
	int dx[4] = {1,  1,  0, 1};
	int dy[4] = {0, -1, -1, 1};

	for (int i=0; i<4; i++)
	{
		int new_x = x + dx[i];
		int new_y = y + dy[i];
	}

 }
 - 또 다음 노드를 검사할 때에는 "같은 방향"
 {
	같은 방향으로 간다면 변수 하나 지정해서 그변수의 값 1씩 증가시켜주기
	만약 그 변수의 값이 5가 되면 탈출! (return)
 }
 출력
  - 어떤 돌이 이겼는지 출력
  - 가장 첫 노드의 좌표 출력
  반복 노드
  - 첫번째 노드는 1번째 돌
  - 마지막 노드는 5번째 돌




여섯 알 이상이 되는지 어떻게 확일할 지 생각하가지
1. 언제 여섯 알 이상이 될지?

2. 그걸 어떻게 대처할 지?


*/
int k[20][20] = { 0 };
int dx[4] = { 1,  1,  0, 1 };
int dy[4] = { 0, 1, 1, -1 };
int new_x;
int new_y;
int a = 0;

bool isSafe(int x, int y)
{
	if (x < 1 || y < 1 || x >19 || y >19)
	{
		return false;
	}
	return true;
}
bool solve(int x, int y, int n, int l, int c)// n은 연속된 돌의 갯수, l은 방향, c는 색깔
{
	int new_x = x + dx[l];
	int new_y = y + dy[l];

	int befo_x = x- dx[l];
	int befo_y = y - dy[l];
	//cout << "n:" << n << endl;
	//cout << "x: " << x << " y: " << y << " color: " << k[y][x] << endl;
	//cout << "new_x: " << new_x << " new_y: " << new_y << " color: " << k[new_y][new_x] << endl;

	if (n == 0)
	{
		if (isSafe(new_x, new_y) == true)
		{
			if (k[befo_y][befo_x] == k[y][x])
			{
				return false;
			}
		}
	}

	if (n == 4) // 오목이 되어서 
	{
		if(isSafe(new_x, new_y) == true)
		{
			if (k[new_y][new_x] == k[y][x])
			{
				return false;
			}
		}
		return true;
	}
	
	if (isSafe(new_x, new_y) == false)
	{
		return false;
	}

	if (c != k[new_y][new_x])
	{
		return false;
	}

	return solve(new_x,new_y,n+1,l,c);

}
int main()
{

	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 19; j++)
		{
			cin >> k[i][j];
		}
	}
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 19; j++)
		{
			if (k[i][j] == 0)
			{
				continue;
			}
			for (int l = 0; l < 4; l++)
			{
				if (solve(j, i, 0, l,k[i][j]) == true)
				{
					cout << k[i][j] << endl;
					cout << i << ' ' << j << endl;
					return 0;
				}
			}
		
		}
	}
	cout << 0;
	return 0;
}
/*
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 1 2 0 0 2 2 2 1 0 0 0 0 0 0 0 0 0 0
0 0 1 2 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0
0 0 0 1 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 1 2 2 0 0 0 0 0 0 0 0 0 0 0 0
0 0 1 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
//////////////////////////////////////
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 1 2 0 0 2 2 2 1 0 0 0 0 0 0 0 0 0 0
0 0 1 2 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0
0 0 0 1 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 1 2 2 0 0 0 0 0 0 0 0 0 0 0 0
0 0 1 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

2 2 2 2 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 1 2 0 0 2 2 2 1 0 0 0 0 0 0 0 0 0 0
0 0 1 2 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0
0 0 0 1 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 1 2 2 0 0 0 0 0 0 0 0 0 0 0 0
0 0 1 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 1 2 0 0 2 2 2 1 0 0 0 0 0 0 0 0 0 0
0 0 1 2 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0
0 0 0 1 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 1 2 2 0 0 0 0 0 0 0 0 0 0 0 0
0 0 1 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 2
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 2
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 2
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 2
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 2

*/
#endif