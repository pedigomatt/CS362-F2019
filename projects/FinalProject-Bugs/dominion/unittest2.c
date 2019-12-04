#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"


void checkEstate( int one , int two );
void checkGold(int one, int two);

int main() {
	int preEstate, postEstate, preGold, postGold;

	int seed = 4;
	int k[10] = { adventurer, council_room, feast, gardens, mine
			   , remodel, smithy, village, baron, great_hall };
	
	struct gameState G, G2;
	
	printf("----------------------------------------------------------------------------\n");
	printf("Begin Testing Mine Case \n");

	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	initializeGame(2, k, seed, &G); // initialize a new game

	G.hand[0][0] = copper;
	G.hand[0][1] = mine;
	G.hand[0][3] = estate;

	preEstate = 0;

	int i;
	for (i = 0; i < G.handCount[0]; i++)
	{
		if (G.hand[0][i] == estate)
		{
			preEstate++;
		}
	}

	//pass in the position of the choice1 card because that is what is being used in the function. 
	cardEffect(mine, 0, estate, 0, &G, 1, 0);

	postEstate = 0;

	for (i = 0; i < G.handCount[0]; i++)
	{
		if (G.hand[0][i] == estate)
		{
			postEstate++;
		}
	}

	printf("Bug#2 < +3 test ");

	checkEstate(preEstate, postEstate);

	//printf("pre-%d    post-%d \n", preEstate, postEstate);

	memset(&G2, 23, sizeof(struct gameState));   // clear the game state
	initializeGame(2, k, seed, &G2); // initialize a new game

	G2.hand[0][0] = copper;
	G2.hand[0][1] = mine;
	G2.hand[0][3] = estate;

	preGold = 0;
	
	int j;
	for (j = 0; j < G2.handCount[0]; j++)
	{
		if (G2.hand[0][j] == gold)
		{
			preGold++;
		}
	}

	//pass in the position of the choice1 card because that is what is being used in the function. 
	cardEffect(mine, 0, gold, 0, &G2, 1, 0);

	postGold = 0;

	for (j = 0; j < G2.handCount[0]; j++)
	{
		if (G2.hand[0][j] == gold)
		{
			postGold++;
		}
	}

	printf("Bug#2 > Allowed gain card test ");

	checkGold(preGold, postGold);
		
	//printf("preGold-%d    postGold-%d \n", preGold, postGold);

	return 0;
}

void checkEstate(int one , int two)
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

void checkGold(int one, int two)
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