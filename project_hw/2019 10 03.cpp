#include "����.h"

/*
�׷��� �̷�
Ž��!

- �ʺ� �켱 Ž�� (BFS: Breadth First Search)
- ���� �켱 Ž�� (DFS:Depth First Search)






*/


#ifdef A2019_10_03


#include <iostream>
#include <vector>
using namespace std;

vector<int> G[101];
bool V[101] = { false, }; // �湮 ���� (ó���� �� false)
int N, M; // N = ��ǻ���� ���� M = ���� ����
int num = 0;

/**
@brief �� ��忡�� ������ ��ǻ���� ������ ��ȯ 
(�� �� �� �� ������ �ʴ´ٰ� ����)
*/
int dfs(int node) // Depth First Search
{
	int vc = 1;
	V[node] = true; // ���� node (1) �� �湮�߽��ϴ�.

	// ���� node�� ������ node �˻�
	for (int i = 0; i < G[node].size(); i++) 
	{
		// �湮 �߾���?? �α��ε�, �߾���???
		if (V[G[node][i]] == false) // G[node][i] (2)�� �湮�ߴ��� Ȯ��
		{
			vc += dfs(G[node][i]); // dfs(2), dfs(5), dfs(6), dfs(3) = 1
		}
	}

	return vc;
}

// dfs(1) --> �� ������ dfs�� ������� �ɰ��� Ǯ�ڽ��ϴ�.

// dfs(1) --> dfs(2) --> dfs(5) --> dfs(6)
//							    --> dfs(3)
int main()
{
	int vc = 1;//���̷��� ���� ��ǻ��
	cin >> N;
	cin >> M;
	
	// ���� �׷��� �����
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		// ��ȣ ����Ǿ� �ֱ� ������
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

	//for (int i = 0; i < G[1].size(); i++)// 1�� ��忡 ������ ��带 �����Ѵ�.
	//{
//		cout << G[1][i] << endl; //
//	}

	return 0;
}

#endif 