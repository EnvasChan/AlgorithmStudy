#include"선택.h"

// 첫줄에 M 과 N이 주어진다.  k개의 직사각형도 주어짐
// solve 함수가 뭘 하는지 
// 검사를 시작할 칸의 좌표를 받는다
// 종료조건은 더이상 이어진 집들이 없을때
// 1을 리턴받는다
// 종료조건이 아닐때는 0,0 
// 몇개가 이어져 있고  | 각 단지가 몇개로 이루어 져있는지를 1을 반환



#ifdef acm2667


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool arr[101][101];//칸
bool visit[101][101];//방문여부

int n, m, k;
//값을 받아서 인접 노드 검색
//연결되어있는지 연결되어있지 않은지 검사
// 연결되있다면 가고 아니면 안감
// return 해야할것 

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
		// 아이고 맙소사 우린 다 죽었어 아 혈압
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

	vector<int> areas;//넓이 저장
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
			if (arr[i][j] == false && visit[i][j] == false)// 색칠된 사각형 이외이 장소를 받는다면
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

		if (isSafe(new_x, new_y) == false)//예외 범위 처리
		{
			continue;
		}

		if (num[new_x][new_y] == 1) // 4방향 검사
		{
			area += solve(new_x, new_y); // 같은 곳이니 이곳으로 간다
			
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
		cout << ans[i]<< endl; // 아 ㅋㅋ 그럼 빨리 알려주세요 현기증 난단 말이에요
	}
	
}
*/







#endif 