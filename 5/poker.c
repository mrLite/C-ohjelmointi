#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "poker.h"

// Input is a string of two characters, where the spot value is the first and the suit is the second, e.g. 'TS'
// Function extracts these chars, and checks to see if it can find the characters at the suit and value input arrays, introduced at poker.h
// Output is a struct card, which has two int fields, suit and value, which both are indices of corresponding arrays
card match_card(char* card_string) {
	char suit, value;
	int suit_match = -1, value_match = -1;
	card ret;
	
	sscanf(card_string, "%c%c", &value, &suit);
	
	for(int i = 0; i < 4; ++i) {
		if(suit_input[i] == suit) {
			suit_match = i;
			break;
		}
	}
	for(int i = 0; i < 13; ++i) {
		if(value_input[i] == value) {
			value_match = i;
			break;
		}
	}
	
	if((suit_match >= 0) && (value_match >= 0)) {
		ret.suit = suit_match;
		ret.value = value_match;
	}
	else {
		printf("You failed at giving me right values! Shame on you!\n");
		exit(0);
	}
	
	return ret;
}

// Ex. 2
card* get_hand(void) {
	card* hand = malloc(sizeof(card)*5);
	assert(hand != NULL);
	char cards[5][3];
	
	puts("Please give me five cards, one at a time, separated by carriage return. E.g. 'TS' or '3H'");
	for(int i = 0; i < 5; ++i) {
		if((fgets(cards[i], 10, stdin)) == NULL) {
			puts("Incomplete data!");
			return NULL;
		}
		hand[i] = match_card(cards[i]);
	}
	return hand;
}

// Ex. 3
// Simple insertion sort
void sort_hand(card* hand) {
	card current;
	int j;
	for(int i = 1; i < 5; ++i) {
		current = hand[i];
		j = i-1;
		while((j >= 0) && (hand[j].value > current.value)) {
			hand[j+1] = hand[j];
			--j;
		}
		hand[j+1] = current;
	}
	return;
}

// Ex. 4
void print_hand(card* hand) {
	for(int i = 0; i < 5; ++i) {
		printf("%s of %s\n", value_output[hand[i].value], suit_output[hand[i].suit]);
	}
	return;
}

// <Ex. 5..6>

int is_four_of_a_kind(card* hand) {
	if((hand[1].value == hand[2].value) && (hand[2].value == hand[3].value) && ((hand[0].value == hand[1].value) || (hand[4].value == hand[1].value))) return 1;
	return 0;
}

int is_full_house(card* hand) {
	if((hand[0].value == hand[1].value) && (hand[3].value == hand[4].value) && ((hand[2].value == hand[3].value) || (hand[1].value == hand[2].value))) return 1;
	return 0;
}

// Returns 1 if the cards form a straight, otherwise 0.
// Works only with a sorted hand!
int is_straight(card* hand) {
	int x = hand[0].value;
	for(int i = 1; i < 5; ++i) {
		x = hand[i].value - x;
		if(x != 1) return 0;
		x = hand[i].value;
	}
	return 1;
}

// Returns 1 if all the cards in hand are of the same suit, 0 otherwise.
int is_same_suit(card* hand) {
	int x = hand[0].suit;
	for(int i = 1; i < 5; ++i) {
		x ^= hand[i].suit;
		if(x > 0) return 0;
		x = hand[i].suit;
	}
	return 1;
}

int is_three_of_a_kind(card* hand) {
	int mid_value = hand[2].value;
	if((hand[0].value == mid_value) && (hand[1].value == mid_value)) return 1;
	if((hand[1].value == mid_value) && (hand[3].value == mid_value)) return 1;
	if((hand[3].value == mid_value) && (hand[4].value == mid_value)) return 1;
	return 0;
}

int is_two_pairs(card* hand) {
	if(hand[0].value == hand[1].value) {
		if((hand[2].value == hand[3].value) || (hand[3].value == hand[4].value)) return 1;
	}
	if((hand[1].value == hand[2].value) && (hand[3].value == hand[4].value)) return 1;
	return 0;
}

int has_pair(card* hand) {
	int x = hand[0].value;
	for(int i = 1; i < 5; ++i) {
		if(x == hand[i].value) return 1;
		x = hand[i].value;
	}
	return 0;
}

// </Ex. 5..6>

// Ex. 7
// Evaluates hand
int evaluate_hand(card* hand) {
	sort_hand(hand);
	int straight_flag = is_straight(hand);
	if(is_same_suit(hand)) {
		if((hand[0].value == 8) && (straight_flag)) return 9;	// If the 1st card is Ten and the cards form a straight, return 9 (Royal flush)
		if(straight_flag) return 8;								// If the cards form a straight, return 8 (Straight flush)
		else return 5;											// Otherwise, return 5 (Flush)
	}
	else if(is_four_of_a_kind(hand)) return 7;
	else if(is_full_house(hand)) return 6;
	else if(straight_flag) return 4;
	else if(is_three_of_a_kind(hand)) return 3;
	else if(is_two_pairs(hand)) return 2;
	else if(has_pair(hand)) return 1;
	return 0;													// If none of these evaluations holds, return 0 (Bust)
}

// Ex. 8
int main(void) {
	puts("Enter hand number 1");
	card* hand1 = get_hand();
	int eval1 = evaluate_hand(hand1);
	print_hand(hand1);
	printf("%s\n\n", hand_value[eval1]);
	
	puts("Enter hand number 2");
	card* hand2 = get_hand();
	int eval2 = evaluate_hand(hand2);
	print_hand(hand2);
	printf("%s\n\n", hand_value[eval2]);
	
	if(eval1 > eval2) puts("Hand number 1 wins");
	else if(eval2 > eval1) puts("Hand number 2 wins");
	else puts("It's a tie");
	
	free(hand1);
	free(hand2);
	return(EXIT_SUCCESS);
}