//用两个栈来实现一个队列

#include <stack>
#include <stdlib.h>
#include <iostream>

using namespace std;

template<class T>
class CQueue
{
	private:
		stack<T> stack1;
		stack<T> stack2;
	
	public:
		void appendTail(const T& node);
		T deleteHead();
};

template<class T>
void CQueue<T>::appendTail(const T& node)
{
	stack1.push(node);
}

template<class T>
T CQueue<T>::deleteHead()
{
	if(stack2.size() == 0)
	{
		while(stack1.size() > 0)
		{
			T temp = stack1.top();
			stack1.pop();
			stack2.push(temp);
		}
	}
	if(stack2.size() == 0)
	{
		cout<<"the queue is empty"<<endl;
		exit(-1);
	}
	T head = stack2.top();
	stack2.pop();
	return head;
}

int main()
{
	CQueue<int> queue;
	queue.appendTail(1);
	queue.appendTail(2);
	queue.appendTail(3);
	queue.appendTail(4);
	queue.appendTail(5);
	for(int i = 0;i < 3;i++)
	{
		cout<<queue.deleteHead()<<endl;
	}
}
