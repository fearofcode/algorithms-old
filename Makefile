CC = clang

FLAGS =  -Wall -D_GNU_SOURCE -O3

LIBS = -lc

all: quickfind quickunion weightedquickunion weightedquickunionhalving

quickfind:
	$(CC) quickfind.c -o quickfind.out $(LIBS) $(FLAGS)

quickunion:
	$(CC) quickunion.c -o quickunion.out $(LIBS) $(FLAGS)

weightedquickunion:
	$(CC) weightedquickunion.c -o weightedquickunion.out $(LIBS) $(FLAGS)

weightedquickunionhalving:
	$(CC) weightedquickunionhalving.c -o weightedquickunionhalving.out $(LIBS) $(FLAGS)

clean: 
	rm -f *.out *.o