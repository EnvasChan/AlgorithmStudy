#include "선택.h"

#ifdef acm99999

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// i 가 1 2 3 5 7 제외하고 10의 자리 이상부터 1 ~ 10까지 나눠보고 나머지가 

bool primes[1000001] = { false, };
int r = 0;

int main()
{
    int n = 0;
    int a;
    bool c = false;
    vector<int> b;
    cin >> n;

    
    // O(Nlog(N)) --> O(N)
    for (int i = 1; i <= n; i++)    // N 번
    {
        for (int j = 2; j <i; j++)  // ~N
        {
            a = i % j;
            if (a == 0)
            {
                c = true;
                break;
            }
        }
        if (c == false)
        {
            b.push_back(i);
        }
        c = false;
    }

    cout << "\n 2 is done" << endl;
    cout << b.size()<<endl;

    //for (int i = 0; i < b.size(); i++)
    //{
    //    cout << b[i]<<"  ";
    // }










    return 0;
}

#endif