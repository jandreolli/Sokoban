CC = gcc
CFLAGS += -Wall -Wextra -std=c99
LDFLAGS += -Linstall_dir/lib/ -lSDL2 -Wl,-rpath=install_dir/lib/

all: compileLIB sokoban

sokoban: main.o grid.o player.o sdl2.o
	$(CC) main.o grid.o player.o sdl2.o -o sokoban $(LDFLAGS)

main.o: main.c grid.h sdl2.h
	$(CC) $(CFLAGS) -c main.c

grid.o: grid.c grid.h
	$(CC) $(CFLAGS) -c grid.c

player.o: player.c grid.h
	$(CC) $(CFLAGS) -c player.c 

sdl2.o : sdl2.c grid.h sdl2.h
	$(CC) $(CFLAGS) -c sdl2.c

compileLIB:
	cd SDL2 && ./configure --prefix=$$PWD/../install_dir
	cd SDL2 && make install -j6

doc: 
	doxygen Doxyfile

clean:
	rm -rf *.o sokoban html *.tar.gz install_dir

archive:
	tar -cJvf sokobanGame_ANDREOLLI.tar.gz *.c *.h *.txt Makefile README.md Doxyfile SDL2