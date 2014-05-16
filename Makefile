CC = clang

FLAGS =  -Wall -D_GNU_SOURCE -O3

LIBS = -lc

all: quickfind quickunion

quickfind:
	$(CC) quickfind.c -o quickfind.out $(LIBS) $(FLAGS)

quickunion:
	$(CC) quickunion.c -o quickunion.out $(LIBS) $(FLAGS)

clean: 
	rm -f *.out *.o