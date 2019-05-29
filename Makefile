.PHONY: all  clean test
BB=g++ -Wall -Werror
SFMLFIX = -lsfml-graphics -lsfml-window -lsfml-system

all: bin/game

bin/game: repository  build/src/main.o build/src/menu.o build/src/game.o 
	$(BB) build/src/main.o build/src/menu.o build/src/game.o -o bin/game -lncurses $(SFMLFIX)
build/src/main.o: src/main.c
	$(BB) -c -o build/src/main.o src/main.c -lncurses $(SFMLFIX)
build/src/menu.o: src/menu.c
	$(BB) -c -o build/src/menu.o src/menu.c -lncurses $(SFMLFIX)
build/src/game.o: src/game.c
	$(BB) -c -o build/src/game.o src/game.c -lncurses $(SFMLFIX)

repository:
	mkdir -p bin
	mkdir -p build
	mkdir -p build/src
	mkdir -p build/tests
clean:
	rm -rf bin/game
	rm -rf bin/test
	rm -R build

test: repository bin/test

bin/test: build/tests/first_test.o build/tests/test.o build/tests/functest.o
	gcc -Wall -std=c99 build/tests/first_test.o build/tests/functest.o build/tests/test.o -o bin/test -Ilibrary -lm
build/tests/first_test.o: test/first_test.c
	gcc -Wall -std=c99 -c test/first_test.c -o build/tests/first_test.o -Ilibrary -lm
build/tests/test.o: test/test.c build/tests/functest.o
	gcc -Wall -std=c99 -c test/test.c -o build/tests/test.o -Ilibrary -lm
build/tests/functest.o: test/functest.c
	gcc -Wall -std=c99 -c test/functest.c -o build/tests/functest.o -Ilibrary -lm
