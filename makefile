all: battleship

battleship: placement.o main.c
	gcc placement.o main.c -o battleship

placement.o: placement.c
	gcc -c placement.c

clean:
	rm -f ./bin/*
