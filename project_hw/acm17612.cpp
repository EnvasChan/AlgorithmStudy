#include "선택.h"

//today problem : https://www.acmicpc.net/problem/17612

#ifdef acm17612

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 고객 한명은 아이디값과 물건의 수를 가지고 있어야함.

int k = 0;//k의값만큼 계산대가 있다.
int n = 0;
vector<int>costomer[1000000];
int id = 0;
int w = 0;
vector<int> bg[100000];//계산대 buy gate 약자

int main()
{
    cin >> n;
    cin >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> id;
        cin >> w;

        costomer[i].push_back(id);//고객에게 아이디값 주기
        costomer[i].push_back(w);//고객에게 물건의 수 주기

    }

    for (int i = 0; i < n; i++)
    {
        if (i <= k)
        {
            bg[i].push_back(costomer[i][0]);
            bg[i].push_back(costomer[i][1]);
            continue;
        }
        


        for (int j = 0; j < k; j++)//기다리는 시간이 같을때 더 번호가 작은 곳으로 보내는 코드
        {
            for (int m = 0; m < k; m++)
            {
                if (bg[j][1] == bg[m][1])
                {
                    if ( j > m)
                    {
                        bg[m][1] += costomer[i][1];
                    }
                    else
                    {
                        bg[j][1] += costomer[i][1];
                    }
                    continue;
                }
           }
        }

        //순서대로 처넣음


    }

    for (int i = 0; i < n; i++)
    {
        cout << bg[i][0] << endl;
        cout << bg[i][1] << endl;
    }
    return 0;
}

//결제데스크에 순서를 붙힘

/*

계산대

계산대     111111111

계산대

*/

//먼저 온놈부터 계산한다.

//K번째 고객까지는 먼저온놈부터 쳐넣는다.

// 같은 대기시간일 경우 값이 낮은 순서 데스크로 보냄.

//아니면 순서대로 처넣음

//계산이 동시에 끝난다면 높은 계산대부터 빠져나감

//물건이 많은 놈이 높은번호 

// 가장 물건이 많은놈의 회원정보 * 1 
#endif