#include <stdio.h>
#include <stdlib.h>

typedef struct list_node {
	int value;
	struct list_node* next;
} list_node;

void add(list_node** position, int value) {
	list_node* new = malloc(sizeof(list_node));
	new->value = value;
	
	new->next = *position;
	*position = new;
	return;
}

void delete(list_node* prev, list_node** position) {
	if(*position == NULL) {
		printf("List is empty.\n");
		return;
	}
	list_node* deleted = *position;
	if(prev == NULL)
		*position = (*position)->next;
	else
		prev->next = (*position)->next;
	free(deleted);
	return;
}

void print_list(list_node* head) {
	list_node* current = head;

	while(current != NULL) {
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
}

int main(void) {
	list_node* head = NULL;
	add(&head, 1);
	add(&(head->next), 2);
	add(&((head->next)->next), 3);
	add(&head, 666);
	print_list(head);
	delete(head, &(head->next));
	print_list(head);
	delete(head->next, &((head->next)->next));
	print_list(head);
	delete(NULL, &head);
	print_list(head);
	delete(NULL, &head);
	print_list(head);
	
	return(EXIT_SUCCESS);
}