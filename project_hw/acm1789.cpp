#include "����.h"

#ifdef acm1789

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/*
"�ߵ�� �����"



�ڵ� �����ϴ�

������ ���´ٰ� ����





10 -> 1 2 3 4

20 -> 1 2 3 4 10
      1 2 3 4 5 6

30 - > 1 2 3 4 5 6 9
       1 2 3 4 5 6 7 8

?

*/
int main()
{
    int n = 0;
    int s = 0; 
    int a = 0;
    int b = 0;

    cin >> s;

    for (int i = 1; i < s; i++)
    { 
       b += i;
       n += 1;
        
       if (b > s)
       {
           n -= 1;
           break;
       }
        

    }

    cout << n;


    return 0;
}

#endif