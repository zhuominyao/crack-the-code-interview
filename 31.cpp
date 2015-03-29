//给定一个数组，求该数组所有子数组的最大和

#include <iostream>

using namespace std;

int MaxSum(int * array,int length)
{
	int sum[length];
	int max = array[0];
	for(int i = 0;i < length;i++)
	{
		if(i == 0)
			sum[i] = array[i];
		else if(sum[i-1] < 0)
			sum[i] = array[i];
		else if(sum[i-1] > 0)
			sum[i] = array[i] + sum[i-1];
		if(sum[i] > max)
			max = sum[i];
	}
	return max;
}

int main()
{
	int array[8] = {1,-2,3,10,-4,7,2,-5};
	cout<<MaxSum(array,8)<<endl;
}
