#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(void* a, void* b, size_t elem_size)
{
    char* ca = a;
    char* cb = b;
    for (size_t i = 0; i < elem_size; i++)
    {
        char temp = ca[i];
        ca[i] = cb[i];
        cb[i] = temp;
    }
    return;
}

void shuffle(void* array, int len, size_t elem_size) {
	for(int i = 0; i < len; i++) {
		int r = rand()%len;
		swap((char*)array+i*elem_size, (char*)array+r*elem_size, elem_size);
	}
}

void print_doubles(double* array, int len) {
	int counter = 0;
	if(len > 0) {
		while(counter < len) {
			printf("%.5f\n", array[counter]);
			counter++;
		}
	}
}

int main(void) {
	srand(time(NULL));
	double nums[5] = { 1.5, 3.5, 5.5, 7.5, 9.5};
	shuffle(nums, 5, sizeof(double));
	print_doubles(nums, 5);
	
	return EXIT_SUCCESS;
}