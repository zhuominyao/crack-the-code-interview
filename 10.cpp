//实现一个函数，输入一个数，输出它的二进制数中1的个数

#include <iostream>

using namespace std;

int count1(int n)
{
	int count = 0;
	while(n != 0)
	{
		count++;
		n = n & (n-1);
	}
	cout<<count<<endl;
}

int main()
{
	count1(11);
}
