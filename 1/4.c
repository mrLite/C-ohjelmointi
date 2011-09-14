#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char forename[20];
	char surname[20];
	int birth_year;
	
	printf("plz enter ur forename\n");
	scanf("%19s", forename);
	printf("now ur surname\n");
	scanf("%19s", surname);
	printf("and ur year of birth\n");
	scanf("%4d", &birth_year);
	
	printf("\nHere's ur info:\n");
	printf("%s\n", forename);
	printf("%s\n", surname);
	printf("%d\n", birth_year);
	
	return 0;
}