#include <stdio.h>

int main(int argc, char *argv []) {
	int ch;
	int chc = 0;
	int wc = 0;
	FILE *fptr;
	
	if(argc > 1) {
		fptr = fopen(argv[1], "r");
		while ((ch = getc(fptr)) != EOF)
			if (ch == ' ' || ch == '\t' || ch == '\n') {
				wc++;
				chc++;
			}
			else {
				chc++;
			}	
		fclose (fptr);
	}
	printf("Word count is %d\n", wc);
	printf("Character count is %d\n", chc);
	return 0;
}