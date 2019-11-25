/*
 * unittest1.c
 * Minion
 
 */

/*
 * Include the following lines in your makefile:
 *
 * unittest1: unittest1.c dominion.o rngs.o
 *      gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h" 
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "minion"

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
	//Test 1  - choice 1 - player decides to add 2 coins to treasury
	//--------Assert: coins+2
	//--------Assert: discardCard
	//--------Assert: currentPlayer does not discard cards and get new cards
	printf("TEST 1: choice1 = 1 = +2 treasury\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	choice1 = 1;
	cardEffect(minion, choice1, choice2, choice3, &testG, handpos, &bonus);
	numActions = 1;
	//--------Assert: numActions+1
	printf("Actions = %d, expected = %d\n", testG.numActions, G.numActions + numActions);
	//printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
	//printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
	//assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);
	//assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards);
	//assert(testG.coins == G.coins + xtraCoins);


	//Test 2  - choice 2 - currentPlayer discards hand and draws 4 new cards.
	//each other player with at least 5 cards in hand, discards their hand
	//and draws 4 cards.	
	printf("TEST 2: choice1 = 0, choice2 = 1 and other player has 5 cards, discards and draws 4.\n");
	

	memcpy(&testG, &G, sizeof(struct gameState));
	printf("HandCount = %d\n", testG.handCount[thisPlayer]);
	choice1 = 0;
	choice2 = 1;
	cardEffect(minion, choice1, choice2, choice3, &testG, handpos, &bonus);

	//test when other player has 5 cards
	//--------Setup: choice 1 = 0
	//--------Setup: choice 2 = 1
	//--------Setup: otherPlayer cards = 5
	//--------Assert: numActions+1
	//--------Assert: coins does not change
	//--------Assert: discardCard
	//--------Assert: currentPlayer discard hand - discardPile + 4
	//--------Assert: currentPlayer draws 4 cards - +4 in hand, -4 in deck
	//--------Assert: other player discards hand - discardPile+5
	//--------Assert: other player draws 4 cards - +4 in hand, -4 in deck

	//Test 3  - choice 2 - currentPlayer discards hand and draws 4 new cards.
	//each other player with at least 5 cards in hand, discards their hand
	//and draws 4 cards.
	printf("TEST 3: choice1 = 0, choice2 = 1 and other player has 4 cards, discards and draws 4.\n");
	

	memcpy(&testG, &G, sizeof(struct gameState));
	testG.handCount[1] = 4;
	printf("HandCount = %d\n", testG.handCount[1]);
	choice1 = 0;
	choice2 = 1;
	cardEffect(minion, choice1, choice2, choice3, &testG, handpos, &bonus);
	//test when other player < 5 cards
	//--------Setup: choice 1 = 0
	//--------Setup: choice 2 = 1
	//--------Setup: otherPlayer cards = 4
	//--------Assert: numActions+1
	//--------Assert: coins does not change
	//--------Assert: discardCard
	//--------Assert: currentPlayer discard hand - discardPile + 4
	//--------Assert: currentPlayer draws 4 cards - +4 in hand, -4 in deck
	//--------Assert: other player does not discard hand.
	//--------Assert: other player does not draw 4 cards.

    

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);


	return 0;
}
