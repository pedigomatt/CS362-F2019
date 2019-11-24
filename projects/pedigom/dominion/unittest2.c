/*
 * unittest2.c
 * Ambassador
 
 */

/*
 * Include the following lines in your makefile:
 *
 * unittest2: unittest2.c dominion.o rngs.o
 *      gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "ambassador"

int main() {
    int numActions = 0;
    int discarded = 1;
    int xtraCoins = 0;
    int shuffledCards = 0;

    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
    //Test 1  - choice 2 == -1 No matches of the card shown to cards in hand
    printf("TEST 1: choice 2 == -1 No matches of the card shown to cards in hand\n");
    memcpy(&testG, &G, sizeof(struct gameState));
	choice2 = -1;
	int cha = cardEffect(ambassador, choice1, choice2, choice3, &testG, handpos, &bonus);
    printf("Return = %d\n", cha);
    //Test 2  - choice 1 == handPos No matches of the card shown to cards in hand
    printf("TEST 2: choice 1 == 1 No matches of the card shown to cards in hand\n");
    choice1 = 1;
    choice2 = 0;
    handpos = 1;
    memcpy(&testG, &G, sizeof(struct gameState));
	cha = cardEffect(ambassador, choice1, choice2, choice3, &testG, handpos, &bonus);
    printf("Return = %d\n", cha);
    //Test 3  - j < choice 2 (j is number of matches)
    printf("TEST 3: choice 1 == 1 No matches of the card shown to cards in hand\n");
    memcpy(&testG, &G, sizeof(struct gameState));
    choice1 = 5;
    choice2 = 1;
    handpos = 6;
    testG.hand[0][0] = 0;
    testG.hand[0][1] = 1;
    testG.hand[0][2] = 2;
    testG.hand[0][3] = 1;
	cha = cardEffect(ambassador, choice1, choice2, choice3, &testG, handpos, &bonus);
    printf("Return T3= %d\n", cha);
    //Test 4  - j > choice 2 (j is number of matches)

	


}
