#ifndef __AUTOMATA_H__
#define __AUTOMATA_H__

typedef struct transition {
	int symbol;
	int state;
	struct transition* next;
} transition;

/* Type is 0, if the state is ordinary, 1, if the state is initial, and -1, if the state is final */
typedef struct state {
	int state;
	int type;
	struct transition* transitions;
} state;

typedef struct s_table_element {
	int int_value;
	char symbol[30];
} s_table_element;

typedef struct automaton {
	int initial_state;
	int states;
	int final_state_c;
	int symbol_c;
	state* state_table;
	s_table_element* symbol_table;
	int* final_states;
} automaton;

state new_state(int state, int type, transition* transitions);
void add_transition_node(transition** TL, transition* T);
int add_transition(state* s, int symbol, int state);
s_table_element* read_symbols(int symbol_c, FILE* fptr);
int* read_final_states(FILE* fptr, int* count);
int read_transition(state* state_table, FILE* fptr);
int is_final_state(int* final_states, int final_state_c, int state);
automaton* read_automaton(FILE* fptr);

#endif