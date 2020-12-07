#include "º±≈√.h"

#ifdef acm14697

#include <iostream>
#include <vector>
#include <algorithm>
#include<array>


using namespace std;

int main()
{
    int gf = 0;

    array<int, 3> a;

    for (int i = 0; i < 3; i++)
    {
        cin >> a[i];
    }

    cin >> gf;

    sort(a.begin(), a.end(), less<int>());
    

    // 1- 0 2  - 0 3 - 0
    // -> 0
    // 
    for (int i = 0; i < gf / a[0]; i++)
    {
        if (a[0] * i < gf)
        {
            for (int j = 0; j < gf / a[1]; j++)
            {
                if (a[1] * j < gf - (a[0] * i))
                {
                    for (int l = 0; l < gf / a[2]; l++)
                    {
                        if (a[1] * l == gf - (a[0] * i + a[1] * j))
                        {
                            cout << 1;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << 0;
    return 0;



    return 0;
}

#endif