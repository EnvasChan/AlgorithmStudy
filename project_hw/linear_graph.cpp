#include "선택.h"

#ifdef LINEAR_GRAPH


#include <iostream>

// 100 -> 75

// 일반: 75번 반복
// 이진탐색: 2번!!! 야호

int main()
{
	// 선형 그래프
	int arr[10] = { 1, 3, 5, 7, 11, 15, 18, 58, 9999, 102424 };

	// 선형 그래프 전체 탐색
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] == 11)
		{
			// 발견!
			break;
		}
	}


	// + 가정: 선형 그래프가 정렬이 되어있다면???
	int index = 5;

	if (arr[index] == 11)
	{
		// 발견!
	}
	else if (arr[index] > 11)
	{
		index = 7;
	}
	else
	{
		index = 2;
	}
	// ..


	
	

	return 0;

}

#endif // LINEAR_GRAPH
