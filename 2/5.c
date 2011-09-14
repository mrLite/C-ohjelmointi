#include <stdio.h>
#include <stdlib.h>

typedef struct list_node {
	int value;
	struct list_node* next;
} list_node;

void add(list_node** head, int index, int value) {
	list_node* new_node = malloc(sizeof(list_node));
	if(new_node != NULL && index >= 0) {
		new_node->value = value;
		if(index == 0) {
			new_node->next = *head;
			*head = new_node;
			return;
		}
		else {
			list_node* current = *head;
			int count = 0;
			while(current != NULL) {
				if(count == index-1) {
					new_node->next = current->next;
					current->next = new_node;
					return;
				}
				count++;
				current = current->next;
			}
		}
	}
	return;
}

void delete(list_node** head, int index) {
	list_node* current = *head;
	int count = 0;
	
	if(current != NULL && index == 0) {
		*head = current->next;
		free(current);
		return;
	}
	
	while(current != NULL) {
		if(count == index-1) {
			list_node* deleted = current->next;
			if(deleted != NULL) {
				current->next = deleted->next;
				free(deleted);
			}
			return;
		}
		count++;
		current = current->next;
	}
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
	add(&head, 0, 1);
	add(&head, 0, 2);
	add(&head, 1, 3);
	add(&head, 3, 666);
	print_list(head);
	delete(&head, 3);
	printf("Deleted the last item from the list.\n");
	print_list(head);
	printf("Deleted the first item from the list.\n");
	delete(&head, 0);
	print_list(head);
}