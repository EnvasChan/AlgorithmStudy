#include "����.h"

#ifdef acm2098

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



/*
�� �� �� (�ٱ� �Ĵ� ���)
Traveling Salesperson Problem


1. DFS�� ��� ��츦 �� Ž���ؼ� ���� ���ϱ�
2. �޸���ƽ 


*/

int n = 0;
int m_cost = 0;
int w[17][17] = { 0 };
bool check[17] = { false };

void solve(int node, int cost,int count)
{
    
    if (count == n)//�������� �ٲٱ� node�� �ƴ϶� �� �� ����� ���� n�϶��� ��ü
    {
        if (m_cost > cost)
        {
            m_cost = cost;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (check[i] == true)
        {
            continue;
        }
      
        check[node] = true;
        solve(i, cost + w[node][i],count + 1);
        check[node] = false;
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
        solve(i, 0,0);
    }
    cout << m_cost;















    return 0;
}

#endif