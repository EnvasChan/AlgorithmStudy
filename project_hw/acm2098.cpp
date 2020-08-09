#include "선택.h"

#ifdef acm2098

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



/*
외 판 원 (바깥 파는 사람)
Traveling Salesperson Problem


1. DFS로 모든 경우를 다 탐색해서 답을 구하기
2. 휴리스틱 


*/

int n = 0;
int m_cost = 1600000000;
int w[17][17] = { 0 };
bool check[17] = { false };

void solve(int node, int cost,int count, int start_node)
{
    
    if (count == n-1)//종료조건 바꾸기 node가 아니라 총 간 노드의 수가 n일때로 교체
    {
        int final_cost = cost + w[node][start_node];
        if (m_cost > final_cost)
        {
            m_cost = final_cost;
        }
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (check[i] == true)
        {
            continue;
        }
      
        check[i] = true;
        solve(i, cost + w[node][i],count + 1,start_node);
        check[i] = false;
    }

}




int main()
{
    

    cin >> n;

    

    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            cin >> w[i][j];
        }
    }

    for (int i = 1; i < n +1; i++)
    {
        check[i] = true;
        solve(i, 0,0,i);
        check[i] = false;
    }
    cout << m_cost;















    return 0;
}

#endif