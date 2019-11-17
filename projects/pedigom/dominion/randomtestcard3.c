/*
 * randomtestcard3.c
 * Tribute
 
 */

#include "dominion.h"
#include "dominion_helpers.h" 
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "tribute"

int randomg(int array[], int in_array, int out_array)
{
    int *r = (int *) malloc(sizeof(int) * out_array);
    int j;
    int r1;

    for (int i = 0; i < out_array; i++)
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
	int handcount[27] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
    int estate_opt[4] = {0, 1, 2, 3};
    int num_estates, deck_count, discard_count;
	int t = 1;
	int jk = 0;
	while(t){

		memcpy(&testG, &G, sizeof(struct gameState));
		testG.hand[1][0] = randomg(handcount, 27, 1);
        testG.hand[1][1] = randomg(handcount, 27, 1);
        testG.hand[1][2] = randomg(handcount, 27, 1);
        testG.hand[1][3] = randomg(handcount, 27, 1);
        testG.hand[1][4] = randomg(handcount, 27, 1);
        testG.hand[1][5] = randomg(handcount, 27, 1);

        testG.deckCount[1] = randomg(estate_opt, 4, 1);
        testG.discardCount[1] = randomg(estate_opt,4,1);
		printf("TRIBUTE 1: new_hand = %d,%d,%d,%d,%d,%d\n", testG.hand[1][0],testG.hand[1][1],testG.hand[1][2],testG.hand[1][3],testG.hand[1][4],testG.hand[1][5]);

        cardEffect(tribute, choice1, choice2, choice3, &testG, handpos, &bonus);

		if(jk > 100){
			t = 0;
		}
		jk++;

	}
	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);


	return 0;
}