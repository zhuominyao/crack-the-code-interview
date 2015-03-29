//实现double power(double base,int exp)，不得使用库函数，不用考虑大数的情况

#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

double powerUnsignedInt(double base,int exp);

bool equal(double n1,double n2)
{
	if(abs(n1 - n2) < 0.0000001)
		return true;
	else
		return false;
}

double power(double base,int exp)
{
	if(equal(base,0.0) && exp <= 0)
	{
		cout<<"非法输入"<<endl;
		exit(-1);
	}
	if(exp < 0)
	{
		exp = exp * -1;
		base = 1.0 / base;
	}
	return powerUnsignedInt(base,exp);
}

double powerUnsignedInt(double base,int exp)
{
	if(exp == 0)
		return 1;
	if(exp == 1)
		return base;

	double result = powerUnsignedInt(base,exp>>1);
	result = result * result;
	if(exp & 0x01 == 1)
		result = result * base;
	return result;
}

int main()
{
	cout<<power(3,3)<<endl;
}
