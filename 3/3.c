#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	if(argc > 1) {
		FILE* fptr;
		if((fptr = fopen(argv[1], "r")) == NULL) {
			printf("Failed to open file %s\n", argv[1]);
			return EXIT_FAILURE;
		}
		
		
	}
	return EXIT_SUCCESS;
}