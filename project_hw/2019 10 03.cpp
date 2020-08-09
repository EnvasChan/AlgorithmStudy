#include "선택.h"

/*
그래프 이론
탐색!

- 너비 우선 탐색 (BFS: Breadth First Search)
- 깊이 우선 탐색 (DFS:Depth First Search)






*/


#ifdef A2019_10_03


#include <iostream>
#include <vector>
using namespace std;

vector<int> G[101];
bool V[101] = { false, }; // 방문 여부 (처음엔 다 false)
int N, M; // N = 컴퓨터의 개수 M = 쌍의 개수
int num = 0;

/**
@brief 그 노드에서 감염된 컴퓨터의 개수를 반환 
(한 번 들어간 건 나오지 않는다고 가정)
*/
int dfs(int node) // Depth First Search
{
	int vc = 1;
	V[node] = true; // 현재 node (1) 를 방문했습니다.

	// 현재 node와 인접한 node 검사
	for (int i = 0; i < G[node].size(); i++) 
	{
		// 방문 했었니?? 인근인데, 했었어???
		if (V[G[node][i]] == false) // G[node][i] (2)를 방문했는지 확인
		{
			vc += dfs(G[node][i]); // dfs(2), dfs(5), dfs(6), dfs(3) = 1
		}
	}

	return vc;
}

// dfs(1) --> 이 문제를 dfs의 조각들로 쪼개서 풀겠습니다.

// dfs(1) --> dfs(2) --> dfs(5) --> dfs(6)
//							    --> dfs(3)
int main()
{
	int vc = 1;//바이러스 먹은 컴퓨터
	cin >> N;
	cin >> M;
	
	// 인접 그래프 만들기
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		// 상호 연결되어 있기 때문에
		G[a].push_back(b);
		G[b].push_back(a);
	}

	vc = dfs(1) - 1;

	cout << vc << endl;

	// G[1] = {2, 5}
	// G[2] = {1, 5, 3}
	// G[3] = {2}
	// G[4] = {7}
	// G[5] = {1, 2, 6}

	//for (int i = 0; i < G[1].size(); i++)// 1번 노드에 인접한 노드를 조사한다.
	//{
//		cout << G[1][i] << endl; //
//	}

	return 0;
}

#endif 