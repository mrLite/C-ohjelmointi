#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int i, j = 25;
	printf("a) Value of i: %d. Value of j: %d\n", i, j);
	printf("a) Value of &i: %p. Value of &j: %p\n", (void*)&i, (void*)&j);
	
	int *pi, *pj = &j;
	printf("b) Value of pi: %p. Value of pj: %p\n", (void*)pi, (void*)pj);
	printf("b) Value of *pi: NULL. Value of *pj: %d\n", *pj);
	
	*pj = j+5;
	printf("c) Value of pj: %p. Value of *pj: %d\n", (void*)pj, *pj);
	
	i = *pj+5;
	printf("d) Value of i: %d\n", i);
	
	pi = pj;
	printf("e) Value of pi: %p. Value of *pi: %d\n", (void*)pi, *pi);
	
	*pi = i+j;
	printf("f) Value of pi: %p. Value of *pi: %d\n", (void*)pi, *pi);
}