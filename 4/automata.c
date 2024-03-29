#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "automata.h"
#define MAX_LEN 100

state new_state(int state, int type, transition* transitions) {
	struct state ret;
	ret.state = state;
	ret.type = type;
	ret.transitions = transitions;
	return ret;
}

// Ex. 11
// Adds transition T as the first element of the transition list TL.
void add_transition_node(transition** TL, transition* T) {
	T->next = *TL;
	*TL = T;
	return;
}

// Ex. 12
// Constructs a new transition and adds it as the first element of the transition list of state s.
int add_transition(state* s, int symbol, int state) {
	transition* T = malloc(sizeof(transition));
	if(T == NULL) {
		printf("Couldn't allocate transition data for symbol: %d, state: %d\n", symbol, state);
		return 0;
	}
	T->symbol = symbol;
	T->state = state;
	add_transition_node(&(s->transitions), T);
	return 1;
}

// Reads a line from the file pointed by fptr and extracts the symbol number and corresponding char representation.
s_table_element read_symbol(FILE* fptr) {
	char line[MAX_LEN+1];
	int val;
	char sym[30];
	struct s_table_element s;
	
	fgets(line, (int)MAX_LEN, fptr);
	sscanf(line, "%d %30s", &val, sym);
	s.int_value = val;
	strcpy(s.symbol, sym);
	return s;
}

// Ex. 13
// Reads symbol_c number of lines from a file pointed by fptr and constructs the symbol table.
s_table_element* read_symbols(int symbol_c, FILE* fptr) {
	s_table_element* symbol_table;
	
	if((symbol_table = malloc(sizeof(s_table_element)*symbol_c)) == NULL) {
		puts("Couldn't allocate symbol table!");
		return NULL;
	}
		
	for(int i = 0; i < symbol_c; ++i) {
		symbol_table[i] = read_symbol(fptr);
	}
	return symbol_table;
}

// Reads a line of the file pointed by fptr and constructs the final states table
// Line should be of the format 'c n n n', where c is the number of final states, and n is a final state number.
int* read_final_states(FILE* fptr, int* count) {
	char str[MAX_LEN+1];
	char delim[] = " ";
	char* result = NULL;
	
	fgets(str, (int)MAX_LEN, fptr);
	result = strtok(str, delim);
	sscanf(result, "%d", count);
	
	int* final_states = malloc(sizeof(int)*(*count));
	if(final_states == NULL)
		return NULL;
	
	for(int i = 0; i < *count; ++i) {
		result = strtok(NULL, delim);
		sscanf(result, "%d", &final_states[i]);
	}
	return final_states;
}

// Reads a line of the file pointed by fptr, and adds the transition to the appropriate state.
// Line should be of the format 'a b c' where a denotes the state to which the transition belongs to, b is the symbol which transitions to the next state c.
int read_transition(state* state_table, FILE* fptr) {
	char line[MAX_LEN+1];
	int cur_state, symbol, next_state;
	
	if((fgets(line, (int)MAX_LEN, fptr)) == NULL)
		return 0;
	sscanf(line, "%d %d %d", &cur_state, &symbol, &next_state);
	state* current = &state_table[cur_state-1];
	if((add_transition(current, symbol, next_state)) == 0)
		return 0;
	return 1;
}

// Returns 1 if the third argument is a final state, otherwise 0.
int is_final_state(int* final_states, int final_state_c, int state) {
	for(int i = 0; i < final_state_c; ++i) {
		if(final_states[i] == state)
			return 1;
	}
	return 0;
}

void print_symbol_table(automaton* A) {
	s_table_element* symbol_table = A->symbol_table;
	int table_size = A->symbol_c;
	printf("Symbol table size: %d\n", table_size);
	for(int i = 0; i < table_size; ++i) {
		printf("%d\t%s\n", symbol_table[i].int_value, symbol_table[i].symbol);
	}
	return;
}

void print_transitions(state* S) {
	transition* curr = S->transitions;
	while(curr != NULL) {
		printf("Symbol: %d\tState: %d\n", curr->symbol, curr->state);
		curr = curr->next;
	}
	return;
}

void free_tl(state* S) {
	transition* tl = S->transitions;
	if(tl == NULL)
		return;
	transition* curr = tl->next;
	while(tl != NULL) {
		free(tl);
		tl = curr;
		if(curr != NULL)
			curr = curr->next;
	}
}

void free_automaton(automaton* A) {
	int* final_states = A->final_states;
	s_table_element* symbol_table = A->symbol_table;
	state* state_table = A->state_table;
	int state_c = A->states;
	
	free(final_states);
	free(symbol_table);
	for(int i = 0; i < state_c; ++i) {
		free_tl(&state_table[i]);
	}
	free(state_table);
	return;
}

// Ex. 14
automaton* read_automaton(FILE* fptr) {	
	int state_c;
	int symbol_c;
	int initial_state;
	
	int final_state_c;
	int* final_states;
	
	s_table_element* symbol_table;
	state* state_table;
	
	char line[MAX_LEN+1];
	
	if(fseek(fptr, 0, SEEK_SET)) {
		puts("Couldn't seek the start of the file!");
		return NULL;
	}
	
	// Reading the number of states, number of symbols, and initial state
	fgets(line, (int)MAX_LEN, fptr);
	sscanf(line, "%d %d %d", &state_c, &symbol_c, &initial_state);
	
	// Constructing the table of final states
	final_states = read_final_states(fptr, &final_state_c);
	
	// Constructing the symbol table
	symbol_table = read_symbols(symbol_c, fptr);
	
	// Constructing the state table
	state_table = malloc(sizeof(state)*state_c);
	if(state_table == NULL) {
		puts("Couldn't allocate the state table");
		return NULL;
	}
	int type;
	for(int i = 0; i < state_c; ++i) {
		if((i+1) == initial_state)
			type = 1;
		else if(is_final_state(final_states, final_state_c, i+1))
			type = -1;
		else
			type = 0;
		state_table[i] = new_state(i+1, type, NULL);
	}
	while(read_transition(state_table, fptr));
	
	automaton* ret = malloc(sizeof(automaton));
	if(ret == NULL)
		return NULL;
	ret->initial_state = initial_state;
	ret->states = state_c;
	ret->symbol_c = symbol_c;
	ret->state_table = state_table;
	ret->symbol_table = symbol_table;
	ret->final_states = final_states;
	ret->final_state_c = final_state_c;
	
	return ret;
}

int main(void) {
	FILE* automaton_p;
	if((automaton_p = fopen("automaton.txt", "r")) == NULL)
		return EXIT_FAILURE;
	
	automaton* test = read_automaton(automaton_p);
	printf("Initial state: %d\n", test->initial_state);
	printf("Number of states: %d\n", test->states);
	printf("Number of final states: %d\n", test->final_state_c);
	printf("Final state: %d\n", test->final_states[0]);
	printf("Transitions of the initial state:\n");
	state initial = test->state_table[0];
	print_transitions(&initial);
	print_symbol_table(test);
	free_automaton(test);
	free(test);
}