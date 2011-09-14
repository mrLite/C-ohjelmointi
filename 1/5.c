#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char* names[10];
	int birth_year;
	int counter = 0;
	
	for(int n = 0; n < 10; n++) {
		names[n] = malloc(20*sizeof(char));
	}
	
	while(counter < 10) {
		printf("Enter a name. 0 will stop.\n");
		scanf("%19s", names[counter]);
		if(*names[counter] == '0') {
			break;
		}
		counter++;
	}
	printf("Enter ur year of birth\n");
	scanf("%4d", &birth_year);
	
	printf("\nHere's ur info:\n");
	for(int i = 0; i < counter; i++) {
		printf("%s\n", names[i]);
	}
	printf("%d\n", birth_year);
	
	return 0;
}