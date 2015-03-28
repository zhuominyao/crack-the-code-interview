//找出给定数在排序数组中的重复次数

#include <iostream>
#include <stdlib.h>

using namespace std;

int findFirstK(int * array,int left,int right,int target,int length)
{
	if(left > right)
		return -1;
	int middle = (left + right) / 2;
	if(array[middle] > target)
		return findFirstK(array,left,middle - 1,target,length);
	else if(array[middle] < target)
		return findFirstK(array,middle + 1,right,target,length);
	else if(array[middle] == target && ((middle - 1) >= 0 && array[middle - 1] == target))
		return findFirstK(array,left,middle - 1,target,length);
	else if(array[middle] == target)
		return middle;
}

int findLastK(int * array,int left,int right,int target,int length)
{
	if(left > right)
		return -1;
	int middle = (left + right) / 2;
	if(array[middle] > target)
		return findLastK(array,left,middle - 1,target,length);
	else if(array[middle] < target)
		return findLastK(array,middle + 1,right,target,length);
	else if(array[middle] == target && (middle + 1) < length && array[middle + 1] == target)
		return findLastK(array,middle + 1,right,target,length);
	else if(array[middle] == target)
		return middle;
}

int main()
{
	int array[6] = {1,2,3,3,3,6};
	int first = findFirstK(array,0,5,5,6);
	int last = findLastK(array,0,5,5,6);
	if(first == -1)
	{
		cout<<"there is no target in array"<<endl;
		exit(-1);
	}
	else
		cout<<last-first<<" times"<<endl;
}
