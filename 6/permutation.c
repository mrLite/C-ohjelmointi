#include <stdio.h>
#include <stdlib.h>
#include "permutation.h"

static void swap(unsigned int *ar, unsigned int first, unsigned int second) {
    unsigned int temp = ar[first];
    ar[first] = ar[second];
    ar[second] = temp;
}

static void reverse(unsigned int *ar, size_t len) {
    unsigned int i, j;

    for (i = 0, j = len - 1; i < j; i++, j--) {
        swap(ar, i, j);
    }
}

unsigned int MBnext_permutation(unsigned int *ar, size_t len) {
    unsigned int i1, i2;
    unsigned int result = 0;
    
    /* Find the rightmost element that is the first in a pair in ascending order */
    for (i1 = len - 2, i2 = len - 1; ar[i2] <= ar[i1] && i1 != 0; i1--, i2--);
    if (ar[i2] <= ar[i1]) {
        /* If not found, array is highest permutation */
        reverse(ar, len);
    }
    else {
        /* Find the rightmost element to the right of i1 that is greater than ar[i1] */
        for (i2 = len - 1; i2 > i1 && ar[i2] <= ar[i1]; i2--);
        /* Swap it with the first one */
        swap(ar, i1, i2);
        /* Reverse the remainder */
        reverse(ar + i1 + 1, len - i1 - 1);
        result = 1;
    }
    return result;
}

void print_array(unsigned int arr[], unsigned int count) {
	for(unsigned int i = 0; i < count; ++i) {
		printf("%d ", (int)arr[i]);
	}
	printf("\n");
	return;
}

int main(void) {
	unsigned int nums[] = {1,2,3,4,5,6};
	const unsigned int count = 6;
	unsigned int perms = 0;
	
	do {
		//print_array(nums, count);
		perms++;
	} while(MBnext_permutation(nums, count));
	
	printf("Permuations: %d\n", perms);
	
	return EXIT_SUCCESS;
}