#include "����.h"

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
	q.push(1); // 1�� ù��° �����, 1�� push����.
	V[1] = true;
	
	while (!q.empty())
	{
		int cur = q.front(); // ť���� �� ���� ģ�� (������ ������ ��)
		q.pop();

		for (int i = 0; i < G[cur].size(); i++)	// G[cur] cur ����� ������ ��� ���
		{
			int next_node = G[cur][i];
			// if (���� ������ ���)
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
