#include "����.h"

//today problem : https://www.acmicpc.net/problem/17612

#ifdef acm17612

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// �� �Ѹ��� ���̵𰪰� ������ ���� ������ �־����.

int k = 0;//k�ǰ���ŭ ���밡 �ִ�.
int n = 0;
vector<int>costomer[1000000];
int id = 0;
int w = 0;
vector<int> bg[100000];//���� buy gate ����

int main()
{
    cin >> n;
    cin >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> id;
        cin >> w;

        costomer[i].push_back(id);//������ ���̵� �ֱ�
        costomer[i].push_back(w);//������ ������ �� �ֱ�

    }

    for (int i = 0; i < n; i++)
    {
        if (i <= k)
        {
            bg[i].push_back(costomer[i][0]);
            bg[i].push_back(costomer[i][1]);
            continue;
        }
        


        for (int j = 0; j < k; j++)//��ٸ��� �ð��� ������ �� ��ȣ�� ���� ������ ������ �ڵ�
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

        //������� ó����


    }

    for (int i = 0; i < n; i++)
    {
        cout << bg[i][0] << endl;
        cout << bg[i][1] << endl;
    }
    return 0;
}

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

//����� ���ÿ� �����ٸ� ���� ������� ��������

//������ ���� ���� ������ȣ 

// ���� ������ �������� ȸ������ * 1 
#endif