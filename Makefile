CC = clang

FILES = main.c

FLAGS =  -Wall -g -o quickfind -D_GNU_SOURCE

LIBS = -lc

all: 
	$(CC) $(FILES) $(LIBS) $(FLAGS)

clean: 
	rm -f prog *.o