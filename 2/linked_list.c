#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

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