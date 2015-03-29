//翻转链表

#include <iostream>

struct ListNode
{
	int key;
	ListNode * next;
};

using namespace std;

void reverseLinkList(ListNode * head)
{
	if(head == NULL || head->next == NULL)
		return;
	if(head->next->next == NULL)
	{
		ListNode * temp = head->next;
		temp->next = head;
		head->next = NULL;
		return;
	}
	ListNode * first;
	ListNode * second;
	ListNode * third;
	first = head;
	second = first->next;
	third = second->next;
	head->next = NULL;
	while(third != NULL)
	{
		second->next = first;
		first = second;
		second = third;
		third = third->next;
	}
	second->next = first;
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
	ListNode * temp = node1;
	while(temp != NULL)
	{
		cout<<temp->key<<endl;
		temp = temp->next;
	}
	reverseLinkList(node1);
	while(node5 != NULL)
	{
		cout<<node5->key<<endl;
		node5 = node5->next;
	}
}
