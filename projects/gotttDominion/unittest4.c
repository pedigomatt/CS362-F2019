/*
 * unittest4.c
 * Mine
 
 */

/*
 * Include the following lines in your makefile:
 *
 * unittest4: unittest4.c dominion.o rngs.o
 *      gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "mine"

int main() {
    //Test 1 - currentPlayer[choice1] is not a treasure

    //Test 2 - Choice 2 is not a valid choice

    //Test 3 - choice 2 is > 3 more than choice 1

}