#include "선택.h"

#ifdef acm1912

#include <iostream>
#include <vector>
#include <algorithm>
int n = 1;
using namespace std;

// 숫자를 받음 그 숫자를 가지고 계속 나아감 
// 계속 다음숫자들을 더함
// 어느순간 음수가 되면 서렌치고 미드 오픈
// 그 다음 숫자부터 다시 시작
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