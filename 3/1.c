#include <stdio.h>

int main(int argc, char *argv []) {
	int ch;
	FILE *fptr;
	if(argc > 1) {
		fptr = fopen(argv[1], "r");
		while ((ch = getc(fptr)) != EOF)
			if (ch == ' ' || ch == '\t')
				putchar ('\n');
			else
				putchar (ch);
		fclose (fptr);
	}
	return 0;
}