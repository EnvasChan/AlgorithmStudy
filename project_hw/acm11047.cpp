#include "����.h"
// ���� �޾Ƽ� ū�� ���� ���ʴ�� �P ���´�
// ū������ ���� ������ �Ǵ´�� �� ó�ڴ´�
// �׷��ٰ� ���� ���� k�� �ȴٸ� ���ݱ��� ����� ������ ������ ����ϰ� ������.

#ifdef acm11047
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int n;
int k[11] = { 0 };
int num;

int max_value = 0;
int current_value = 0;//���� ��
int current_weight = 0;//��������
int value = 0;
int current_money = 0;
int weight[22];

// 1. ���� �κ� ����
// 1,5,10�� ���� ��
// 17 -> 1 1 5 10
// 27 -> 1 1 5 10 10

// 2. ������� ����
// 

void solve(int nn,int money)
{
	
	if (money == 0)
	{
		cout << value;
		return;
	}

	//���� ���� �ְ�� �������� 
	
	
	if (k[nn] > money)
	{
		solve(nn + 1,money);//��;; �� ������ �� ���� �� �����
	}
	else
	{
		value += 1;
		solve(nn, money - k[nn]);// ��� ���´� ���� �� �ֽ��ϴ�, ��񸸿� �� �� �ѹ� �� �� �� �ֳ���
	}
}




int main()
{
	cin >> n;
	cin >> current_money;


	for (int i = n - 1; i >= 0; i--)
	{
		cin >> num;
		k[i] = num;
	}
	solve(0, current_money);
	return 0;
}

#endif // {0}