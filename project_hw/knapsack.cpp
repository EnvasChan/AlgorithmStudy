#include "����.h"
#ifdef knapsack
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;




// ���Կ� �������� �޴´�
// ��Ͽ��� �ϳ��ϳ� �� ���� �˻��غ� ����� �� 2^n 
//���� for�� ������ 2�� for�� �ȿ� if������ ���� �ʰ��ϸ� ���� ��� �����
// ��� �� ����
//�ݽ���
//ȣ���Ѵ�  ����



/*
2^n�� Ž���� �ڵ����� ��


solve
solve - yes or no --> 2 ����
solve - yes or no --> 2 ������ ����� ��
main
--------
[1 2 3 4]

main
 -> solve(0)
	 -> solve(1) NO
		 -> solve(2) NO
			-> solve(3) NO 
				-> solve(4) NO --> 0
				-> solve(4) YES --> 4
			-> solve(3) YES
				-> solve(4) NO --> 3
				-> solve(4) YES --> 7
		 -> solve(2) YES
			-> solve(3) NO 
				-> solve(4) NO --> 2
				-> solve(4) YES --> 6
			-> solve(3) YES
				-> solve(4) NO --> 5
				-> solve(4) YES --> 9
	 -> solve(1) YES
		 -> solve(2) NO
			-> solve(3) NO 
				-> solve(4) NO --> 0
				-> solve(4) YES --> 4
			-> solve(3) YES
				-> solve(4) NO --> 3
				-> solve(4) YES --> 7
		 -> solve(2) YES
			-> solve(3) NO 
				-> solve(4) NO --> 2
				-> solve(4) YES --> 6
			-> solve(3) YES
				-> solve(4) NO --> 5
				-> solve(4) YES --> 9

				*/
int w, n, a, b;
int max_value = 0;
int current_value = 0;
int current_weight = 0;
int value[22];
int weight[22];

//���� ������ ������


int nax = 0;


int solve(int num)
{
	if (num == n)

	{
		if (current_value > nax)
		{
			nax = current_value;
		}
		return;
	}

	for (int i = 0; i < 2; i++)
	{
		current_value  += i * value[num];
		solve(num + 1);
		current_value  -= i * value[num];
	}
}



int main()

{
	cin >> w >> n;

	
	for (int i = 0; i < n; i++)//�Է�
	{
		cin >> weight[i] >> value[i];
	}


	return 0;
}






























































#endif