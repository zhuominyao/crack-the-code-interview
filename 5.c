//从尾到头打印链表

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int key;
	ListNode * next;
};
//这里采用递归来实现，也可以借助栈，采用循环来实现
void printLinkListReversingly(ListNode * head)
{
	if(head == NULL)
		return;
	if(head->next != NULL)
		printLinkListReversingly(head->next);
	else
	{
		printf("%d\n",head->key);
		return;
	}
	printf("%d\n",head->key);
}

int main()
{
	ListNode * node1 = new ListNode();
	ListNode * node2 = new ListNode();
	ListNode * node3 = new ListNode();
	ListNode * node4 = new ListNode();
	ListNode * node5 = new ListNode();
	node1->key = 1;
	node2->key = 2;
	node3->key = 3;
	node4->key = 4;
	node5->key = 5;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;
	printLinkListReversingly(node1);
}
