#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int abs(int number) {
	return sqrt(number*number);
}

int main(void) {
	int num1 = -4;
	int num2 = 13;
	int num3 = -22;
	
	printf("%d\n", abs(num1));
	printf("%d\n", abs(num2));
	printf("%d\n", abs(num3));
	
	return 0;
}