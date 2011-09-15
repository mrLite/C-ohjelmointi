#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

typedef struct list_node {
	int value;
	struct list_node* next;
} list_node;

void add(list_node** head, int index, int value);
void delete(list_node** head, int index);
void print_list(list_node* head);

#endif