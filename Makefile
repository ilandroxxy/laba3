CXX=gcc
CFLAGS = -c -Wall -Werror -std=c99
FLAGS  =  -Wall -Werror -std=c99
OBJECTS = build/main.o build/board.o build/draw_board.o build/draw.o build/board_read.o 

OB = build/board.o build/draw_board.o build/draw.o build/board_read.o 

.PHONY: clean all bin build default

all: bin build default

default: bin/programm

bin/programm: $(OBJECTS)
	$(CXX) $(FLAGS) $(OBJECTS) -o bin/programm

build/main.o: src/main.c src/board.h src/draw.h src/draw_board.h src/board_read.h
	$(CXX) $(CFLAGS) src/main.c -o build/main.o 

build/board.o: src/board.c src/board.h src/draw.h src/draw_board.h src/board_read.h
	$(CXX) $(CFLAGS) src/board.c -o build/board.o 

build/draw_board.o: src/draw_board.c src/board.h src/draw.h src/draw_board.h src/board_read.h
	$(CXX) $(CFLAGS) src/draw_board.c -o build/draw_board.o

build/draw.o: src/draw.c src/board.h src/draw.h src/draw_board.h src/board_read.h
	$(CXX) $(CFLAGS) src/draw.c -o build/draw.o

build/board_read.o: src/board_read.c src/board_read.h src/board.h
	$(CXX) $(CFLAGS) src/board_read.c -o build/board_read.o

build:
	mkdir -p build
bin:
	mkdir -p bin 
clean:
	rm -rf bin/* build/*.o