#include <stdio.h>
#include <stdlib.h>

typedef struct dl_list_node {
	int value;
	struct dl_list_node* prev;
	struct dl_list_node* next;
} dl_list_node;

void add(dl_list_node** position, int value) {
	dl_list_node* new = malloc(sizeof(dl_list_node));
	new->value = value;
	
	new->prev = NULL;
	new->next = *position;
	
	if(*position != NULL) {
		new->prev = (*position)->prev;
		(*position)->prev = new;
	}
	*position = new;
	return;
}

void print_list(dl_list_node* head) {
	dl_list_node* current = head;
	while (current != NULL) {
		printf("%d\n", current->value);
		current = current->next;
	}
}

void print_list_reverse(dl_list_node* tail) {
	dl_list_node* current = tail;
	while(current != NULL) {
		printf("%d\n", current->value);
		current = current->prev;
	}
}

int main(void) {
	dl_list_node* head = NULL;
	add(&head, 1);
	add(&head, 2);
	add(&head, 3);
	print_list(head);
	printf("\n");
	add(&(head->next), 666);
	print_list(head);
	printf("\n");
	dl_list_node* tail = ((head->next)->next)->next;
	print_list_reverse(tail);
}