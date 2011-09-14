#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int i = 12;
	int j = 666;
	long ix = 1212412541352;
	short s = 1;
	float x = 2.1;
	double dx = 101.101;
	char c = 'a';
	unsigned long ux = 20000000000000;
	
	printf("%d\n", i+c);
	printf("%f\n", x+c);
	printf("%f\n", dx+x);
	printf("%ld\n", ((int)dx)+ix);
	printf("%f\n", i+x);
	printf("%d\n", s+j);
	printf("%ld\n", ix+j);
	printf("%d\n", s+c);
	printf("%ld\n", ix+c);
	printf("%ld\n", ix+ux);
}