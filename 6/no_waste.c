#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
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

double to_radians(double deg) {
	return deg*(3.14159/180);
}

double distance(city* from, city* to) {
	double f_lat_rad = to_radians(from->latitude);
	double t_lat_rad = to_radians(to->latitude);
	double f_lon_rad = to_radians(from->longitude);
	double t_lon_rad = to_radians(to->longitude);
	
	double diff_lat = fabs(t_lat_rad - f_lat_rad);
	double diff_lon = fabs(t_lon_rad - f_lon_rad);
	
	double a = sin(diff_lat/2)*sin(diff_lat/2) + (cos(f_lat_rad)*cos(t_lat_rad)*sin(diff_lon/2)*sin(diff_lon/2));
	
	double c = 2*atan2(sqrt(a), sqrt(1-a));
	
	return c*EARTH_RADIUS;
}

double path_distance(city** cities, int city_c) {
	double dist = 0;
	for(int i = 0; i < city_c-1; ++i) {
		dist += distance(cities[i], cities[i+1]);
	}
	dist += distance(cities[city_c-1], cities[0]);
	return dist;
}

void free_cities(city* cities[], int city_c) {
	for(int i = 0; i < city_c; ++i) {
		free(cities[i]);
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
		printf("Distance between Helsinki and Espoo: %f km\n", distance(cities[1], cities[4]));
		printf("Path distance: %f km\n", path_distance(cities, city_c));
		
		free_cities(cities, city_c);
		fclose(fptr);
	}
	return EXIT_SUCCESS;
}