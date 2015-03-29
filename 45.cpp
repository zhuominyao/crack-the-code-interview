//约瑟夫环问题:0,1,2,...,n-1这n个数字排成一个圆圈，从数字0开始每次从这个
//圈里删除第m个数字。求这个圆圈里最后剩余的数字

#include <iostream>

using namespace std;

int lastRemaining(unsigned int n,int unsigned m)
{
	if(n < 1 || m < 1)
		return -1;
	int last = 0;
	for(int i = 2;i <= n;i++)
		last = (last + m) % i;
	return last;
}

int main()
{
	cout<<lastRemaining(3,3);
}
