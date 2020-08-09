
#include "선택.h"

#ifdef 순열

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


// host 주인

vector<int> numbers;	// 받은 숫자
vector<int> gen;		// 만들어 내는 숫자
vector<bool> mask;		// 받은 숫자를 사용했는지 여부 (mask[0] = true라면, numbers[0]은 이미 사용됨)
int k;					// numbers.size()
int num[10] = { 0 };

// 123 523
// 123 523
// 132 532
// 213 253
// 231 235
// 8337 
// ...

// 6 * 5 * 4 * 3 * 2 *1 => 최적화 안된 똥프로그램
void solve(int cur)//cur은 검사하는 자릿수
{
	bool is_end = false;
	if (cur == k)// 현재 검사하는칸이 맨 끝칸이라면 
	{
		for (int i = 0; i < k; i++)
		{
			cout << gen[i];// 무작위로 섞은 숫자 출력
		}
		cout << ", ";
		return;// 다시 바로 뒷칸으로 이동
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
		// 주어준 숫자중에서 가장 앞이 0일경우
		if (cur == 0 && i == 0)
		{
			continue;
		}
		if (num[i] != 0)
		{
			gen[cur] = i;//쌌다 브로
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
	// 주어진 수를 특정 값으로 나누어서 몫과 나머지를 이용해라
	// 1 ~ 10^n 까지를 해서 얼마의 10^n으로 나누어서 몫이 1의자리 수가 나오면 된다.



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
				a = numbers[j];야발....
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


		//조합 가능한 겹치지 않는 숫자들을 만든다.
		//막 뒤섞어 근데 겹쳐 그럼 걸러 그리고 다시 뒤섞어



		/*


		for (int i = 0; i < numbers.size(); i++)
		{
			for (int j = 0; j < numbers.size(); j++)
			{

				//하나를 검사하여 앞 숫자와 뒷숫자와의 크기를 비교하여
				//작은것을 앞으로 보낸다
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