#include "����.h"

#ifdef LINEAR_GRAPH


#include <iostream>

// 100 -> 75

// �Ϲ�: 75�� �ݺ�
// ����Ž��: 2��!!! ��ȣ

int main()
{
	// ���� �׷���
	int arr[10] = { 1, 3, 5, 7, 11, 15, 18, 58, 9999, 102424 };

	// ���� �׷��� ��ü Ž��
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] == 11)
		{
			// �߰�!
			break;
		}
	}


	// + ����: ���� �׷����� ������ �Ǿ��ִٸ�???
	int index = 5;

	if (arr[index] == 11)
	{
		// �߰�!
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
