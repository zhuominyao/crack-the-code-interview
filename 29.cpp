//找出一个数组中出现次数超过数组长度一半的元素

#include <iostream>

using namespace std;

bool inputLeagle = true;

void swap(int * a,int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int * array,int l,int h)
{
	int index = l - 1;
	int target = array[h];
	for(int i = l;i <= h-1;i++)
	{
		if(array[i] < target)
		{
			index++;
			swap(&array[index],&array[i]);
		}
	}
	swap(&array[index+1],&array[h]);
	return index+1;
}

int MoreThenHalfNum(int * array,int length)
{
	if(array == NULL || length <= 0)
	{
		inputLeagle = false;
		return -1;
	}
	int target = length>>1;
	int start = 0;
	int end = length - 1;
	int pos = partition(array,start,end);
	while(pos != target)
	{
		if(pos > target)
		{
			end = pos - 1;
			pos = partition(array,start,end);
		}
		else
		{
			start = pos + 1;
			pos = partition(array,start,end);
		}
	}
	return array[pos];
}

int main()
{
	int array[5] = {1,2,2,2,3};
	cout<<MoreThenHalfNum(array,5);
}
