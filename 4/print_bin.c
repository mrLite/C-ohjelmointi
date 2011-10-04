#include <stdio.h>
#include <stdlib.h>
#include "print_bin.h"

// Ex. 1
void print_bin(int value) {
	char bin[36];
	int mask = 1;
	
	for(int i = 34; i >= 0; i--) {
		if((i == 8) || (i == 17) || (i == 26))
			bin[i] = '.';
		else {
			int f = value & mask;
			if(f > 0)
				bin[i] = '0'+1;
			else
				bin[i] = '0';
			mask <<= 1;
		}
	}
	printf("%s\n", bin);
	return;
}