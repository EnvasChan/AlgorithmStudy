
#include "����.h"

#ifdef ����

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


// host ����

vector<int> numbers;	// ���� ����
vector<int> gen;		// ����� ���� ����
vector<bool> mask;		// ���� ���ڸ� ����ߴ��� ���� (mask[0] = true���, numbers[0]�� �̹� ����)
int k;					// numbers.size()
int num[10] = { 0 };

// 123 523
// 123 523
// 132 532
// 213 253
// 231 235
// 8337 
// ...

// 6 * 5 * 4 * 3 * 2 *1 => ����ȭ �ȵ� �����α׷�
void solve(int cur)//cur�� �˻��ϴ� �ڸ���
{
	bool is_end = false;
	if (cur == k)// ���� �˻��ϴ�ĭ�� �� ��ĭ�̶�� 
	{
		for (int i = 0; i < k; i++)
		{
			cout << gen[i];// �������� ���� ���� ���
		}
		cout << ", ";
		return;// �ٽ� �ٷ� ��ĭ���� �̵�
	}
	for (int i = 0; i < k; i++)
	{
		if (mask[i] == false)
		{
			mask[i] = true;
			gen[cur] = numbers[i];
			solve(cur + 1);
			mask[i] = false;
		}
	}
}

void solve2(int cur)
{
	bool is_end = false;
	if (cur == k)
	{
		for (int i = 0; i < k; i++)
		{
			cout << gen[i];
		}
		cout << " ";
		return;
	}

	// num -> 0~9 
	for (int i = 0; i < 10; i++)
	{
		// �־��� �����߿��� ���� ���� 0�ϰ��
		if (cur == 0 && i == 0)
		{
			continue;
		}
		if (num[i] != 0)
		{
			gen[cur] = i;//�մ� ���
			num[i] -= 1;
			solve2(cur + 1);
			num[i] += 1;
		}
	}
	
}

int main()
{
	int n = 1;
	cin >> n;
	int b = 0;
	int a = 0;
	int tmp = 0;
	// �־��� ���� Ư�� ������ ����� ��� �������� �̿��ض�
	// 1 ~ 10^n ������ �ؼ� ���� 10^n���� ����� ���� 1���ڸ� ���� ������ �ȴ�.



	// 1746 6471
	while (n > 0)
	{
		numbers.push_back(n % 10);
		num[n % 10] ++;
		mask.push_back(false);
		n /= 10;
	}
	k = numbers.size();
	gen.resize(k);

	for (int i = 0; i < k-1; i++)
	{
		for (int j = 0; j < k-1; j++)
		{
			if (numbers[j] > numbers[j+1])
			{
				tmp = numbers[j];
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = tmp;
			}
		}
	}
	solve2(0);


		/*
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				a = numbers[j];�߹�....
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = a;
				for (int c = 0; c < numbers.size(); c++)
				{
					cout << numbers[c] << " ";
				}
				cout << endl;

			}
		}
		*/


		//���� ������ ��ġ�� �ʴ� ���ڵ��� �����.
		//�� �ڼ��� �ٵ� ���� �׷� �ɷ� �׸��� �ٽ� �ڼ���



		/*


		for (int i = 0; i < numbers.size(); i++)
		{
			for (int j = 0; j < numbers.size(); j++)
			{

				//�ϳ��� �˻��Ͽ� �� ���ڿ� �޼��ڿ��� ũ�⸦ ���Ͽ�
				//�������� ������ ������
			}



		}








	for (int i = 0; i < n; i++)
	{
		int a = n % (int)pow(10, i);
		if (a < 10)
		{
			b = 10 ^ i;
		}

	}





	*/
	return 0;

}

#endif