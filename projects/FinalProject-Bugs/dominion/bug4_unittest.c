/*
 * bug4_unittest.c
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
	
    initializeGame(numPlayers, k, seed, &G);
    
    //Create a copy for unit test #1.
    memcpy(&testG, &G, sizeof(struct gameState));

    //set the last 3 positions of the supplyCount array to 0.
    testG.supplyCount[25] = 0;
    testG.supplyCount[24] = 0;
    testG.supplyCount[23] = 0;

    //print out the supplyCount values.
    printf(">>>>> Bug 4 Tests Supply Count <<<<<\n");
    for(int tt = 0; tt<26; tt++){
        printf("%d, ", testG.supplyCount[tt]);
    }
    //check bug 4 -  run isGameOver function.
    int value = isGameOver(&testG);

    //run assert to see if correct value is returned.
    t = testAssert(value, 1, 0);

    //print if assert was successfull.
    if(t==1){
        printf("\n >>>>> SUCCESS: Testing %s <<<<<\n\n", "BUG4 - POSITION 23, 24, 25 set to 0");
    }
	else{
        printf("\n >>>>> FAILURE: Testing %s <<<<<\n\n", "BUG4 - POSITION 23, 24, 25 set to 0");
    }

    //Create a copy for unit test #1.
    memcpy(&testG, &G, sizeof(struct gameState));

    //set the last 3+1 positions of the supplyCount array to 0.
    testG.supplyCount[24] = 0;
    testG.supplyCount[23] = 0;
    testG.supplyCount[22] = 0;

    //print out the supplyCount values.
    printf(">>>>> Bug 4 (last 3+1) Tests Supply Count <<<<<\n");
    for(int tt = 0; tt<26; tt++){
        printf("%d, ", testG.supplyCount[tt]);
    }
    printf("\n");
    //check bug 4 -  run isGameOver function.
    value = isGameOver(&testG);

    //run assert to see if correct value is returned.
    t = testAssert(value, 1, 0);

    //print if assert was successfull.
    if(t==1){
        printf("\n >>>>> SUCCESS: Testing %s <<<<<\n\n", "BUG4 - POSITION 22, 23, 24 set to 0");
    }
	else{
        printf("\n >>>>> FAILURE: Testing %s <<<<<\n\n", "BUG4 - POSITION 22, 23, 24 set to 0");
    }

	return 0;
}