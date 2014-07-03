#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *sortList(ListNode *head)
{
	ListNode *cur, *parent_cur;
	ListNode *p, *parent_p;
	parent_cur = head;
	while (parent_cur && parent_cur->next)
	{
		cur = parent_cur->next;
		p = head;
		parent_p = NULL;
		while (p && p != cur && p->val <= cur->val)
		{
			parent_p = p;
			p = p->next;
		}
		if(p->val > cur->val)
		{//需要移动
			parent_cur->next = cur->next;
			cur->next = p;
			if (parent_p != NULL)
				parent_p->next = cur;
			else//改变头结点
				head = cur;
		}
		else//不需要移动
			parent_cur = parent_cur->next;
	}
	
	return head;
}
ListNode* insert(int val, ListNode *head)
{
	ListNode *newNode = new ListNode(val);
	newNode->next = head;
	return newNode;
}

void print(ListNode *head)
{
	ListNode *p = head;
	while(p)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}


int main()
{
	ListNode *head = NULL;
	//int a[] = {8, 9, 10, 2, 3, 1, 9, 18, 12, 0, 7, 4, 6};
	int a;
	srand((int)time(0));
	for (int i = 0; i < 130000; i++)
	{
		a = 3*(rand()/(RAND_MAX+1.0)) + 1;
		head = insert(a, head);
	}
	//print(head);
	head = sortList(head);
	print(head);
	
	return 0;
}