CC = gcc
CFLAGS += -Wall -Wextra -std=c99

sokoban: main.o grid.o player.o
	$(CC) main.o grid.o player.o -o sokoban

main.o: main.c grid.h
	$(CC) $(CFLAGS) -c main.c

grid.o: grid.c grid.h
	$(CC) $(CFLAGS) -c grid.c

player.o: player.c grid.h
	$(CC) $(CFLAGS) -c player.c 

doc: 
	doxygen Doxyfile

clean:
	rm -rf *.o sokoban html *.tar.gz

archive:
	tar -cJvf sokobanGame_ANDREOLLI.tar.gz *.c *.h *.txt Makefile README.md Doxyfile