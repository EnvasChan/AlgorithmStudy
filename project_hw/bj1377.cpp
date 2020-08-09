#include "선택.h"

#ifdef BJ1377

// https://www.acmicpc.net/problem/1377

// 정렬: 나란히 바꾸는 것

// SWAP: 치환하다 A B C --> C B A
// C B C


// A B C
// tmp = arr[0]
// arr[0] = arr[2]
// arr[2] = tmp


// 'A' -> 'AA' -> 'AAA' -> 'AAAA' -> 'AAAAA'
// 'AAAA...B' -> // DFS
// 'A' -> 'B' -> 'C' -> 'AA' // BFS
#include <iostream>

using namespace std;

int main()
{
	int array[10] = { 6, 1, 2, 9, 10421, 4829999, 0, -999999,10, -1 };
	int mem = 0;
	for (int j = 0; j < 10; j++)
	{
		for (int i = 0; i < 9; i++)
		{
			if (array[i] < array[i + 1])
			{
				mem = array[i];
				array[i] = array[i + 1];
				array[i + 1] = mem;
			}
		}

	}
		
	for (int i = 0; i < 10; i++)
	{
		cout << array[i] << ' ';
	}
	cout << endl;
	return 0;
}

#endif