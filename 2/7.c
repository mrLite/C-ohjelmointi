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

void delete(dl_list_node** position) {
	if(*position == NULL) {
		printf("List is empty.\n");
		return;
	}
	dl_list_node* deleted = *position;

	*position = (*position)->next;
	(*position)->prev = deleted->prev;
	
	free(deleted);
	return;
}

void print_list(dl_list_node* head) {
	dl_list_node* current = head;
	while (current != NULL) {
		printf("%d ", current->value);
		current = current->next;
	}
	if(head != NULL)
		printf("\n");
}

void print_list_reverse(dl_list_node* tail) {
	dl_list_node* current = tail;
	while(current != NULL) {
		printf("%d ", current->value);
		current = current->prev;
	}
	if(tail != NULL)
		printf("\n");
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
	printf("\nreverse list\n");
	dl_list_node* tail = ((head->next)->next)->next;
	print_list_reverse(tail);
	printf("\ndeleted 666\n");
	delete(&(head->next));
	print_list(head);
	tail = (head->next)->next;
	printf("\n");
	print_list_reverse(tail);
}