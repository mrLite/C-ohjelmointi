#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float a = 1.0;
	float aa = 6.66;
	float aaa = 1.001;
	float aaaa = 2.345;
	float aaaaa = 3.14159;
	
	printf("%.1f\n", a);
	printf("%.2f\n", aa);
	printf("%.3f\n", aaa);
	printf("%.4f\n", aaaa);
	printf("%.5f\n", aaaaa);
	
	return 0;
}