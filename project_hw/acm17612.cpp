#include "선택.h"

//today problem : https://www.acmicpc.net/problem/17612

#ifdef acm17612

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 고객 한명은 아이디값과 물건의 수를 가지고 있어야함.

int k = 0;//k의값만큼 계산대가 있다.
int n = 0;

struct customer
{
    int id;
    int weight;
    int counter;
};


vector<customer> customers;
vector<pair<int, int>> counter[100001];
int id = 0;
int w = 0;
int sw[100001] = { 0 };













int main()
{
    cin >> n;
    cin >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> id;
        cin >> w;

        customers.push_back({ id, w, 0 });

    }

    
    

    for (int i = 0; i < n; i++)
    {
        if (i <= k)
        {
            counter[i].push_back(make_pair(customers[i].id, customers[i].weight));
            continue;
        }


        for (int j = 0; j < k; j++)//기다리는 시간이 같을때 더 번호가 작은 곳으로 보내는 코드
        {
            for (int m = 0; m < k; m++)
            {
                if (sw[j]== sw[m]) 
                {
                    if ( j > m)
                    {
                        counter[m].push_back(make_pair(customers[i].id, customers[i].weight));
                    }
                    else
                    {
                        counter[j].push_back(make_pair(customers[i].id, customers[i].weight));
                    }
                    continue;
                }
           }
        }


        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < counter[i].size(); j++)
            {
                sw[i] += counter[i][j].first;
            }
        }





        //가장 시간이 적게 걸리는곳에 처넣음
        //k개 만큼 검사를 해야함

        // sw중에 가장 작은값의 인덱스를 알고싶다 mindex
        //counter[mindex].pushback(pair(customers[i].id, customers[i].w))
        // sw 를소트를 한다
        //소트를 해서 가장 처음에 오는 값에다가 i 번째 고객을 i 쑤셔박아준다

        /*
        카운터의 손님이 들어갈때 자기보다 앞에있는 손님의 무게를 자신의 무게의 더해준다

        손님에게 자신이 현재 들어가 잇는 카운터의 인덱스 쑤셔박기

        
        
        */

        //뺄 때 
        /*
        요번에 나가야할 애들의 시간을 검사해서 가장 적은 시간이 걸리는 놈이 먼저 나감(단 가장 처음에 있는 손님들)
        처음손님이 아닌 2번째 손님일 경우 앞 손님의 시간을 더해서 다른애들이랑 비교함
        
        
        
        */



    }

 
}









// counter[0][3].id;

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
// 

/*
int 무게[N];
int id[N];

vector<int, int> 계산대[k];
vector<int> 계산대_id[k];


손님 <- 무게 id
계산대[i] <- 손님

for(int i = 0; i < 5; i++)
{
    계산대[0].push_back(손님.무게) 
    계산대[0].push_back(손님.id)
}

int i번의 총 무게의 합

계산대[0][5].first

for(int i = 0; i < 5; i++)
{
    1 += 계산대[0][0]
}

우선순위큐 통로;
통로.push(계산대 k개)
*/ 
/*
높은번호 부터 빠져나간다. 즉 손님들에게 자신이 현재 있는 계산대의 번호를 부여하고 

우선순위 큐로 자신이 있는 계산대의 번호가 높은 순서대로 빠져나가게 정렬하면 끝!
*/
// 계산대의 값이 높은애들부터 빠져나감
// 우선순위 큐
// queue

#endif