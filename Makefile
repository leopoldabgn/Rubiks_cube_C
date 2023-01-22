# Instuction: Run make. That's it. 
CC=gcc
CFLAGS=-Wall -g -pedantic
all: clean temp

temp:
	gcc -Wall rubiks.c IA.c functions.c getch.c functions.h getch.h -o rubiks -lm

rubiks: rubiks.o ia.o functions.o
	$(CC) $(CFLAGS) -o $@ $^

rubiks.o: rubiks.c functions.c functions.h
	$(CC) $(CFLAGS) -o $@ -c $<

ia.o: IA.c functions.c functions.h
	$(CC) $(CFLAGS) -o $@ -c $<

functions.o: rubiks.c functions.c IA.c functions.h
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f *.o
	rm -f rubiks
