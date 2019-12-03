CFLAGS= -Wall -fpic -coverage -lm -std=c99

bug4_unittest: bug4_unittest.c dominion.o rngs.o
	gcc  -o bug4_unittest -g bug4_unittest.c dominion.o rngs.o $(CFLAGS)

bug5_unittest: bug5_unittest.c dominion.o rngs.o
	gcc  -o bug5_unittest -g bug5_unittest.c dominion.o rngs.o $(CFLAGS)

bug6_unittest: bug6_unittest.c dominion.o rngs.o
	gcc  -o bug6_unittest -g bug6_unittest.c dominion.o rngs.o $(CFLAGS)

bug7_unittest: bug7_unittest.c dominion.o rngs.o
	gcc  -o bug7_unittest -g bug7_unittest.c dominion.o rngs.o $(CFLAGS)

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
