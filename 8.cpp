//找出旋转数组中的最小值

#include <iostream>
#include <stdlib.h>

using namespace std;

int findMinInRotatedArray(int * array,int length)
{
	if(array == NULL || length <= 0)
	{
		cout<<"非法输入"<<endl;
		exit(-1);
	}
	int index1 = 0;
	int index2 = length - 1;
	int midIndex = index1;
	while(array[index1] >= array[index2])
	{
		if(index2 - index1 == 1)
		{
			midIndex = index2;
			break;
		}
		midIndex = (index1 + index2) / 2;
		if(array[midIndex] > array[index2])
			index1 = midIndex;
		else
			index2 = midIndex;
	}
	return array[midIndex];
}

int main()
{
	int array[6] = {5,6,1,2,3,4};
	cout<<findMinInRotatedArray(array,6);
}
