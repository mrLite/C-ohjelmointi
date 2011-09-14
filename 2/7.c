#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node* prev;
	struct node* next;
} node;

void add(node** prev_pos, node** next_pos, int value) {
	node* new_node = malloc(sizeof(node));
	new_node->value = value;
	
	new_node->next = *next_pos;
	if(*next_pos != NULL) {
		(*next_pos)->prev = new_node;
	}
	new_node->prev = *prev_pos;
	if(*prev_pos != NULL) {
		(*prev_pos)->next = new_node;
	}
	if(*prev_pos == NULL) {
		next_pos = &new_node;
	}
	if(*next_pos == NULL) {
		prev_pos = &new_node;
	}
}

void print_list(node* head) {
	node* current = head;

	while (current != NULL) {
		printf("%d\n", current->value);
		current = current->next;
	}
}

int main(void) {
	node* null = NULL;
	node* head = NULL;
	node* tail = NULL;
	add(&head, &tail, 1);
	print_list(tail);
	print_list(head);
	add(&null, &head, 2);
	print_list(tail);
	print_list(head);
}