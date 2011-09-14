#include <stdio.h>
#include <stdlib.h>
#include "print_doubles.h"

void print_doubles(double* array, int len) {
	int counter = 0;
	if(len > 0) {
		while(counter < len) {
			printf("%.5f\n", array[counter]);
			counter++;
		}
	}
}