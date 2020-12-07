#include "����.h"

#ifdef acm17608

//today problem: https://www.acmicpc.net/problem/17610

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    // �־��� �� + �� = �־��� ��
    // �� : �߰� 1 2 3 ������
    // 1 = �� - 1
    // 2= �� :2 �Ǵ� 1 + �� : 1

    int k = 0;//���� ����

    int water = 1; // ��

    int sum = 0;

    int w[2000001] = { 0 }; // ���� ����
 
    vector<int> save;// ���� ���� ����

    cin >> k;

    for (int i = 0; i < k; i++)// ���� ���� �ޱ�
    {
        int a;
        cin >> a;
        w[i] = a;
    }

    for (int i = 0; i < k; i++)//�� �����ϱ�
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

// ������ ������ ����
struct Customer
{
    int counter;
    int weight;
    int id;
};


// �񱳸� ���� ����ü�� ������ �� (priority_queue ����� ����)
struct CompareIn
{
    // �̰� ���̸�, lhs�� queue�� �ڷ� ����
    bool operator()(const Customer& lhs, const Customer& rhs)
    {
        if (lhs.weight == rhs.weight)
        {
            // ��ȣ�� ���� ī���ͷ�, (ī���� ��ȣ�� ������ �� �ڷ� ������ ��)
            return lhs.counter > rhs.counter;
        }
        // ���԰� ���ſ� �� �ڷ� ������ ��
        return lhs.weight > rhs.weight;
    }
};

// ���� ���� ���� �� �񱳰� �ٸ�
struct CompareOut
{
    // �̰� ���̸�, lhs�� queue�� �ڷ� ����
    bool operator()(const Customer& lhs, const Customer& rhs)
    {
        // ���԰� ���ٸ�?
        if (lhs.weight == rhs.weight)
        {
            // ��ȣ�� ������ ī���͸� ���� ����, (ī���� ��ȣ�� ���� �� �ڷ� ������ ��)
            return lhs.counter < rhs.counter;
        }
        // ���԰� ���ſ� �� �ڷ� ������ ��
        return lhs.weight > rhs.weight;
    }
};

// �켱���� ť ���� (����ü�� �������� ����ϵ� �� �Լ��� �ٸ� ���� ���)
priority_queue<Customer, std::vector<Customer>, CompareIn> in_q;
priority_queue<Customer, std::vector<Customer>, CompareOut> out_q;


int main()
{
    // �Է�
    int n, k;
    cin >> n >> k;

    // �ʱ� ī���Ϳ� �մ��� �ޱ� ���� ī���� ��ȣ ���� 
    // (������ �� �մ��� ���� �׳� �־�δ� �Ŷ� ���԰� 0��)
    for (int i = 1; i <= k; ++i)
    {
        in_q.push({ i,0 });
    }

    // ���Ե� �ޱ�
    for (int i = 0; i < n; ++i)
    {
        int id, weight;
        cin >> id >> weight;
        // �켱���� ť���� �� ���� ���� 
        // (ť �ִ� �� �߿� ���԰� ���� ������� ���� ���԰� ���ٸ� ��ȣ�� ���� ��)
        // ī���� ���� �� ���ݱ��� ���� ����(�ð�) ���� Ȱ�� ����
        Customer fast_customer = in_q.top();
        in_q.pop(); // top()�� ������ �������⸸ �ϰ�, pop()�� ����� ť���� �����

        // ���� ���� ���� (�տ� �ִ� ��� ������ �ϴ� ����)
        Customer next_customer;

        // �Ƶ� �־��ְ�
        next_customer.id = id;
        // ���Դ� �տ� �ִ� �� ���Զ� ���� ���� ���Զ� ��ħ 
        next_customer.weight = fast_customer.weight + weight;
        // fast_customer -> �ְ� ���������� ���� ī���� �ڿ� ���� ���� ������
        next_customer.counter = fast_customer.counter;

        // ���� �� ���� ����� ���� in_q�� �־���
        in_q.push(next_customer);

        // ���� �� ����ؾ��ϱ� ������ out_q�� �־���
        out_q.push(next_customer);
    }

    // ���� ����
    long long answer = 0, count = 1;
    while (!out_q.empty()) // out_q�� �� �� ����
    {
        // out_q�� top()�� �ְ�� ���� ������ ���� ������ ���ĵǾ����� 
        // (���ſ���� �ڷ� ��)
        // ������� �̾Ƽ� count ���ؼ� ����
        answer += (count * out_q.top().id); // ���� = ���� + count * id ��ȣ
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

    int num = 0; // �迭�� ������ �μ����� ū �� ���� �����ϴ� ����

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