#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"


void checkOne( int one , int two );

int main() {
	int prePlayedCards, postPlayedCards;

	int seed = 4;
	int k[10] = { adventurer, council_room, feast, gardens, mine
			   , remodel, smithy, village, baron, great_hall };
	
	struct gameState G;
	
	printf("----------------------------------------------------------------------------\n");
	printf("Begin Testing Mine Case \n");

	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	initializeGame(2, k, seed, &G); // initialize a new game

	G.hand[0][0] = copper;
	G.hand[0][1] = mine;

	prePlayedCards = G.playedCardCount;

	cardEffect(mine, copper, silver, 0, &G, 1, 0);
	
	postPlayedCards = G.playedCardCount;

	printf("Bug#1 discardCard trash flag test ");

	checkOne(prePlayedCards + 1, postPlayedCards);

	//printf("pre-%d    post-%d \n", prePlayedCards, postPlayedCards);

	return 0;
}

void checkOne(int one , int two)
{
	if (one == two )
	{
		printf("Passed \n");
	}
	else
	{
		printf("Failed \n");
	}

	return;
}
