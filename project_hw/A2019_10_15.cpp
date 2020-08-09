// https://www.acmicpc.net/problem/2667

#include "����.h"
#include <iostream>
#include <vector>
using namespace std;
// ���� �׷���
// (�迭) 
// ���� Ž��

//���� �׷���
// ���(����)�� ����(����)�� ���� �� �������� �׷���
// Ž�� �ÿ� Ư���� �˰��� �ʿ� 
// DFS, BFS

// ���� �߿��� ������������~~~
// (�ʼ��ʼ�) 1. DFS �Ⱥ��� �ٽ�¥���� (���̷��� ���� �ٽ� Ǯ���!!) �� ������ �� Ƽ��
// 2. ���� ��� for��? (32~25����), �߰� ���� ���� ���� (for�� 1���� ����)
// 3. �� �ϰ� �ð��� ���´� --> �̰� ���� �� Ǯ��� (dfs ���踸)
// 4. 3���� ���ߴ�. -> ������ ������ ���� Ǯ��� (https://www.acmicpc.net/problem/1026)

#ifdef A2019_10_15

// �� ������ �� ��� �پ��ִ���

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

		// new_x, new_y�� ���� �ȿ� �ִ��� Ȯ��
		// �ȿ� ������ continue;
		if (new_x < 0 || new_y < 0 || new_x >= N || new_y >= N)//������ ��� ���ܸ� ó���� �ִ� ���ѳ�
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