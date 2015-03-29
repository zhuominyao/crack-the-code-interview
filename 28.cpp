//输入一个字符串，输出它的全排列

#include <iostream>

using namespace std;

void printPermutation(char * str,char * startPos)
{
	if(*startPos == '\0')
	{
		cout<<str<<endl;
		return;
	}
	char * tempPos = startPos;
	while((*tempPos) != '\0')
	{
		char temp = *tempPos;
		*tempPos = *startPos;
		*startPos = temp;
		printPermutation(str,startPos+1);
		temp = * tempPos;
		*tempPos = *startPos;
		*startPos = temp;
		tempPos++;
	}
}

void Permutation(char * str)
{
	if(str == NULL)
		return;
	printPermutation(str,str);
}

int main()
{
	char str[6] = "abcde";
	Permutation(str);
}
