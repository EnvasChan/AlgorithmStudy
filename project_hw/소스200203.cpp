

#include "선택.h"


#ifdef C200203

#include <iostream>
using namespace std;

/*
1.연못 폭 입력 가로 세로 길이
2.그물의 폭 입력 가로 세로 길이
3. 한 칸의 물고기 수









*/

int main()
{
	int n = 4;
	int m = 0;
	int k = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 2; j < n; j++)
		{
			cout << i << j<< endl;
		}
		
	}
	return 0;
}


/* 복습한 쓰레기
int n, m = 0;//연못의 폭
int w, h = 0;//그물의 폭
int fish[100][100] = { 0 };
int ans = 0;
int k = 0;
cin >> n >> m;
cin >> w >> h;

for (int i = 0; i < n; i++)
{
	for (int j = 0; j < m; i++)
	{
		cin >> fish[i][j];
	}
}
for (int x = 0; x < n - w + 1; x++)
{
	for (int y = 0; y < m - h + 1; y++)
	{
		for (int i = 0; i < w; i++)
		{
			for (int j = 0; j < h; j++)
			{
				k += fish[i + x][j + y];
			}
		}
	}
	if (k > ans)
	{
		ans = k;
	}
}
*/




































//
//int main()
//{
//	int n, m = 0;//연못의 폭
//	int w, h = 0;//그물의 폭
//	int fish[100][100] = { 0 };
//	int ans = 0;
//	int k = 0;
//	cin >> n >> m;
//	cin >> w >> h;
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; i++)
//		{
//			cin >> fish[i][j];
//		}
//	}
//
//	for (int x = 0; x < n - w + 1; x++)
//	{
//		for (int y = 0; y < m - h + 1; y++)
//		{
//			// x와 y가 (시작점) 주어졌을 때 그물이 차지하는 곳의 가치를 구할 수 있음
//			int value = 0;
//			for (int i = 0; i < w; i++)
//			{
//				for (int j = 0; j < h; j++)
//				{
//					value += fish[i + x][j + y];
//				}
//			}
//			if (value > ans)
//			{
//				ans = value;
//			}
//		}
//	}
//
//	cout << ans;
//	return 0;
//}

#endif