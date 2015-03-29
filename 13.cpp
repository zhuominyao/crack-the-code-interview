//在O(1)时间内删除链表内的给定节点

#include <iostream>

using namespace std;

struct ListNode
{
	int key;
	ListNode * next;
};

void deleteListNode(ListNode * head,ListNode * node)
{
	if(head == NULL)
		return;
	if(head->next == NULL)
	{
		head = NULL;
		return;
	}
	
	if(node->next == NULL)
	{
		while(head->next != node)
			head = head->next;
		head->next = NULL;
		delete node;
	}
	else
	{
		node->key = node->next->key;
		node->next = node->next->next;
	}
}

int main()
{

}
