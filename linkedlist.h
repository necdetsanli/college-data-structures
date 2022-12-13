#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct ListNode {
	int data;
	struct ListNode* next;
};

int list_length(struct ListNode* head);

void insert_node(struct ListNode** head, int data, int position);

void delete_node(struct ListNode** head, int position);

void delete_list(struct ListNode** head);

#endif
