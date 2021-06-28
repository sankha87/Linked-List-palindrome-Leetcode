#define _CRT_SECURE_NO_WARNINGS
//https://leetcode.com/problems/palindrome-linked-list/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct ListNode {
	int val;
	struct ListNode *next;
};

ListNode* push(ListNode *head_ref, int num)
{
	struct ListNode *new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
	new_node->val = num;
	new_node->next = head_ref;
	head_ref = new_node;
	return head_ref;
}

void append(ListNode *head_ref, int num)
{
	if (head_ref == NULL)
	{
		printf("This function cannot be used to add a node to an Empty list \n");
		return;
	}
	struct ListNode *head_ref2 = head_ref;
	struct ListNode *new_node = (struct ListNode*) malloc(sizeof(struct ListNode));
	new_node->val = num;
	new_node->next = NULL;
	while (head_ref2->next != NULL)
		head_ref2 = head_ref2->next;
	head_ref2->next = new_node;
}

void display(struct ListNode *head_ref)
{
	struct ListNode *temp = head_ref;
	if (head_ref == NULL)
	{
		printf("List is empty \n\n");
		return;
	}
	while (temp != NULL)
	{
		printf("%d  ", temp->val);
		temp = temp->next;
	}
}

bool isPalindrome(struct ListNode *head) 
{
	struct ListNode *fast = head;
	struct ListNode *slow = head;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	fast = head;

	//reverse slow linked list
	struct ListNode *prev, *ptr, *next;
	prev = NULL;
	ptr = slow;
	while (ptr != NULL)
	{
		next = ptr->next;
		ptr->next = prev;
		prev = ptr;
		ptr = next;
	}
	slow = prev;

	while (slow != NULL)
	{
		if (slow->val != fast->val)
			return false;
		slow = slow->next;
		fast = fast->next;
	}

	return true;
}

void main()
{
	struct ListNode *head = NULL;
	int num;
	char choice;
	while (1)
	{
		printf("\n\n1. Display \n");
		printf("2. Add node to empty list / Add at beginning \n");
		printf("3. Add node at the end \n");
		printf("4. Palindrome? \n");
		printf("5. Exit \n");

		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			display(head);
			break;
		case 2:
			printf("Enter the number to be inserted: ");
			scanf("%d", &num);
			head = push(head, num);
			break;
		case 3:
			printf("Enter the number to be inserted: ");
			scanf("%d", &num);
			append(head, num);
			break;
		case 4:
			if (isPalindrome(head))
				printf("\nPalindrome LinkedList");
			else
				printf("\nNot palindrome LinkedList");
			break;
		case 5:
			exit(1);
		default: printf("Invalid choice \n\n");
		}
	}
	_getch();
}