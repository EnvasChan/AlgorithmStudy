#include "선택.h"

#ifdef koi_hambuger

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct card
{
	int star = 0;
	int rac = 0;
	int tri = 0;
	int cir = 0;
};
vector<int> print = { 0 };


void solve()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		unsigned long a = 0, b = 0;
		int num_a, num_b, m;
		cin >> num_a;
		for (int j = 0; j < num_a; j++)
		{
			cin >> m;
			a += (1 << 7 * (m - 1));
		}
		cin >> num_b;
		for (int j = 0; j < num_b; j++)
		{
			cin >> m;
			b += (1 << 7 * (m - 1));
		}
		if (a > b) cout << "A\n";
		else if (a < b) cout << "B\n";
		else cout << "D\n";
	}
}


int main()
{
	//딱지 하나에 있어야할 정보 : 별 네모 셈몸 동그라미
	solve();
	int n = 0;

	int cycle = 0;

	int turn = 0;

	int scan = 0;

	card a;
	card b;

	cin >> n;

	for (int i = 0; i < n ; i++)
	{
	
		cin >> cycle; //a

		for (int j = 0; j < cycle; j++)//a값 받기
		{
			cin >> scan;
			//switch로 할 수 잇긴한데 귀찮아서 패스
			if (scan == 1)
			{
				a.tri += 1;
			}
			if (scan == 2)
			{
				a.rac += 1;
			}
			if (scan == 3)
			{
				a.cir += 1;
			}
			if (scan == 4)
			{
				a.star += 1;
			}
		}
		
		

		cin >> cycle;//b

		for (int j = 0; j < cycle; j++)//b값 받기
		{
			cin >> scan;

			if (scan == 1)
			{
				b.tri += 1;
			}
			if (scan == 2)
			{
				b.rac += 1;
			}
			if (scan == 3)
			{
				b.cir += 1;
			}
			if (scan == 4)
			{
				b.star += 1;
			}
		}
			
		
		if (a.star > b.star)
		{
			print.push_back(1);
		}
		if (a.star < b.star)
		{
			print.push_back(2);
		}
		else
		{
			if (a.cir > b.cir)
			{
				print.push_back(1);
			}

			if (a.cir < b.cir)
			{
				print.push_back(2);
			}
			else
			{
				if (a.rac > b.rac)
				{
					print.push_back(1);
				}

				if (a.rac < b.rac)
				{
					print.push_back(2);
				}
				else
				{
					if (a.tri > b.tri)
					{
						print.push_back(1);
					}

					if (a.tri < b.tri)
					{
						print.push_back(2);
					}
					else
					{
						print.push_back(3);
					}
				}
			}
		}



		//정신나갈거같에ㅔㅔㅔㅔㅔㅔㅔㅔㅔㅔㅔㅔㅔㅔㅔㅔㅔㅔ

		a.star = 0;
		a.tri = 0;
		a.cir = 0;
		a.rac = 0;
		b.cir = 0;
		b.rac = 0;
		b.star = 0;
		b.tri = 0;
	}

	for (int i = 0; i < print.size(); i++)
	{
		if (print[i] == 1)
		{
			cout << "A" << endl;
		}

		if (print[i] == 2)
		{
			cout << "B" << endl;
		}

		if (print[i] == 3)
		{
			cout << "D" << endl;
		}
	}

	return 0;

}

#endif