#include "����.h"

#ifdef acm1912

#include <iostream>
#include <vector>
#include <algorithm>
int n = 1;
using namespace std;

// ���ڸ� ���� �� ���ڸ� ������ ��� ���ư� 
// ��� �������ڵ��� ����
// ������� ������ �Ǹ� ����ġ�� �̵� ����
// �� ���� ���ں��� �ٽ� ����
int main()
{
    int a = 0;
   
    vector<int> num;
    int result = -1001;

    cin >> n;

    num.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        a += num[i];

        result = max(result, a);

        if (a < 0)
        {
            a = 0;
        }
    }
   
    /// sort(b.begin(),b.end());
    cout << result;
   
}

#endif