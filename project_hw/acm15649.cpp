#include "����.h"
#ifdef acm15649
#include <iostream>
using namespace std;
/*
����
1. ��üŽ�� ����

2. �������� ����� �ִ� ���ڸ� k��° ��� �Ҷ� k ��° ���� �״����� k + 1�� ���ڸ� �����

Ǯ�� ���

�Ȱ��� ���� �ִ��� ������ Ȯ�� 

������ �� �ְ� ������ 2��° ĭ���� �Ѿ

���ٿ� ĭ Ȯ���� �������� ���� �ٷ� �Ѿ



��������
2. �Ȱ��� ���� �ѹ��� ���� �� ����

3. �� ������ �� m���� ���ڸ� ������.






*/
int result[10] = { 0, };

int n = 4;
int m = 4;

void solve(int k) // r -> k
{
	if (k == m)
	{
		// ������� ���� ���
		for (int i = 0; i < m; i++)
		{
			cout << result[i] << " ";
		}
		cout << endl;
		return;
	}


	for (int i = 1; i <= n; i++)//�̹� �� ĭ�� ������ �ִ��� Ȯ��
	{
		// ���� ����
		// ���� k��°�� �˻��ϰ� �ִٸ� 1 ~ k -1 ���� �ߺ��Ǵ� ���� �ִ��� �˻��Ѵ� 
		bool found = false;
		for (int j = 0; j < k; j++)
		{
			if (result[j] == i)
			{
				found = true;
				break;
			}
		}
		if (found) continue;
		
		//�� ���ڿ� ��� �Ծ��� ������ ����ְ�
		result[k] = i;

		solve(k + 1);

		//������ �����ش�
		result[k] = 0;
	}
}


int main()
{
	

	solve(0);








	return 0;
}



#endif // acm15649
