#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"


void checkGarden( int one , int two );
void checkAdventurer(int one, int two);

int main() {
	int preGarden, postGarden, preAdvent, postAdvent;

	int seed = 4;
	int k[10] = { adventurer, council_room, feast, gardens, mine
			   , remodel, smithy, village, baron, great_hall };
	
	struct gameState G, G2;
	
	printf("----------------------------------------------------------------------------\n");
	printf("Begin Testing Mine Case \n");

	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	initializeGame(2, k, seed, &G); // initialize a new game

	G.hand[0][0] = copper;
	G.hand[0][1] = remodel;
	G.hand[0][2] = silver;
	G.hand[0][3] = estate;

	preGarden = 0;

	int i;
	for (i = 0; i < G.discardCount[0]; i++)
	{
		if (G.discard[0][i] == gardens)
		{
			preGarden++;
		}
	}

	//pass in the position of the choice1 card because that is what is being used in the function. 
	cardEffect(remodel, 2, gardens, 0, &G, 1, 0);
	
	postGarden = 0;

	for (i = 0; i < G.discardCount[0]; i++)
	{
		if (G.discard[0][i] == gardens)
		{
			postGarden++;
		}
	}

	printf("Bug#3 < +2 test ");

	checkGarden(preGarden, postGarden);

	memset(&G2, 23, sizeof(struct gameState));   // clear the game state
	initializeGame(2, k, seed, &G2); // initialize a new game

	G2.hand[0][0] = copper;
	G2.hand[0][1] = remodel;
	G2.hand[0][2] = silver;
	G2.hand[0][3] = estate;

	preAdvent = 0;

	int j;
	for (j = 0; j < G2.discardCount[0]; j++)
	{
		if (G2.discard[0][i] == adventurer)
		{
			preAdvent++;
		}
	}

	//pass in the position of the choice1 card because that is what is being used in the function. 
	cardEffect(remodel, 2, adventurer, 0, &G2, 1, 0);

	postAdvent = 0;

	for (j = 0; j < G2.discardCount[0]; j++)
	{
		if (G2.discard[0][i] == adventurer)
		{
			postAdvent++;
		}
	}

	printf("Bug#3 > Allowed gain card test ");

	checkAdventurer(preAdvent, postAdvent);

	return 0;
}

void checkGarden(int one , int two)
{
	if (one < two )
	{
		printf("Passed \n");
	}
	else if(one > two)
	{
		printf("Failed \n");
	}
	else
	{
		printf("Failed \n");
	}

	return;
}

void checkAdventurer(int one, int two)
{
	if (one == two)
	{
		printf("Passed \n");
	}
	else
	{
		printf("Failed \n");
	}

	return;
}