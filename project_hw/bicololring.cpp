#include "선택.h"


#ifdef bicoloring

#include <iostream>
#include <vector>

using namespace std;

/*
문제: 입력된 그래프가 두 색으로 칠할 수 있는 그래프인지를 판단

0. 노드에 들어가서
0-1. 방문한 적이 없다면(색칠이 되어있지 않다면) ->색칠
0-2. 방문한 적이 있다면(색깔이 이전 노드와 색깔이 같다면) -> 안돼 return false
1. 인접한 노드가 있는지 없는지 판단
2. 인접한 노드가 있다면 0 으로 이동
3. 인접한 노드가 없다면
RETURN TRUE


즉 종료조건은  더이상 더 탐사할곳이 없을때 return ture를 해준다

전체문제
노드의 수와 간선의 수 지급되었을때 이것이 가능한지 불가능한지 판단

노드 한개를 사용(출발지)
 주어진 노드 한개와  간선한개씩 사용(새로 놓는 이 노드를 출발지와 다른색으로 설정)
  만약 노드와 간선 둘중 한개가 없다면 return false
주어진 노드와 간선을 모두 사용
return true
성공 예 노드 3개 간선 3개
실패 예 간선의 수가 노드의 수와 같거나 많거나, 노드의 수가 간선의 수보다 2개 이상 많을때 간선이 아예 없거나


 빨강 == 검정 == 빨강
  ||       ||
  검정    빨강
*/

/*

우선 노드가 3개 간선이 2개가 있다고 생각해보자
1.노드 하나 사용 이 노드는 빨간색과 검정색 둘중 아무 한색이다 (빨간색으로 설정)

2.간선 하나 사용 그리고 노드하나 사용(이 노드는 전 노드와 다른색이어야 한다 검정색)
반복
사용할수 있는 간선을 다 사용 할시
return true
*/

int no[200] = { 0 };
vector<int> adj_list[200];

bool solve(int node, int c)//현재노드 node 목표 색상 c
{
	if (no[node] == 0)
	{
		no[node] = c;
	}
	else
	{
		if (no[node] == c)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int new_color = c == 1 ? 2 : 1;
	
	//다음칸 검사
	for (int i = 0; i < adj_list[node].size(); i++)//현재칸과 인접한 노드 검사
	{
		if (solve(adj_list[node][i], new_color) == false)
		{
			return false;
		}
	}
	return true;
}


int main()
{
	int n = 0;
	int m = 0;
	int a = 0;//1번 노드
	int b = 0;//2번 노드
	int k = 0;
	cin >> n;
	cin >> m;

		/*
	우리가 인접한 노드들을 검사하는데에 사용해야 하잖아
	받는걸 왜 a랑 b 두번 해주는지 이유를 알아오고
	어떻게 사용하는지
	설명하시오.
	A만 값을 받으면 A는 B와 연결되있다고 일방적으로 나타내어진다
	마찬가지로 B만값을 받으면 B와 A가 일방적으로 연결되있다고 나타내어진다
	그러므로 A와B둘다 값을 받아야만 연결되있다고 설명할수있다.
	*/
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b; // a와 b가 연결돼 있다
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);

	}
	if (solve(0,1) == true)
	{
		cout << "OK";
	}
	else
	{
		cout << "impossible";
	}
	return 0;
}





#endif bicoloring
