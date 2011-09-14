#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node* prev;
	struct node* next;
} node;

void add(node** position, int value) {
	node* new_node = malloc(sizeof(node));

	new_node->value = value;
	new_node->next = *position;
	if(*position == NULL) {
		new_node->prev = NULL;
	}
	else {
		new_node->prev = (**position).prev;
		(**position).prev = new_node;
	}
	*position = new_node;
}

void print_list(node* head) {
	node* current = head;

	while (current != NULL) {
		printf("%d\n", current->value);
		current = current->next;
	}
}

int main(void) {
	node* first = NULL;
	// add(&first, 20);
	// add(&(first->next), 40);
	// node* second = first->next;
	// add(&(second->next), 80);
	// node* third = second->next;
	// add(&(third->next), 160);
	// print_list(first);
	// add(&first, 10);
	// print_list(first);
	// add(&second, 1212);
	// print_list(first);
	for(int i = 1; i <= 10; i++) {
		add(&first, i*i);
	}
	print_list(first);
	node* second = first->next;
	add(&second, 42);
	printf("\n");
	print_list(first);
}