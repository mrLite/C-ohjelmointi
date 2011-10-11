#ifndef __POKER_H__
#define __POKER_H__

typedef enum cardsuit {
	clubs = 1,
	diamonds = 2,
	hearts = 4,
	spades = 8
} cardsuit;

typedef struct card {
	int suit;
	int value;
} card;

char suit_input[4] = {'C', 'D', 'H', 'S'};
char suit_output[4][9] = {"Clubs", "Diamonds", "Hearts", "Spades"};
char value_input[13] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
char value_output[13][6] = {"2", "3", "4", "5", "6", "7", "8", "9", "Ten", "Jack", "Queen", "King", "Ace"};
char hand_value[10][16] = {"Bust", "One pair", "Two pairs", "Three of a kind", "Straight", "Flush", "Full house", "Four of a kind", "Straight flush", "Royal flush"};

#endif