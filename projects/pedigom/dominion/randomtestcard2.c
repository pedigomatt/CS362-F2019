/*
 * randomtestcard2.c
 * Baron
 
 */

#include "dominion.h"
#include "dominion_helpers.h" 
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "baron"

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
	int handcount[10] = {4,4,4,4,4,4,4,4,4,1};
    int estate_opt[4] = {0, 1, 2, 3};
    int num_estates;
	int t = 1;
	int jk = 0;
	while(t){
		choice1 = randomg(c1_options, 2, 1);
		//new_hand = randomg(handcount, 10, 5);
		num_estates = randomg(estate_opt, 4, 1);
		memcpy(&testG, &G, sizeof(struct gameState));
		testG.hand[0][0] = randomg(handcount, 10, 1);
        testG.hand[0][1] = randomg(handcount, 10, 1);
        testG.hand[0][2] = randomg(handcount, 10, 1);
        testG.hand[0][3] = randomg(handcount, 10, 1);
        testG.hand[0][4] = randomg(handcount, 10, 1);
        testG.hand[0][5] = randomg(handcount, 10, 1);
        testG.hand[0][6] = randomg(handcount, 10, 1);

        testG.supplyCount[estate] = num_estates;
		cardEffect(baron, choice1, choice2, choice3, &testG, handpos, &bonus);
		printf("BARON 1: choice1 = %d, new_hand = %d,%d,%d,%d,%d,%d, num_estates = %d\n", choice1, testG.hand[0][0],testG.hand[0][1],testG.hand[0][2],testG.hand[0][3],testG.hand[0][4],testG.hand[0][5], num_estates);

		if(jk > 100){
			t = 0;
		}
		jk++;

	}
	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);


	return 0;
}
