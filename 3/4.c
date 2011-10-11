#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv []) {
	int ch;
	int chc = 0;
	int wc = 0;
	FILE *fptr;
	
	if(argc > 1) {
		fptr = fopen(argv[1], "r");
		while(1) {
			ch = getc(fptr);
			if ((ch == ' ') || (ch == '\t') || (ch == '\n')) {
				wc++;
				chc++;
			}
			else if(ch == EOF) {
				wc++;
				break;
			}
			else {
				chc++;
			}
		}
		fclose (fptr);
	}
	printf("Word count is %d\n", wc);
	printf("Character count is %d\n", chc);
	return 0;
}