#include <stdio.h>
#include "linkedlist.h"


int list_length(struct ListNode* head)
{
	struct ListNode* current = head;
	int count = 0;

	while (current) {
		++count;
		current = current->next;
	}
	return count;
}

void insert_node(struct ListNode** head, int data, int position)
{
	int k = 1;
	struct ListNode* p, * q, * new_node;

	new_node = (struct ListNode*)malloc(sizeof(struct ListNode));

	if (!new_node) {
		printf("Memory sufficient!");
		return;
	}

	new_node->data = data;
	p = *head;

	if (position == 1) {
		new_node->next = p;
		*head = new_node;
		return;
	}

	else {
		while (p && (k < position - 1)) {
			++k;
			q = p;
			p = p->next;
		}
	}

	if (!p) {
		q->next = new_node;
		new_node->next = NULL;
	}
	
	else {
		q->next = new_node;
		new_node->next = p;
	}
	
}

void delete_node(struct ListNode** head, int position)
{
	int k = 1;
	struct ListNode* p, * q;

	if (!*head) {
		printf("List is empty!");
		return;
	}

	p = *head;

	if (position == 1) {
		p = *head;
		*head = *head->next;
		free(p);
		return;
	}
	else {
		while (p && (k < position - 1)) {
			++k;
			q = p;
			p = p->next;
		}
		if (!p) {
			printf("Position does not exist");
		}
		else {
			q->next = p->next;
			free(p);
		}
	}
}

void delete_list(struct ListNode** head)
{
	struct ListNode* auxilary_node, * iterator;
	iterator = *head;

	while (iterator) {
		auxilary_node = iterator->next;
		free(iterator);
		iterator = auxilary_node;
	}
	*head = NULL;
}
