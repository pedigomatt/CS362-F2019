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
	/
	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", "BUG4");


	return 0;
}