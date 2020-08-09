// https://www.acmicpc.net/problem/1260
#include "����.h"



#ifdef ACM_1260

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> G[100];
vector<int> print, print_bfs;
bool V[100] = { false };
int N, M; // N = ��ǻ���� ���� M = ���� ����
int num = 0;


// ����Լ�: ������ �Լ��� �ڱ� �ڽ��� ȣ���ϸ� �װ� ����Լ���� ��
// ����: LIFO (������ �� ģ���� ���� ���� ����)
// DFS�� ���� ������ ���� ������: ���������� ������ �Լ��� ���� ���� ������ �������̱� ������
void dfs(int node)//1�� ��尡 ������
{
	V[node] = true;//���� �˻�
	print.push_back(node);
	for (int i = 0; i < G[node].size(); i++)//���� ��� �˻�
	{
		if (V[G[node][i]] == false)// ���� �Ȱ� �� �̶��?
		{
			dfs(G[node][i]);//ȣ�� 
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
// ť: FIFO (���� �� ģ���� ���� ����)


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
	

	/*int vc = 1;//���̷��� ���� ��ǻ��
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