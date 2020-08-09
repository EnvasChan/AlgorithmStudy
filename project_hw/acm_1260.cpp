// https://www.acmicpc.net/problem/1260
#include "선택.h"



#ifdef ACM_1260

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> G[100];
vector<int> print, print_bfs;
bool V[100] = { false };
int N, M; // N = 컴퓨터의 개수 M = 쌍의 개수
int num = 0;


// 재귀함수: 임의의 함수가 자기 자신을 호출하면 그걸 재귀함수라고 함
// 스택: LIFO (마지막 들어간 친구가 제일 먼저 나옴)
// DFS가 스택 구조를 갖는 이유는: 마지막으로 실행한 함수가 제일 먼저 끝나는 순서기이기 때문에
void dfs(int node)//1번 노드가 들어오면
{
	V[node] = true;//여부 검사
	print.push_back(node);
	for (int i = 0; i < G[node].size(); i++)//인접 노드 검사
	{
		if (V[G[node][i]] == false)// 아직 안간 곳 이라면?
		{
			dfs(G[node][i]);//호출 
		}
	}
}

void bfs(int node)
{
	queue<int> q;
	q.push(1);
	V[1] = true;
	while (!q.empty())
	{
		int a = q.front();
		print_bfs.push_back(a);
		q.pop();
		for (int i = 0; i < G[a].size(); i++)
		{
			int next_node = G[a][i];
			if (V[next_node] == false)
			{
				q.push(next_node);
				V[next_node] = true;
			}
		}
	}
}

/*

-----------------------------------------------
   										  
-----------------------------------------------


*/
// 큐: FIFO (먼저 들어간 친구가 먼저 나옴)


int main()
{
	int A[10] = { 9, 7, 5, 10, 15, 1, -5, 3, -20, 100 };
	int num = 0;
	for(int i = 1; i < 11; i++)
	{
		for (int j = 1; j < 11; j++)
		{
			if (A[j] < A[j - 1])
			{
				num = A[j];
				A[j] = A[j - 1];
				A[j - 1] = num;
			}
		}
	
	};
	for (int i = 0; i < 10; i++)
	{
		cout << A[i] <<"  ";
	}
	

	/*int vc = 1;//바이러스 먹은 컴퓨터
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

	//dfs(1);
	//bfs(1);
	/*for (int i = 0; i < print_bfs.size(); i++)
	{
		cout << print_bfs[i];
	}
	*/
	
	return 0;
}


#endif