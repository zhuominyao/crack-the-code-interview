//实现一个函数，将字符串中的每一个空格字符转换成“%20”

#include <stdio.h>

void replaceBlank(char * array,int length)
{
	printf("%s\n",array);
	if(array == NULL || length <= 0)
		return;
	int numberOfBlank = 0;
	int i;
	for(i = 0;array[i] != '\0';i++)
	{
		if(array[i] == ' ')
			numberOfBlank++;
	}
	int newLength = i + 2 * numberOfBlank;
	printf("%s\n%d\n",array,newLength);
	if(newLength > length)
		return;//新的字符串长度大于可以容纳的长度
	int indexOfOriginal = i;
	int indexOfNew = newLength;
	while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
	{
		if(array[indexOfOriginal] == ' ')
		{
			array[indexOfNew--] = '0';
			array[indexOfNew--] = '2';
			array[indexOfNew--] = '%';
		}
		else
		{
			array[indexOfNew--] = array[indexOfOriginal];
		}
		indexOfOriginal--;
	}
	printf("%s\n",array);
}

int main()
{
	char array[15] = "123 123";
	printf("%s\n",array);
	replaceBlank(array,15);
}
