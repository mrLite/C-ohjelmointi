#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle_ints(int* array, int len) {
	for(int i = 0; i < len; i++) {
		int r = rand()%len;
		int temp;
		temp = array[i];
		array[i] = array[r];
		array[r] = temp;
	}
}

int main(void) {
	srand(time(NULL));
	int nums[] = { 0, 1, 2, 3, 4, 5, 6 };
	shuffle_ints(nums, 7);
	for(int i = 0; i < 7; i++) {
		printf("%d ", nums[i]);
	}
	printf("\n");
	return 0;
}