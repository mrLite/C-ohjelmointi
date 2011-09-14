#ifndef __DYNARRAY_H__
#define __DYNARRAY_H__

typedef struct dyn_array {
	int elements;
	int size;
	int* array;
} dyn_array;

dyn_array* create(void);
void destroy(dyn_array* arr);
int append(dyn_array* arr, int number);
int get(dyn_array* arr, int index);

#endif