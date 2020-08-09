#include "º±≈√.h"

#ifdef acm11399

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n = 0;
vector<int> p;
int a[1000] = { 0 };

/*

// O(n)
for (int i = 0; i < n; i++)
{
    // function1
}
for (int i = 0; i < n; i++)
{
    // function1
}
for (int i = 0; i < n; i++)
{
    // function1
}
for (int i = 0; i < n; i++)
{
    // function1
}
for (int i = 0; i < n; i++)
{
    // function1
}
for (int i = 0; i < n; i++)
{
    // function1
}


// O(n^2)
for (int i = 0; i < n; i++)
{
    // function1
    for (int j = 0; j < n; j++)
    {
        // function1
    }
}

*/

int main()
{
    cin >> n; 
    p.resize(n);


    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    sort(p.begin(), p.end(), less<int>());

    // O(n)
    a[0] = p[0];
    for (int i = 1; i < n; i++)
    {
        a[i] += p[i] + a[i-1];
    }
    int total1 = 0;
    for (int i = 0; i < n; i++)
    {
        total1 += a[i];
    }


    // O(n log(n)) 
    int total2 = 0;  // O(n) < O(n log n) <= O(n^2)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            total2 += p[j];
        }
    }

    

    cout << total1 << " " << total2 << endl;






























    return 0;
}

#endif