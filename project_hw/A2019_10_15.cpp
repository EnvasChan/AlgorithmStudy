// https://www.acmicpc.net/problem/2667

#include "선택.h"
#include <iostream>
#include <vector>
using namespace std;
// 선형 그래프
// (배열) 
// 이진 탐색

//비선형 그래프
// 노드(정점)와 엣지(간선)를 갖는 비 선형적인 그래프
// 탐색 시에 특수한 알고리즘 필요 
// DFS, BFS

// 제일 중요한 숙제에에에에~~~
// (필수필수) 1. DFS 안보고 다시짜보기 (바이러스 문제 다시 풀어보기!!) 답 베끼면 다 티남
// 2. 저걸 어떻게 for문? (32~25라인), 추가 변수 선언 가능 (for문 1개만 제한)
// 3. 다 하고 시간이 남는다 --> 이거 문제 좀 풀어보기 (dfs 설계만)
// 4. 3까지 다했다. -> 저번에 보내준 문제 풀어보기 (https://www.acmicpc.net/problem/1026)

#ifdef A2019_10_15

// 한 단지에 집 몇개가 붙어있는지

int N;

bool V[26][26] = { false };

int M[26][26] = { 0, };

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int dfs(int x, int y)
{
	int apt;
	apt = 1;
	V[x][y] = true;
	
	for (int i = 0; i < 4; i++)
	{
		int new_x, new_y;
		new_x = x + dx[i];
		new_y = y + dy[i];

		// new_x, new_y가 범위 안에 있는지 확인
		// 안에 없으면 continue;
		if (new_x < 0 || new_y < 0 || new_x >= N || new_y >= N)//범위를 벗어난 예외를 처리해 주는 착한놈
		{
			continue;
		}
		
		if (V[new_x][new_y] == false && M[new_x][new_y] == 1)
		{
			apt += dfs(new_x, new_y);
		}	
	}
	return apt;
}


int main()
{
	int mem = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%1d", &M[j][i]);
			// cin >> M[i][j];
		}
	}
	
	vector<int> num;

	


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (M[j][i] == 1 && V[j][i] == false)
			{
				int result = dfs(j, i);
				num.push_back(result);
			}
		}
	}

	for (int i = 0; i < num.size(); i++)
	{
		for (int j = 0; j < num.size() - 1; j++)
		{
			if (num[i] > num[i + 1])
			{
				mem = num[i];
				num[i + 1] = num[i];
				num[i] = mem;

			}
		}
	}

	cout << num.size() << endl;
	for (int i = 0; i < num.size(); i++)
	{
		cout << num[i] << endl;
	}
	
	// 5 8 1 3
	// 1 3 5 8
	return 0;
	
}
/*
	int s[100] = { 0 };
	int s2[100] = { 0 };
	int num = 0;
	int count = 0;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> s[i];
	}
	for (int i = 0; i < num; i++)
	{
		cin >> s2[i];
	}
	for (int i = 0; i < num; i++)
	{
		count += s[i] - s2[i];
	}
	cout << count;
	return 0;
	*/


#endif