/*
 * bug6_unittest.c
 * 
 
 */

#include "dominion.h"
#include "dominion_helpers.h" 
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "feast"


int testAssert(int result, int expected, int v)
{
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
    int player = 0;
	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

    memcpy(&testG, &G, sizeof(struct gameState));
    
    choice1 = 6; //Gold with cost of 6.
    testG.handCount[player] = 5;
    testG.hand[player][0] = copper;
    testG.hand[player][1] = 11;
    testG.hand[player][2] = 11;
    testG.hand[player][3] = 11;
    testG.hand[player][4] = 11;

    int val = cardEffect(feast, choice1, choice2, choice3, &testG, handpos, &bonus);


    int discard = testAssert(testG.discardCount[player], G.discardCount[player],0);
    //print if assert was successfull.
    if(discard==1){
        printf("\n >>>>> SUCCESS: Testing %s <<<<<\n\n", "BUG6 - DISCARD count doesn't increase");
    }
	else{
        printf("\n >>>>> FAILURE: Testing %s <<<<<\n\n", "BUG6 - DISCARD count INCREASES");
    }

    int supply = testAssert(testG.supplyCount[6], G.supplyCount[6],0);
    if(supply==1){
        printf("\n >>>>> SUCCESS: Testing %s <<<<<\n\n", "BUG6 - SUPPLY count doesn't increase");
    }
	else{
        printf("\n >>>>> FAILURE: Testing %s <<<<<\n\n", "BUG6 - SUPPLY count INCREASES");
    }

	return 0;
}