/*
 * unittest5.c
 * Baron
 
 */

/*
 * Include the following lines in your makefile:
 *
 * unittest5: unittest5.c dominion.o rngs.o
 *      gcc -o unittest5 -g  unittest5.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "baron"

int main() {
    //Test 1  - choice 1 > 0 - discard estate for +4 treasure with estate card in hand

    //Test 2 - choice 1 > 0 - w/estate card not in hand

    //Test 3 - choice 1 < 0 - no estate card

    ///////////'
}