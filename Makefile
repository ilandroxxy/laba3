all: bin/compile

bin/compile: build/main.o build/board.o
	g++ build/main.o build/board.o -o $@

build/main.o: src/main.cpp
	g++ -c -Wall -Werror src/main.cpp -o $@

build/board.o: src/board.cpp
	g++ -c -Wall -Werror src/board.cpp -o $@

.PHONY: all clean install uninstall

clean:
	rm -rf bin/* build/*.o
