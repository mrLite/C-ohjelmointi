#include <stdio.h>
#include <stdlib.h>
#include "dynarray.h"

dyn_array* create(void) {
	dyn_array* arr = malloc(sizeof(dyn_array));
	if(arr == NULL) {
		return NULL;
	}
	else {
		arr->array = malloc(10*sizeof(int));
		if(arr->array == NULL) {
			return NULL;
		}
		else {
			arr->elements = 0;
			arr->size = 10;
		}
	}
	return arr;
}

void destroy(dyn_array* arr) {
	if(arr == NULL) {
		return;
	}
	free(arr->array);
	free(arr);
	return;
}

int append(dyn_array* arr, int number) {
	if(arr->elements == arr->size) {
		arr->array = realloc(arr->array, 2*(arr->size)*sizeof(int));
		if(arr->array == NULL) {
			return 0;
		}
		else {
			arr->size = 2*(arr->size);
		}
	}
	(arr->array)[arr->elements] = number;
	(arr->elements)++;
	return 1;
}

int get(dyn_array* arr, int index) {
	if(arr == NULL) {
		printf("NULL array!\n");
		return 0;
	}
	else if(index < 0 || index >= arr->elements) {
		printf("invalid array index!\n");
		return 0;
	}
	else {
		int ret = (arr->array)[index];
		return ret;
	}
}