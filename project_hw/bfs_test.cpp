#include "선택.h"

#ifdef BFS_TEST

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*




*/


vector<int> G[101];
bool V[101];	



// 1 2 3 4 5 6 7 8
// Stack // Last in First out : LIFO
void bfs()
{
	// First in First out: FIFO
	queue<int> q; // {}
	q.push(1); // 1이 첫번째 노드라면, 1을 push해줌.
	V[1] = true;
	
	while (!q.empty())
	{
		int cur = q.front(); // 큐에서 막 나올 친구 (뽑으면 나오는 애)
		q.pop();

		for (int i = 0; i < G[cur].size(); i++)	// G[cur] cur 노드의 인접한 노드 목록
		{
			int next_node = G[cur][i];
			// if (접근 가능할 경우)
			if (V[next_node] == false)
			{
				q.push(next_node);
				V[next_node] = true;
			}
		}
	}
}


int main()
{


	return 0;
}







#endif // BFS_TEST
