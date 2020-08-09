/*

** 컴파일 해야 하는 프로그램:
레시피가 있으면 그걸로 반찬을 다 만드는거고,
a = 5 -> 어셈블리어(10110110) -> 실행



** 스크립트 실행 프로그램: 적힌 명령어를 한 줄씩 실행하는 프로그램
레시피로 음식은 완성 되어있고, 그 음식들을 찾아서 먹는 것
이미 실행하는 프로그램이 있음

a = 5


집 문을 여세요.
들어가세요.
문을 닫으세요.
컵을 잡으세요.
마시세요.


재귀함수

*/

#include "선택.h"

#ifdef C200112

#include <iostream>
using namespace std;



// 1부터 N까지의 합을 구하는 점화식을 구하세요.

// a(n) = 1부터 n까지 구하는 식.

// a(n+1) = a(n) + n+1

// sum(N+1) = sum(N) + N+1
// sum(10) -> 10 + sum(9) -> 9 + sum(8) -> 
// 10 + 9 + 8 + 7+ 6 + ... + 0
// sum(N)은 뭘 구해줌? 1부터 N까지의 수의 합
// f(n) = n+1
// a(n+1) = a(n) + f(n)
// a(n+1) = a(n) + n+1
// sum(N) = sum(N-1) + N

// sum(3)=  sum(2) + 3
// sum(2) = sum(1) + 2
// sum(1) = sum(0) + 1
// sum(0) = 0 // 이미 알고있는 값

// 1부터 a까지 더하는 재귀함수
int sum(int n)
{
	if (n <= 0) return 0;
	int res = n + sum(n - 1)
		;

	return res;
}


// 피보나치 수열
// 1 1 2 3 5 8 13 21 34 55
// a(n+1) = a(n) + f(n) 

// 수학적 귀납법을 통해서 a(5) 등의 임의의 값을 구하고 싶음.
// a(n+1) = a(n) + a(n+1) - a(n)
// f(n) = a(n+1) -a(n)
// fib(N) = fib(N-1) + fib(N-2)
// 종료 조건:
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

	cout << "fib(" << n << ") 가 호출됐어요 ^^" << endl;
	if (n == 1)
	{
		for (int i = 0; i < level; i++)
			cout << '\t';
		cout << "fib(" << n << ") 의 값 " << 1 << "이 리턴됐어요 ^^" << endl;
		level--;
		return 1;
	}
	if (n == 2)
	{
		for (int i = 0; i < level; i++)
			cout << '\t';

		cout << "fib(" << n << ") 의 값 " << 1 << "이 리턴됐어요 ^^" << endl;
		level--;
		return 1;
	}
	int result = fib(n - 1) + fib(n - 2);;

	for (int i = 0; i < level; i++)
		cout << '\t';

	cout << "fib(" << n << ") 의 값 " << result << "이 리턴됐어요 ^^" << endl;
	level--;

	return result;
}




int main()
{
	cout << fib_with_info(7) << endl;

	return 0;
}


#endif