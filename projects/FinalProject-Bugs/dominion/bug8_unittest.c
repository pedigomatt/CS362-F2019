/********************************************************************
 * Author: George Lenz
 * Program: unittest8.c
 * Class: CS362 - Software Engineering II
 * Description: Unit test for play card adding coins properly
 *******************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int assert(int actual, int expected)
{
    if (actual == expected)
    {
        printf("PASSED:\n");
        return 0;
    }
    else
    {
        printf("FAILED:\n");
        return 1;
    }
}

int test()
{
int i;
//initialize game
struct gameState* state = newGame();

//get between 2 and MAX_PLAYERS player count
state->numPlayers = rand() % (MAX_PLAYERS - 1) + 2;

//set kingdom cards
int kingdomCards[10];
for (i = 0; i < 10; i++)
{
    //random action card (adventure = 7 to treasure_map = 26) 
    kingdomCards[i] = rand() %  20 + 7;
}

//set up supply counts
memset(state->supplyCount, 0, sizeof(state->supplyCount));

//randomly add victory supply count
for(i = 0; i < copper; i++)
{
    state->supplyCount[i] = rand() % 13;
}

//randmly add action cards
for(i = 0; i < 10; i++)
{
    state->supplyCount[kingdomCards[i]] = rand() % 12;
}

//randomly add treasure supply count
for(i = copper; i<= gold; i++);
{
    state->supplyCount[i] = rand() % 60;
}


//randomly select whose turn
int currentPlayer = state->whoseTurn = rand() % state->numPlayers;

//set actions to 0
state->numActions = 1;

//set coins to 0
state->coins = 0;

//set number of buys
state->numBuys = 1;

//random hand of players
for (i=0; i < state->numPlayers; i++)
{
   state->handCount[i] = rand() % MAX_HAND + 1;
}

//Create hand of players
for(i = 0; i < state->numPlayers; i++)
{
   int j;

    for (j=0; j < state->handCount[i]; j++)
    {
        state->hand[i][j] = rand() % 27;
    }
}

//random deck count
for(i = 0; i < state->numPlayers; i++)
{
    state->deckCount[i] = rand() % MAX_DECK + 1;
}
memset(state->deck[i], -1, sizeof(state->deck[state->whoseTurn]));

//create player decks
for(i = 0; i < state->numPlayers; i++)
{
   int j;
   for(j=0; j < state->deckCount[i]; j++)
   {
       state->deck[i][j] = rand() % 27;
   }
}

//random discard count
for(i = 0; i < state->numPlayers; i++)
{ 
    state->discardCount[i] = rand() % 500;
}
memset(state->discard[state->whoseTurn], -1, sizeof(state->discard[state->whoseTurn]));


//create player discard piles
for(i = 0; i < state->numPlayers; i++)
{
   int j;
   for(j=0; j < state->discardCount[i]; j++)
   {
       state->discard[i][j] = rand() % 27;
   }
}

//place a card that adds coins in hand (minion in this case)
int handPos = rand() % state->handCount[currentPlayer];
state->hand[currentPlayer][handPos] = minion;


//Check amount of treasures in hand
int handCoins = 0;
for(i = 0; i < state->handCount[currentPlayer]; i++)
{
    if (state->hand[currentPlayer][i] == copper)
    {
        handCoins += 1;
    }
    else if (state->hand[currentPlayer][i] == silver)
    {
        handCoins += 2;
    }
    else if (state->hand[currentPlayer][i] == gold)
    {
        handCoins += 3;
    }

}

playCard(handPos, 1, -1, -1, state);
assert(state->coins, handCoins + 2);

printf("Coins = Expected: %d Actual: %d\n", handCoins + 2, state->coins);

return 0;
}

int main()
{
    srand(time(0));
    
    printf("\n\n************************ TESTING BUG #8 ************************\n");

    test();
    
    return 0;
}
