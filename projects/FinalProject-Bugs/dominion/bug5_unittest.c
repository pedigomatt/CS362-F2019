/*
 * bug5_unittest.c
 * 
 
 */

#include "dominion.h"
#include "dominion_helpers.h" 
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int *randomg(int array[], int in_array, int out_array)
{
    int *r = (int *) malloc(sizeof(int) * out_array);
    int j;
    int r1;

    for (int i = 0; i < in_array; i++)
    {
      r1 = rand()%in_array;
      r[i] = array[r1];
      
    }
	if(out_array ==1){
		return r[0];
	}
    else{
		return r;
	}
}


int main() {
	srand(time(NULL));

    int i;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	// loop through random inputs and test code coverage.
	//choice1 - [0,1]
	int c1_options[2] = {0,1};	
	//choice2 - [0,1]
	int c2_options[2] = {0,1};	
	//currentPlayer = 0
	//nextPlayer = 1
	//adjust nextPlayer hand between 4 and 5 [4,5]	
	int handcount[2] = {4,5};
	int nextPlayer_hand_count;
	int t = 1;
	int jk = 0;
	while(t){
		choice1 = randomg(c1_options, 2, 1);
		choice2 = randomg(c2_options, 2, 1);
		nextPlayer_hand_count = randomg(handcount, 2, 1);
		
		memcpy(&testG, &G, sizeof(struct gameState));
		testG.handCount[1] = nextPlayer_hand_count;
		cardEffect(minion, choice1, choice2, choice3, &testG, handpos, &bonus);
		printf("TEST 1: choice1 = %d, choice2 = %d, next_player_cards = %d\n", choice1, choice2, nextPlayer_hand_count);

		if(jk > 100){
			t = 0;
		}
		jk++;

	}
	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", "BUG5");


	return 0;
}