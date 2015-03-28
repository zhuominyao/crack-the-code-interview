//在一个数组中，有两个数出现了一次，其他的数都出现了两次。找出这两个只出现了一次的数

#include <iostream>

using namespace std;

void findNumber(int * array,int length)
{
	int A_XOR_B = 0;
	int tempArray1[length];
	int tempArray2[length];
	int index1 = -1;
	int index2 = -1;
	unsigned int first_bit = 0;

	for(int i = 0;i < length;i++)
		A_XOR_B = A_XOR_B ^ array[i];
	
	while(A_XOR_B & (1 >> first_bit) == 0)
		first_bit++;

	cout<<first_bit<<endl;

	for(int i = 0;i < length;i++)
	{
		if((array[i] & (1 >> first_bit)) == 0)
		{
			index1++;
			tempArray1[index1] = array[i];
		}
		else
		{
			index2++;
			tempArray2[index2] = array[i];
		}
	}
	
	int A = 0;
	for(int i = 0;i <= index1;i++)
	{
		A = A ^ tempArray1[i];
		cout<<tempArray1[i]<<" ";
	}
	cout<<endl;
	cout<<A<<endl;

	int B = 0;
	for(int i = 0;i <= index2;i++)
	{
		B = B ^ tempArray2[i];
		cout<<tempArray2[i]<<" ";
	}
	cout<<endl;
	cout<<B<<endl;
}

int main()
{
	int array[10] = {1,1,10,9,3,3,4,4,5,5};
	findNumber(array,10);
}
