#include "����.h"

//today problem : https://www.acmicpc.net/problem/17612

#ifdef acm17612

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// �� �Ѹ��� ���̵𰪰� ������ ���� ������ �־����.

int k = 0;//k�ǰ���ŭ ���밡 �ִ�.
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


        for (int j = 0; j < k; j++)//��ٸ��� �ð��� ������ �� ��ȣ�� ���� ������ ������ �ڵ�
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





        //���� �ð��� ���� �ɸ��°��� ó����
        //k�� ��ŭ �˻縦 �ؾ���

        // sw�߿� ���� �������� �ε����� �˰�ʹ� mindex
        //counter[mindex].pushback(pair(customers[i].id, customers[i].w))
        // sw ����Ʈ�� �Ѵ�
        //��Ʈ�� �ؼ� ���� ó���� ���� �����ٰ� i ��° ���� i ���Źھ��ش�

        /*
        ī������ �մ��� ���� �ڱ⺸�� �տ��ִ� �մ��� ���Ը� �ڽ��� ������ �����ش�

        �մԿ��� �ڽ��� ���� �� �մ� ī������ �ε��� ���Źڱ�

        
        
        */

        //�� �� 
        /*
        ����� �������� �ֵ��� �ð��� �˻��ؼ� ���� ���� �ð��� �ɸ��� ���� ���� ����(�� ���� ó���� �ִ� �մԵ�)
        ó���մ��� �ƴ� 2��° �մ��� ��� �� �մ��� �ð��� ���ؼ� �ٸ��ֵ��̶� ����
        
        
        
        */



    }

 
}









// counter[0][3].id;

//��������ũ�� ������ ����

/*

����

����     111111111

����

*/

//���� �³���� ����Ѵ�.
    //K��° �������� �����³���� �ĳִ´�.

// ���� ���ð��� ��� ���� ���� ���� ����ũ�� ����.
//�ƴϸ� ������� ó����
// 

/*
int ����[N];
int id[N];

vector<int, int> ����[k];
vector<int> ����_id[k];


�մ� <- ���� id
����[i] <- �մ�

for(int i = 0; i < 5; i++)
{
    ����[0].push_back(�մ�.����) 
    ����[0].push_back(�մ�.id)
}

int i���� �� ������ ��

����[0][5].first

for(int i = 0; i < 5; i++)
{
    1 += ����[0][0]
}

�켱����ť ���;
���.push(���� k��)
*/ 
/*
������ȣ ���� ����������. �� �մԵ鿡�� �ڽ��� ���� �ִ� ������ ��ȣ�� �ο��ϰ� 

�켱���� ť�� �ڽ��� �ִ� ������ ��ȣ�� ���� ������� ���������� �����ϸ� ��!
*/
// ������ ���� �����ֵ���� ��������
// �켱���� ť
// queue

#endif