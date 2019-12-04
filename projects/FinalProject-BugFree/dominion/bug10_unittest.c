/********************************************************************
 * Author: George Lenz
 * Program: unittest10.c
 * Class: CS362 - Software Engineering II
 * Description: Unit test for ambassador case in card effect to test
 * if it is properly counting copies in hand
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
        printf("Passed\n");
        return 0;
    }
    else
    {
        printf("Failed\n");
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
state->whoseTurn = rand() % state->numPlayers;

//set actions to 0
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

//create current player's hand

int card = rand() % 27;

for (i = 0; i < state->handCount[state->whoseTurn] - 2; i++)
{
    while(card == i)
    {
        card = rand() % 27;
    }
 
    state->hand[state->whoseTurn][i] = card;
}
//make sure there are at least three of the same card in the hand
state->hand[state->whoseTurn][state->handCount[state->whoseTurn] - 1] = card;
state->hand[state->whoseTurn][state->handCount[state->whoseTurn] - 2] = card;


//place ambassador in current players hand
int ambassadorPos = 0; 
state->hand[state->whoseTurn][ambassadorPos] = ambassador;

int choice2 = 2; 

//run ambassador cardEffct
int result = cardEffect(ambassador, state->handCount[state->whoseTurn]-1, choice2, -1, state, ambassadorPos, 0);

//test results
assert(result, 0);

printf("playCard() return value: Expected: %d Actual: %d\n\n", 0, result);

return 0;
}


int main()
{
    srand(time(0));
    
    printf("\n\n************************ TESTING BUG #10 ************************\n");

    test();
    
    return 0;
}
