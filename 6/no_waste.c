#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "no_waste.h"

void print_city(city* C);

int read_line(FILE* fptr) {
	char line[MAX_LEN+1];
	
	if(fgets(line, (int)MAX_LEN, fptr) == NULL) {
		return -1;
	}
	if((line[0] == '#') || (line[0] == '\n')) {
		return 0;
	}
	
	return 1;
}

city* read_city(FILE* fptr) {
	char line[MAX_LEN+1];
	
	if(fgets(line, (int)MAX_LEN, fptr) == NULL) {
		return NULL;
	}
	if((line[0] == '#') || (line[0] == '\n')) {
		return NULL;
	}
	
	city* ret = malloc(sizeof(city));
	sscanf(line, "%s %lf %lf", ret->name, &ret->latitude, &ret->longitude);
	print_city(ret);

	return ret;
}

int count_cities(FILE* fptr) {
	rewind(fptr);
	int count = 0;
	int i;
	while((i = read_line(fptr)) >= 0) {
		count += i;
	}
	return count;
}

void read_cities(FILE* fptr, city* cities[], int city_c) {
	rewind(fptr);
	
	for(int i = 0; i < city_c;) {
		city* read = read_city(fptr);
		if(read != NULL) {
			cities[i] = read;
			++i;
		}
	}
	return;
}

void print_city(city* C) {
	printf("%s (%f, %f)\n", C->name, C->latitude, C->longitude);
	return;
}

void print_cities(city* cities[], int city_c) {	
	for(int i = 0; i < city_c; ++i) {
		print_city(cities[i]);
	}
	return;
}

int main(int argc, char* argv[]) {
	if(argc > 1) {
		FILE* fptr = fopen(argv[1], "r");
		assert(fptr != NULL);
		
		int city_c = count_cities(fptr);
		printf("City count: %d\n", city_c);
		
		city* cities[city_c];
		
		read_cities(fptr, cities, city_c);
		print_cities(cities, city_c);
		
		fclose(fptr);
	}
	return EXIT_SUCCESS;
}