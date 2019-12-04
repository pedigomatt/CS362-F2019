/********************************************************************
 * Author: George Lenz
 * Program: unittest9.c
 * Class: CS362 - Software Engineering II
 * Description: Test that tribute card doesn't add extra actions
 * on duplicates
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
        printf("Passed:\n");
        return 0;
    }
    else
    {
        printf("Failed:\n");
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

//set embargo tokens to 0, (irrelevant to baron tests)
memset(state->embargoTokens, 0, sizeof(state->embargoTokens));

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
state->whoseTurn = rand() % state->numPlayers;

//set actions to 1
state->numActions = 0;

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
    state->deckCount[i] = 2 + (int) (MAX_DECK * (rand() / (RAND_MAX + 1.0)));
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

//place tribute in current players hand
int tributePos = rand() % state->handCount[state->whoseTurn]; 
state->hand[state->whoseTurn][tributePos] = tribute;

//function parameters and pre-function variables
int preActions = state->numActions;
int nextPlayer = state->whoseTurn + 1;
if(nextPlayer == state->numPlayers)
{
    nextPlayer = 0;
}
//Set next player to have two of the same card at top of deck
int firstCard = state->deck[nextPlayer][state->deckCount[nextPlayer] - 1];
state->deck[nextPlayer][state->deckCount[nextPlayer] - 2] = firstCard;
int cardType = 0;

//get first cards type
if (firstCard > 6 && firstCard != gardens && firstCard != great_hall)
{
    cardType = 3;
}
else if (firstCard > 3 || firstCard == gardens || firstCard == great_hall)
{
    cardType = 2;
} 
else if (firstCard > 0)
{
    cardType = 1;
}

int bonus;
//run tribtue effct
cardEffect(tribute, -1, -1, -1, state, tributePos, &bonus);

//Check reward if duplicates

if (cardType == 3)
{
    assert(state->numActions, preActions + 2);
    printf("Actions = Expected:%d Actual:%d\n", preActions + 2, state->numActions);
}

else
{
    assert(state->numActions, preActions);
    printf("Actions = Expected:%d Actual:%d\n", preActions, state->numActions);

}
return 0;
}

int main()
{
    srand(time(0));
    
    printf("\n\n************************ TESTING Bug #9 ************************\n");

    test();
    
    return 0;
}
