#include <stdio.h>
#include <stdlib.h>

typedef struct dl_list_node {
	int value;
	struct dl_list_node* prev;
	struct dl_list_node* next;
} dl_list_node;

typedef struct dl_list {
	struct dl_list_node* head;
	struct dl_list_node* tail;
} dl_list;

void add(dl_list* list, dl_list_node** position, int value) {
	dl_list_node* new = malloc(sizeof(dl_list_node));
	new->value = value;
	new->prev = NULL;
	new->next = *position;
	
	// Adding to an empty list.
	if(list->head == NULL) {
		list->head = new;
		list->tail = new;
	}
	// Adding to the end of the list.
	else if((list->tail)->next == *position) {
		new->prev = list->tail;
		list->tail = new;
	}
	// General case.
	else {
		new->prev = (*position)->prev;
		(*position)->prev = new;
	}
	
	*position = new;
	return;
}

void delete(dl_list* list, dl_list_node* position) {
	if(position == NULL) {
		printf("List is empty.\n");
		return;
	}
	dl_list_node* deleted = position;
	
	if(position->prev == NULL) {
		list->head = position->next;
	}
	else {
		(position->prev)->next = position->next;
	}
	
	if(position->next == NULL) {
		list->tail = position->prev;
	}
	else {
		(position->next)->prev = position->prev;
	}
	
	free(deleted);
	return;
}

void print_list(dl_list* list) {
	dl_list_node* current = list->head;
	printf("( ");
	while (current != NULL) {
		printf("%d ", current->value);
		current = current->next;
	}
	printf(")\n");
}

void print_list_reverse(dl_list* list) {
	dl_list_node* current = list->tail;
	printf("( ");
	while(current != NULL) {
		printf("%d ", current->value);
		current = current->prev;
	}
	printf(")\n");
}

int main(void) {
	dl_list list = {NULL, NULL};
	printf("List is empty:\n");
	print_list(&list);
	print_list_reverse(&list);
	printf("\n");
	
	add(&list, &(list.head), 2);
	add(&list, &(list.head), 1);
	// List should now be 1->2.
	
	printf("Added 1 and 2 to the list.\n");
	print_list(&list);
	print_list_reverse(&list);
	printf("\n");
	
	printf("Added 222, 333 and 666 to the list.\n");
	add(&list, &(list.head), 222);
	add(&list, &(((list.head)->next)->next), 333);
	add(&list, &((list.tail)->next), 666);
	print_list(&list);
	print_list_reverse(&list);
	printf("head: %d\ttail: %d\n", (list.head)->value, (list.tail)->value);
	printf("\n");
	
	printf("Deleted head (222) from the list.\n");
	delete(&list, (list.head));
	print_list(&list);
	print_list_reverse(&list);
	printf("head: %d\ttail: %d\n", (list.head)->value, (list.tail)->value);
	printf("\n");
	
	printf("Deleted node (333) from the middle of the list.\n");
	delete(&list, (list.head)->next);
	print_list(&list);
	print_list_reverse(&list);
	printf("head: %d\ttail: %d\n", (list.head)->value, (list.tail)->value);
	printf("\n");
	
	printf("Deleted tail (666) from the list.\n");
	delete(&list, (list.tail));
	print_list(&list);
	print_list_reverse(&list);
	printf("head: %d\ttail: %d\n", (list.head)->value, (list.tail)->value);
}