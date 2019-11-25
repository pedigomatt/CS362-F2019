/*
 * unittest3.c
 * Tribute
 
 */

/*
 * Include the following lines in your makefile:
 *
 * unittest1: unittest3.c dominion.o rngs.o
 *      gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "tribute"

int main() {
    //Test 1  - left player reveals 2 action cards resulting in +2 action
    //          discardCount[nextPlayer] + deckCount[nextPlayer] >1

    //Test 2  - left player reveals 2 treasure cards resulting in +2 treasure
    //          discardCount[nextPlayer] + deckCount[nextPlayer] >1

    //Test 3  - left player reveals 2 victory cards resulting in +2 cards
    //          discardCount[nextPlayer] + deckCount[nextPlayer] >1

    //Test 4  - left player reveals 1 action and 1 treasure resulting in +2 action and +2 treasure
    //          discardCount[nextPlayer] + deckCount[nextPlayer] >1

    //Test 5  - left player reveals 1 action and 1 victory resulting in +2 action and +2 cards
    //          discardCount[nextPlayer] + deckCount[nextPlayer] >1

    //Test 6  - left player reveals 1 treasure and 1 victory resulting in +2 action and +2 cards
    //          discardCount[nextPlayer] + deckCount[nextPlayer] >1

    //Test 7  - discardCount[nextPlayer] + deckCount[nextPlayer] <=1

    //Test 8  - deckCount[nextPlayer] = 0
    //          discardCount[nextPlayer] + deckCount[nextPlayer] >1

}
