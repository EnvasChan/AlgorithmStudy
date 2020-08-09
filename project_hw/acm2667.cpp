#include"����.h"

// ù�ٿ� M �� N�� �־�����.  k���� ���簢���� �־���
// solve �Լ��� �� �ϴ��� 
// �˻縦 ������ ĭ�� ��ǥ�� �޴´�
// ���������� ���̻� �̾��� ������ ������
// 1�� ���Ϲ޴´�
// ���������� �ƴҶ��� 0,0 
// ��� �̾��� �ְ�  | �� ������ ��� �̷�� ���ִ����� 1�� ��ȯ



#ifdef acm2667


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool arr[101][101];//ĭ
bool visit[101][101];//�湮����

int n, m, k;
//���� �޾Ƽ� ���� ��� �˻�
//����Ǿ��ִ��� ����Ǿ����� ������ �˻�
// ������ִٸ� ���� �ƴϸ� �Ȱ�
// return �ؾ��Ұ� 

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

bool issafe(int x, int y)
{
	if (x < 0 || x > n -1 || y < 0 || y > m - 1)
	{
		return false;
	}
	return true;
}

int solve(int x, int y)
{
	visit[x][y] = true;
	int area = 1;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		// ���̰� ���һ� �츰 �� �׾��� �� ����
		if (!issafe(nx, ny))
			continue;
		if (arr[nx][ny] == false && visit[nx][ny] != true)
		{
			area += solve(nx, ny);
		}
	}
	return area;
}
int main()
{

	vector<int> areas;//���� ����
	cin >> m >> n >> k;

	while (k--)
	{
		int x1, x2, y1, y2;
			cin >> x1 >> y1 >> x2 >> y2;
		for (int i = x1; i < x2; i++)
		{
			for (int j = y1; j < y2; j++)
			{
				arr[i][j] = true;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == false && visit[i][j] == false)// ��ĥ�� �簢�� �̿��� ��Ҹ� �޴´ٸ�
			{
				areas.push_back(solve(i,j));
			}
		}
	}
	sort(areas.begin(), areas.end());

	cout << areas.size() << endl;
	for (int i = 0; i < areas.size(); i++)
	{
		cout << areas[i] << " ";
	}
		
	return 0;
}

/*
int n;
int num[26][26] = { 0 };
int dx[4] = {1, -1, 0 ,0};
int dy[4] = {0, 0, 1 ,-1};
int a = 0;
int b[26] = { 0 };
int c = 0;

bool isSafe(int x, int y)
{
	if (x < 0 || x > n || y < 0 || y > n)
	{
		return false;
	}
	return true;
}

int solve(int x, int y)
{
	int area = 1;
	num[x][y] = 0;
	for (int i = 0; i < 4; i++)
	{
		int new_x = x + dx[i];
		int new_y = y + dy[i];

		if (isSafe(new_x, new_y) == false)//���� ���� ó��
		{
			continue;
		}

		if (num[new_x][new_y] == 1) // 4���� �˻�
		{
			area += solve(new_x, new_y); // ���� ���̴� �̰����� ����
			
		}
	}
	return area;
}



int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string line;
		cin >> line;
		for (int j = 0; j < n; j++)
		{
			int value = line[j] - '0';
			num[i][j] = value;
		}
	}
	vector<int> ans;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			
			if (num[i][j] == 1)
			{
				ans.push_back(solve(i, j));
				a = ans.size();
		
			}
		}
	}
	cout << a << endl;

	/*
	for (int i = 0; i < ans.size(); i++)
	{
		for (int j = 0; j < ans.size() -1; j++)
		{
			if (ans[j] > ans[j + 1])
			{
				c = ans[j];
				ans[j] = ans[j + 1];
				ans[j + 1] = c;
			}
			
		}
		
	}
	

	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i]<< endl; // �� ���� �׷� ���� �˷��ּ��� ������ ���� ���̿���
	}
	
}
*/







#endif 