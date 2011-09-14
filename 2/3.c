#include <stdio.h>
#include <stdlib.h>

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
	double nums[5] = { 3.14159, 2.71828, 1.41421, 1.61803, 4.66920 };
	print_doubles(nums, 5);
	return 0;
}