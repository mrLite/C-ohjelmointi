#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "print_bin.h"

// Ex. 2
uint16_t make_16bit(uint8_t ls, uint8_t ms) {
	uint16_t result = 0;
	result += (ms << 8);
	result += ls;
	return result;
}

// Ex. 3
uint32_t make_32bit(uint8_t byte1, uint8_t byte2, uint8_t byte3, uint8_t byte4) {
	uint32_t result = 0;
	result += (byte4 << 24);
	result += (byte3 << 16);
	result += (byte2 << 8);
	result += byte1;
	return result;
}

// Ex. 4
uint8_t read_lsb(FILE* fptr) {
	uint8_t result = 0;
	uint8_t mask = 1;
	uint8_t byte = (uint8_t)(getc(fptr));
	result = byte & mask;
	return result;
}

// Ex. 5
uint8_t extract_byte(FILE* fptr) {
	uint8_t result = 0;
	uint8_t next_bit;
	for(int i = 0; i < 8; i++) {
		next_bit = read_lsb(fptr);
		next_bit <<= i;
		result += next_bit;
	}
	return result;
}

// Ex. 6
uint32_t read_uint32(FILE* fptr) {
	uint8_t b1 = (uint8_t)getc(fptr);
	uint8_t b2 = (uint8_t)getc(fptr);
	uint8_t b3 = (uint8_t)getc(fptr);
	uint8_t b4 = (uint8_t)getc(fptr);
	return make_32bit(b1,b2,b3,b4);
}

// Ex. 7
uint32_t read_pixel_offset(FILE* fptr) {
	fseek(fptr, 0xa, SEEK_SET);
	return read_uint32(fptr);
}

// Ex. 8
void reveal_message(FILE* fptr) {
	uint32_t offset = read_pixel_offset(fptr);
	fseek(fptr, offset, SEEK_SET);
	uint8_t next_byte;
	while((next_byte = extract_byte(fptr))) {
		printf("%c", (char)next_byte);
	}
	return;
}

int main(int argc, char* argv[]) {
	if(argc > 1) {
		FILE* fptr;
		if((fptr = fopen(argv[1], "rb")) != NULL) {
			reveal_message(fptr);
			fclose(fptr);
		}
		else {
			printf("Couldn't open file %s!\n", argv[1]);
		}
	}
	return EXIT_SUCCESS;
}