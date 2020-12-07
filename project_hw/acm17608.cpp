#include "선택.h"

#ifdef acm17608

//today problem: https://www.acmicpc.net/problem/17610

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    // 주어진 추 + 물 = 주어진 추
    // 예 : 추가 1 2 3 있으면
    // 1 = 물 - 1
    // 2= 물 :2 또는 1 + 물 : 1

    int k = 0;//추의 갯수

    int water = 1; // 물

    int sum = 0;

    int w[2000001] = { 0 }; // 추의 무게
 
    vector<int> save;// 물의 값을 저장

    cin >> k;

    for (int i = 0; i < k; i++)// 추의 무게 받기
    {
        int a;
        cin >> a;
        w[i] = a;
    }

    for (int i = 0; i < k; i++)//값 저장하기
    {
        save.push_back(w[i]);
    }

    sum = w[0];

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (water + w[i] == w[i] + sum)
            {
                sum += w[j];
            }

            water += 1;
           
        }
        water = 1;
        sum = 0;

    }











	
}




#endif 
/*
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// 고객님의 정보를 저장
struct Customer
{
    int counter;
    int weight;
    int id;
};


// 비교를 위해 구조체를 만들어야 함 (priority_queue 사용을 위해)
struct CompareIn
{
    // 이게 참이면, lhs를 queue의 뒤로 보냄
    bool operator()(const Customer& lhs, const Customer& rhs)
    {
        if (lhs.weight == rhs.weight)
        {
            // 번호가 빠른 카운터로, (카운터 번호가 나중인 걸 뒤로 보내야 함)
            return lhs.counter > rhs.counter;
        }
        // 무게가 무거운 걸 뒤로 보내야 함
        return lhs.weight > rhs.weight;
    }
};

// 들어올 때와 나갈 때 비교가 다름
struct CompareOut
{
    // 이게 참이면, lhs를 queue의 뒤로 보냄
    bool operator()(const Customer& lhs, const Customer& rhs)
    {
        // 무게가 같다면?
        if (lhs.weight == rhs.weight)
        {
            // 번호가 나중인 카운터를 먼저 뽑음, (카운터 번호가 빠른 걸 뒤로 보내야 함)
            return lhs.counter < rhs.counter;
        }
        // 무게가 무거운 걸 뒤로 보내야 함
        return lhs.weight > rhs.weight;
    }
};

// 우선순위 큐 선언 (구조체는 같은것을 사용하되 비교 함수만 다른 것을 사용)
priority_queue<Customer, std::vector<Customer>, CompareIn> in_q;
priority_queue<Customer, std::vector<Customer>, CompareOut> out_q;


int main()
{
    // 입력
    int n, k;
    cin >> n >> k;

    // 초기 카운터에 손님을 받기 위한 카운터 번호 저장 
    // (다음에 올 손님을 위해 그냥 넣어두는 거라서 무게가 0임)
    for (int i = 1; i <= k; ++i)
    {
        in_q.push({ i,0 });
    }

    // 고객님들 받기
    for (int i = 0; i < n; ++i)
    {
        int id, weight;
        cin >> id >> weight;
        // 우선순위 큐에서 맨 앞을 꺼냄 
        // (큐 있는 것 중에 무게가 제일 가벼우며 만약 무게가 같다면 번호가 빠른 것)
        // 카운터 정보 및 지금까지 쌓인 무게(시간) 정보 활용 예정
        Customer fast_customer = in_q.top();
        in_q.pop(); // top()은 데이터 가져오기만 하고, pop()을 해줘야 큐에서 사라짐

        // 집어 넣을 고객님 (앞에 있던 사람 정보를 일단 복사)
        Customer next_customer;

        // 아뒤 넣어주고
        next_customer.id = id;
        // 무게는 앞에 있던 분 무게랑 지금 고갱님 무게랑 합침 
        next_customer.weight = fast_customer.weight + weight;
        // fast_customer -> 최고 빨리끝나는 고갱님 카운터 뒤에 가서 스기 때문에
        next_customer.counter = fast_customer.counter;

        // 다음 줄 스는 사람을 위해 in_q에 넣어줌
        in_q.push(next_customer);

        // 뽑을 때 사용해야하기 때문에 out_q에 넣어줌
        out_q.push(next_customer);
    }

    // 정답 가공
    long long answer = 0, count = 1;
    while (!out_q.empty()) // out_q가 빌 때 까지
    {
        // out_q의 top()은 최고로 빨리 나오는 고갱님 순으로 정렬되어있음 
        // (무거울수록 뒤로 감)
        // 순서대로 뽑아서 count 곱해서 더함
        answer += (count * out_q.top().id); // 정답 = 정답 + count * id 번호
        out_q.pop();
        count++;
    }

    cout << answer;

    return 0;
}
*/

/*
 https://www.acmicpc.net/problem/17608

int gridy = 0;

    int n = 0;

    int block[100001] = { 0 };

    int h = 0;

    int num = 0; // 배열의 마지막 인수보다 큰 수 들을 저장하는 벡터

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> h;
        block[i] = h;
    }

    gridy = n - 1;

    for (int i = n-1; i >= 0; i--)
    {
        if (block[gridy] < block[i])
        {
            gridy = i;
            num += 1;
        }
    }

    cout << num + 1;

    //complete



    return 0;


    ====== solution 2 ====== 

    #include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n = 0;
int h = 0;

int num = 0;

int block[100001] = {0};

int greedy = 0;


int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> h;
        block[i] = h;
    }

    greedy = block[n];



  for (int j = n - 1; j >=0; j--)
    {
            if(greedy < block[j])
            {
                greedy = block[j];
                num +=1;
            }

    }

    cout << num;




    return 0;
}
*/