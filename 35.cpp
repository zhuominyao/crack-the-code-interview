//在字符串中找到第一个只出现一次的字符

#include <iostream>

using namespace std;

int FindFirstChar(char * str,int length)
{
	int array[256];
	for(int i = 0;i < 256;i++)
		array[i] = 0;
	for(int i = 0;i < length;i++)
	{
		if(array[str[i]] == 0)
			array[str[i]] = i+1;
		else if(array[str[i]] != 0)
			array[str[i]] = -1;
	}
	for(int i = 0;i < 256;i++)
		cout<<array[i]<<" ";
	cout<<endl;
	int min = length + 1;
	for(int i = 0;i < 256;i++)
	{
		if(array[i] != 0 && array[i] != -1)
		{
			if(array[i] < min)
				min = array[i];
		}
	}
	return str[min-1];
}

int main()
{
	char str[11] = "abaccdeff";
	cout<<FindFirstChar(str,9);
}
