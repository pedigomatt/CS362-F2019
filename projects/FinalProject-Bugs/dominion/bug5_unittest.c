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
    int seed = 1000;
    int numPlayers = 2;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
    int t;
	int player = 1;
    int score;
    initializeGame(numPlayers, k, seed, &G);
    
    //Create a copy for unit test #1.
    memcpy(&testG, &G, sizeof(struct gameState));

    //Test when discard count < deck
    testG.handCount[player] = 0;
    testG.discardCount[player] = 5;
    testG.deckCount[player] = 10;

    testG.discard[player][0] = 0; //curse : -1
    testG.discard[player][1] = 1; //estate : 1
    testG.discard[player][2] = 2; //duchy : 3
    testG.discard[player][3] = 3; //province : 6
    testG.discard[player][4] = 3; //province : 6

    testG.deck[player][0] = 1; //estate : 1
    testG.deck[player][1] = 1; //estate : 1
    testG.deck[player][2] = 1; //estate : 1
    testG.deck[player][3] = 1; //estate : 1
    testG.deck[player][4] = 1; //estate : 1
    testG.deck[player][5] = 1; //estate : 1
    testG.deck[player][6] = 1; //estate : 1
    testG.deck[player][7] = 1; //estate : 1
    testG.deck[player][8] = 1; //estate : 1
    testG.deck[player][9] = 1; //estate : 1

    score = scoreFor(player, &testG);
    printf("Score for DECK > DISCARD: %d, \n", score);
    t = testAssert(score, 25, 0);

    //print if assert was successfull.
    if(t==1){
        printf("\n >>>>> SUCCESS: Testing %s <<<<<\n\n", "BUG5 - DECK > DISCARD");
    }
	else{
        printf("\n >>>>> FAILURE: Testing %s <<<<<\n\n", "BUG5 - DECK > DISCARD");
    }

    //Create a copy for unit test #1.
    memcpy(&testG, &G, sizeof(struct gameState));

    //Test when discard count < deck
    testG.handCount[player] = 0;
    testG.discardCount[player] = 10;
    testG.deckCount[player] = 5;

    testG.deck[player][0] = 0; //curse : -1
    testG.deck[player][1] = 1; //estate : 1
    testG.deck[player][2] = 2; //duchy : 3
    testG.deck[player][3] = 3; //province : 6
    testG.deck[player][4] = 3; //province : 6

    testG.discard[player][0] = 1; //estate : 1
    testG.discard[player][1] = 1; //estate : 1
    testG.discard[player][2] = 1; //estate : 1
    testG.discard[player][3] = 1; //estate : 1
    testG.discard[player][4] = 1; //estate : 1
    testG.discard[player][5] = 1; //estate : 1
    testG.discard[player][6] = 1; //estate : 1
    testG.discard[player][7] = 1; //estate : 1
    testG.discard[player][8] = 1; //estate : 1
    testG.discard[player][9] = 1; //estate : 1

    score = scoreFor(player, &testG);
    printf("Score for DECK < DISCARD: %d, \n", score);

    t = testAssert(score, 25, 0);

    //print if assert was successfull.
    if(t==1){
        printf("\n >>>>> SUCCESS: Testing %s <<<<<\n\n", "BUG5 - DECK < DISCARD");
    }
	else{
        printf("\n >>>>> FAILURE: Testing %s <<<<<\n\n", "BUG5 - DECK < DISCARD");
    }


	return 0;
}