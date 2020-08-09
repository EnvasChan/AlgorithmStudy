#include "선택.h"
#ifdef 격자길
#include <iostream>
using namespace std;

int h = 0;
int w = 0;
bool n[100][100] = { 0 };

/*
도장 찍어주기
인접한 노드 검사(아래랑 오른쪽만 가면된다)
비어잇는 노드가 있다면 거기로 들어간다
쭊쭊 가다가 n의 h가 h의 다다랐을떄 k 의 1을 더해준다
*/
/*
1. 어떤 값을 받을 지? : 부분 문제의 파라미터
2. 어떤 값을 내보내 줄 지? : 부분 문제의 답 -> x,y 부터 h,w까지 갈 수 있는 경우의 수

 격자의 크기가 입력되었을때 0,0 부터 h,w 까지 갈수있는 길이의 경우의 수 


 x, y 직선의 방정식

 x,y가 직선의 아래에 있는지, 위에 있는지
 y= ax + b

 y = w/h *x < y 인 직선
*/
int hamsu(int x, int y)//경우의 수
{
	if(y * w < h * x)//흰색영역은 꺼져
	{
		return 0;
	}


	if (x == w && y == h)
	{
		return 1;//종료조건, 1을 해주는 이유는 경우의 수 1개가 늘어났다는것
	}

	if (x > w || y > h)
	{
		return 0;
	}

	return hamsu(x + 1, y) + hamsu(x, y + 1);



}
	
	


int main()
{
	cin >> h;
	cin >> w;








	cout << hamsu(0,0);
	return 0;
}

#endif 격자길