/*
 * bug7_unittest.c
 * 
 
 */

#include "dominion.h"
#include "dominion_helpers.h" 
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int testAssert(int result, int expected, int v)
{
    printf("RESULT: %d, EXPECTED: %d\n", result, expected);
    if (v == 0){ //expect results to be equal;
        if (result == expected){
            return 1;
        }
        else {
            return -1;
        }
    }

    else if (v == 1){ //result >= expected
        if (result >= expected){
            return 1;
        }
        else {
            return -1;
        }
    }

    else if (v == -1){ //result <= expected
        if (result <= expected){
            return 1;
        }
        else {
            return -1;
        }
    }
}


int main() {

    int i;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	
    memcpy(&testG, &G, sizeof(struct gameState));

    int player = 0;

    testG.deckCount[player+1] = 2;
    testG.deck[player+1][0] = gold;
    testG.deck[player+1][1] = minion;

    int val = cardEffect(tribute, choice1, choice2, choice3, &testG, handpos, &bonus);

    printf("COINS ");
    int coins = testAssert(testG.coins, G.coins+2,0);
    printf("ACTION ");
    int action = testAssert(testG.numActions, G.numActions+2,0);
    printf("COUNT ");
    int handCount = testAssert(testG.handCount[player], G.handCount[player],0);
    
    if(coins==1 && action == 1 && handCount == 1){
        printf("\n >>>>> SUCCESS: Testing %s <<<<<\n\n", "BUG7 - TRIBUTECARD LOOP WORKS");
    }
	else{
        printf("\n >>>>> FAILURE: Testing %s <<<<<\n\n", "BUG7 - TRIBUTE CARD LOOP DOESN'T WORK");
    }
	
	return 0;
}