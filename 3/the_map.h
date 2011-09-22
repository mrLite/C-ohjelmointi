#ifndef __THE_MAP_H__
#define __THE_MAP_H__

typedef struct map {
	int width;
	int height;
	char* data;
} map;

int is_line_break(char ch);
int get_file_length(char* filename);
char* load_data(char* filename);
map *load_map(char* filename);
void print_map(map* the_map);
char get_char_at(map* the_map, int y, int x);
void set_char_at(map* the_map, int y, int x, char ch);
int position_at_map(map* the_map, int y, int x);
void flood_fill(map* the_map);
void rec_flood_fill(map* the_map, int y, int x);

#endif