//包含min操作的栈，并且保证min(),push(),top()操作的复杂度都是O(1)

#include <iostream>
#include <stack>

using namespace std;

template<class T>
class StackWithMin
{
	public:
		T pop();
		void push(T element);
		T min();
	private:
		stack<T> stack1;
		stack<T> stack2;
		T minElement;
};

template<class T>
T StackWithMin<T>::pop()
{
	if(stack1.size() == 0)
	{
		cout<<"栈为空"<<endl;
		return NULL;
	}
	else
	{
		stack2.pop();
		return stack1.pop();
	}
	
}

template<class T>
void StackWithMin<T>::push(T element)
{
	if(stack1.size() == 0)
	{
		minElement = element;
		stack1.push(element);
		stack2.push(minElement);
	}
	else
	{
		if(element < minElement)
			minElement = element;
		stack1.push(element);
		stack2.push(minElement);
	}
}

template<class T>
T StackWithMin<T>::min()
{
	return stack2.top();
}

int main()
{
	
}
