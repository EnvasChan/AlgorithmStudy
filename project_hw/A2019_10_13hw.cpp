#include "선택.h"
#ifdef A2019_10_13hw


// fib(5) -> fib(4) -> fib(3)
//					-> fib(2)
//		  -> fib(3)




#include<iostream>
using namespace std;
int num = 0;//0 을 카운트 하는 변수
int num2 = 0;//1 을 카운트 하는 변수
int fibonacci(int n) {
	if (n == 0) {
		num += 1;
		return 0;
	}
	else if (n == 1) {
		num2 += 1;
		return 1;
	}
	else {

		int ans = fibonacci(n - 1) + fibonacci(n - 2);
		return ans;
	}
}
int main()
{
	int n = 0;
	int a = 0;
	cin >> a;
	
	
	for (int i = 0; i < a; i++)
	{
		cin >> n;
		fibonacci(n);
		cout << "0이 출력된 횟수" << num << endl;
		cout << "1이 출력된 횟수" << num2 << endl;
		num = 0;
		num2 = 0;
	}
	
	return 0;
}

#endif A2019_10_13hw