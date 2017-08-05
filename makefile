all: battleship

battleship: drawboard.o placement.o main.c
	gcc drawboard.o placement.o main.c -o battleship

placement.o: placement.c
	gcc -c placement.c

drawboard.o: drawboard.c
	gcc -c drawboard.c

clean:
	rm -f ./*.o
