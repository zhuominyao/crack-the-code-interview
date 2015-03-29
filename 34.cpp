//求从小到大的第n个丑数

#include <iostream>

using namespace std;

int min(int a,int b,int c)
{
	if(a < b && a < c)
		return a;
	if( b > c)
		return c;
	else
		return b;
}

void PrintUglyNumber(int n)
{
	int uglyNumber[n];
	uglyNumber[0] = 1;
	uglyNumber[1] = 2;
	uglyNumber[2] = 3;
	uglyNumber[3] = 5;
	int index2 = 0;
	int index3 = 0;
	int index5 = 0;
	for(int i = 1;i < n;i++)
	{
		uglyNumber[i] = min(uglyNumber[index2]*2,uglyNumber[index3]*3,uglyNumber[index5]*5);
		while(uglyNumber[index2]*2 <= uglyNumber[i])
			index2++;
		while(uglyNumber[index3]*3 <= uglyNumber[i])
			index3++;
		while(uglyNumber[index5]*5 <= uglyNumber[i])
			index5++;
		cout<<uglyNumber[i]<<endl;
	}
}

int main()
{
	PrintUglyNumber(1500);
}
