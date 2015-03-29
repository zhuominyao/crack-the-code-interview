//将数组中所有奇数调整到所有偶数前面

#include <iostream>

using namespace std;

void reorder(int * array,int length)
{
	if(array == NULL || length <= 0)
	{
		cout<<"非法输入"<<endl;
		return;
	}
	int left = 0;
	int right = length - 1;
	while(left < right)
	{
		while(left < right && array[left] % 2 == 1)
			left++;
		while(left < right && array[right] % 2 == 0)
			right--;
		if(left < right)
		{
			int temp = array[left];
			array[left] = array[right];
			array[right] = temp;
			left++;
			right--;
		}
	}
}

int main()
{
	int array[10] = {1,2,3,4,5,6,7,8,9,10};
	reorder(array,10);
	for(int i = 0;i < 10;i++)
		cout<<array[i]<<endl;
}
