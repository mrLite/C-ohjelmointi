/* This progran reads characters typed at the keyboard and writes them 
   one at a time to a disk file, then reads from the same file and
   displays the characters.
*/

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[]) {
	if(argc > 1) {
		FILE *fptr;
		int ch;

		puts("Enter what you want to save in the file.");
		puts("End your input with a Return key.");

		if((fptr = fopen(argv[1], "a+")) == NULL)
		{
			printf("Failed to open file\n");
		 	exit(1);
		}
		while((ch = getchar()) != '\n')
		    putc(ch, fptr);
		putc('\n', fptr);
		rewind(fptr);

		puts("The contents of the file is : ");
		while ((ch = getc(fptr)) != EOF)
		    putchar(ch);

		fclose(fptr);
	}
	else {
		puts("Plz give me a filename!");
	}
	return 0;
}
