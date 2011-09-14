#include <stdio.h>
#include <stdlib.h>

typedef struct list_node {
	int value;
	struct list_node* next;
} list_node;

void add(list_node* position, int value) {
	list_node* new_node = malloc(sizeof(list_node));

	new_node->value = value;
	new_node->next = (*position).next;
	(*position).next = new_node;
}

void delete(list_node* position) {
	list_node* deleted = (*position).next;
	(*position).next = (*deleted).next;
	free(deleted);
}

void print_list(list_node* head) {
	list_node* current = head;

	while (current != NULL) {
		printf("%d\n", current->value);
		current = current->next;
	}
	printf("\n");
}

int main(void) {
	list_node first = { 10, NULL };
	print_list(&first);
	add(&first, 20);
	print_list(&first);
	add(&first, 40);
	print_list(&first);
	delete(&first);
	print_list(&first);
}