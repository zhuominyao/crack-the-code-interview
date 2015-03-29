//合并两个有序的链表

 #include <iostream>

using namespace std;

struct ListNode
{
	int key;
	ListNode * next;
};

ListNode * mergeTwoListNode(ListNode * list1,ListNode * list2)
{
	if(list1 == NULL)
		return list2;
	if(list2 == NULL)
		return list1;
	ListNode * temp = NULL;
	if(list1->key >= list2->key)
	{
		temp = list2;
		temp->next = mergeTwoListNode(list1,list2->next);
	}
	else
	{
		temp = list1;
		temp->next = mergeTwoListNode(list1->next,list2);
	}
}

int main()
{
	ListNode * node1 = new ListNode();
	ListNode * node2 = new ListNode();
	ListNode * node3 = new ListNode();
	node1->key = 1;
	node2->key = 3;
	node3->key = 5;
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	ListNode * node4 = new ListNode();
	ListNode * node5 = new ListNode();
	ListNode * node6 = new ListNode();
	node4->key = 2;
	node5->key = 4;
	node6->key = 6;
	node4->next = node5;
	node5->next = node6;
	node6->next = NULL;
	ListNode * newList = mergeTwoListNode(node1,node4);
	while(newList != NULL)
	{
		cout<<newList->key<<endl;
		newList = newList->next;
	}	
}
