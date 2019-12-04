CFLAGS= -Wall -fpic -coverage -lm -std=c99

unittest1: unittest1.c dominion.o rngs.o
	gcc  -o unittest1 -g unittest1.c dominion.o rngs.o $(CFLAGS)

unittest2: unittest2.c dominion.o rngs.o
	gcc  -o unittest2 -g unittest2.c dominion.o rngs.o $(CFLAGS)

unittest3: unittest3.c dominion.o rngs.o
	gcc  -o unittest3 -g unittest3.c dominion.o rngs.o $(CFLAGS)

bug4unittest: bug4_unittest.c dominion.o rngs.o
	gcc  -o bug4_unittest -g bug4_unittest.c dominion.o rngs.o $(CFLAGS)

bug5unittest: bug5_unittest.c dominion.o rngs.o
	gcc  -o bug5_unittest -g bug5_unittest.c dominion.o rngs.o $(CFLAGS)

bug6unittest: bug6_unittest.c dominion.o rngs.o
	gcc  -o bug6_unittest -g bug6_unittest.c dominion.o rngs.o $(CFLAGS)

bug7unittest: bug7_unittest.c dominion.o rngs.o
	gcc  -o bug7_unittest -g bug7_unittest.c dominion.o rngs.o $(CFLAGS)

bug8unittest: bug8_unittest.c dominion.o rngs.o
	gcc  -o bug8_unittest -g bug8_unittest.c dominion.o rngs.o $(CFLAGS)

bug9unittest: bug9_unittest.c dominion.o rngs.o
	gcc  -o bug9_unittest -g bug9_unittest.c dominion.o rngs.o $(CFLAGS)

bug10unittest: bug10_unittest.c dominion.o rngs.o
	gcc  -o bug10_unittest -g bug10_unittest.c dominion.o rngs.o $(CFLAGS)
	
unittestresults: unittest1 unittest2 unittest3 bug4unittest bug5unittest bug6unittest bug7unittest bug8unittest bug9unittest bug10unittest
	./unittest1 > unittestresults.out
	./unittest2 >> unittestresults.out
	./unittest3 >> unittestresults.out
	./bug4_unittest >> unittestresults.out
	./bug5_unittest >> unittestresults.out
	./bug6_unittest >> unittestresults.out
	./bug7_unittest >> unittestresults.out
	./bug8_unittest >> unittestresults.out
	./bug9_unittest >> unittestresults.out
	./bug10_unittest >> unittestresults.out
	gcov dominion.c -b -f >> unittestresults.out

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

cleanall: clean
	rm -f bug*_unittest
