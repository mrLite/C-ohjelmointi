#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "the_map.h"
#define BAD_CHAR 'X'

// Ex. 6
int is_line_break(char ch) {
	if(ch == '\n' || ch == '\r')
		return 1;
	else
		return 0;
}

// Ex. 7
int get_file_length(char* filename) {
	int bytes;
	FILE* fptr;
	if((fptr = fopen(filename, "rb")) == NULL) {
		printf("Failed to open file %s\n", filename);
		return 0;
	}
	fseek(fptr, 0, SEEK_END);
	bytes = ftell(fptr);
	fclose(fptr);
	return bytes;
}

// Ex. 8
char* load_data(char* filename) {
	int length = get_file_length(filename);
	int i = 0;
	char* data = malloc(length*sizeof(char)+sizeof(char));
	char ch;
	FILE* fptr;
	
	if((fptr = fopen(filename, "r")) == NULL) {
		free(data);
		return NULL;
	}
	while((ch = getc(fptr)) != EOF) {
		data[i] = ch;
		i++;
	}
	data[i] = '\0';
	
	fclose(fptr);
	return data;
}

// Ex. 9
map* load_map(char* filename) {
	map* new_map = malloc(sizeof(map));
	if(new_map == NULL) {
		printf("Couldn't allocate memory!\n");
		return NULL;
	}
	new_map->data = load_data(filename);
	int chars = 0;
	int height = 0;
	int bytes = get_file_length(filename);
	char ch;
	char* data = new_map->data;
	while(chars < bytes) {
		ch = data[chars];
		if(ch == '\n' || ch == '\r')
			height++;
		chars++;
	}
	new_map->height = height;
	new_map->width = (chars/height)-1;
	return new_map;
}

// Ex. 10
void print_map(map* the_map) {
	printf("width: %d, height: %d\n", the_map->width, the_map->height);
	printf("%s", the_map->data);
	return;
}

// Ex. 11
char get_char_at(map* the_map, int y, int x) {
	int pos = position_at_map(the_map, y, x);
	if(pos == 0) {
		printf("Position outside of the map!\n");
		return BAD_CHAR;
	}
	char* data = the_map->data;
	char ch = data[pos];
	return ch;
}

// Ex. 12
void set_char_at(map* the_map, int y, int x, char ch) {
	int pos = position_at_map(the_map, y, x);
	if(pos == 0) {
		printf("Position outside of the map!\n");
		return;
	}
	char* data = the_map->data;
	data[pos] = ch;
	return;
}

// Ex. 13
int position_at_map(map* the_map, int y, int x) {
	int pos;
	if(x > the_map->width || x < 1 || y > the_map->height || y < 1) {
		pos = 0;
	}
	else {
		pos = (y-1)*((the_map->width)+1) + (x-1);
	}
	return pos;
}

// Ex. 14
void flood_fill(map* the_map) {
	char* data = the_map->data;
	int i = 0;
	char ch;
	while((ch = data[i]) != '\0') {
		if(ch == ' ') {
			data[i] = '0'+rand()%9+1;
		}
		i++;
	}
	return;
}

// Ex. 15
void rec_flood_fill(map* the_map, int y, int x) {
	char* data = the_map->data;
	int pos = position_at_map(the_map, y, x);
	if(pos == 0) {
		return;
	}
	char ch = data[pos];
	if(ch == ' ') {
		data[pos] = '0'+rand()%9+1;
		rec_flood_fill(the_map, y+1, x);
		rec_flood_fill(the_map, y-1, x);
		rec_flood_fill(the_map, y, x+1);
		rec_flood_fill(the_map, y, x-1);
	}
	return;
}

void free_map(map* the_map) {
	if(the_map == NULL) {
		puts("Nothing to free here!");
		return;
	}
	char* data = the_map->data;
	free(data);
	free(the_map);
	return;
}

int main(int argc, char* argv[]) {
	srand(time(NULL));
	if(argc > 1) {
		int flength = get_file_length(argv[1]);
		printf("File length is %d bytes.\n", flength);
		
		map* the_map = load_map(argv[1]);
		if(the_map != NULL) {
			print_map(the_map);
			char ch = get_char_at(the_map, 2, 7);
			printf("Character at (y=2, x=7): '%c'\n", ch);
			set_char_at(the_map, 2, 7, 'a');
			print_map(the_map);
			rec_flood_fill(the_map, 2, 6);
			print_map(the_map);
		}
		free_map(the_map);
	}
	else {
		printf("The map is a lie!\n");
	}
	return EXIT_SUCCESS;
}