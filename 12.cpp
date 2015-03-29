//打印1-最大的n位数

#include <iostream>

using namespace std;

bool increment(char * number,int n)
{
	int pos = n - 1;
	while(pos >= 0 && number[pos] == '9')
	{
		number[pos] = '0';
		pos--;
	}
	if(pos == -1)
		return false;
	else
	{
		number[pos]++;
		return true;
	}
}

void print(char * number)
{
	int pos = 0;
	while(number[pos] == '0')
		pos++;
	cout<<number+pos<<endl;
}

int print1ToMaxN(int n)
{
	char * number = new char[n+1];
	number[n] = '\0';
	for(int i = 0;i < n;i++)
		number[i] = '0';
	while(increment(number,n))
		print(number);
	delete [] number;
}

int main()
{
	print1ToMaxN(10);
}
