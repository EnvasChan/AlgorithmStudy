/*

** ������ �ؾ� �ϴ� ���α׷�:
�����ǰ� ������ �װɷ� ������ �� ����°Ű�,
a = 5 -> �������(10110110) -> ����



** ��ũ��Ʈ ���� ���α׷�: ���� ��ɾ �� �پ� �����ϴ� ���α׷�
�����Ƿ� ������ �ϼ� �Ǿ��ְ�, �� ���ĵ��� ã�Ƽ� �Դ� ��
�̹� �����ϴ� ���α׷��� ����

a = 5


�� ���� ������.
������.
���� ��������.
���� ��������.
���ü���.


����Լ�

*/

#include "����.h"

#ifdef C200112

#include <iostream>
using namespace std;



// 1���� N������ ���� ���ϴ� ��ȭ���� ���ϼ���.

// a(n) = 1���� n���� ���ϴ� ��.

// a(n+1) = a(n) + n+1

// sum(N+1) = sum(N) + N+1
// sum(10) -> 10 + sum(9) -> 9 + sum(8) -> 
// 10 + 9 + 8 + 7+ 6 + ... + 0
// sum(N)�� �� ������? 1���� N������ ���� ��
// f(n) = n+1
// a(n+1) = a(n) + f(n)
// a(n+1) = a(n) + n+1
// sum(N) = sum(N-1) + N

// sum(3)=  sum(2) + 3
// sum(2) = sum(1) + 2
// sum(1) = sum(0) + 1
// sum(0) = 0 // �̹� �˰��ִ� ��

// 1���� a���� ���ϴ� ����Լ�
int sum(int n)
{
	if (n <= 0) return 0;
	int res = n + sum(n - 1)
		;

	return res;
}


// �Ǻ���ġ ����
// 1 1 2 3 5 8 13 21 34 55
// a(n+1) = a(n) + f(n) 

// ������ �ͳ����� ���ؼ� a(5) ���� ������ ���� ���ϰ� ����.
// a(n+1) = a(n) + a(n+1) - a(n)
// f(n) = a(n+1) -a(n)
// fib(N) = fib(N-1) + fib(N-2)
// ���� ����:
// fib(1) = 1, fib(2) = 1

int level = 0;


int fib(int n)
{
	if (n == 1)
	{
		return 1;
	}
	if (n == 2)
	{
		return 1;
	}

	int result = fib(n - 1) + fib(n - 2);
	return result;
}

int fib_with_info(int n)
{
	level++;
	for (int i = 0; i < level; i++)
		cout << '\t';

	cout << "fib(" << n << ") �� ȣ��ƾ�� ^^" << endl;
	if (n == 1)
	{
		for (int i = 0; i < level; i++)
			cout << '\t';
		cout << "fib(" << n << ") �� �� " << 1 << "�� ���ϵƾ�� ^^" << endl;
		level--;
		return 1;
	}
	if (n == 2)
	{
		for (int i = 0; i < level; i++)
			cout << '\t';

		cout << "fib(" << n << ") �� �� " << 1 << "�� ���ϵƾ�� ^^" << endl;
		level--;
		return 1;
	}
	int result = fib(n - 1) + fib(n - 2);;

	for (int i = 0; i < level; i++)
		cout << '\t';

	cout << "fib(" << n << ") �� �� " << result << "�� ���ϵƾ�� ^^" << endl;
	level--;

	return result;
}




int main()
{
	cout << fib_with_info(7) << endl;

	return 0;
}


#endif