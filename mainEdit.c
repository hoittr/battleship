// Main.c file for Battleship game

#include <stdio.h>
#include <stdlib.h> // used in this program to clear the screen
#include <ctype.h>

int main () {
system ("clear"); //clears screen
int player [10][10];
int computer [10][10];
int i =0;
int ship;
char val;
int row;
int col;
char direction;
char playerName [20]; 

/* Welcome / Prompt User for Name */
printf("\t*** BATTLESHIP ***\n");
printf("Please enter your name: ");
scanf ("%s", &playerName);
printf ("Welcome to BATTLESHIP, %s!\n", playerName);
	
//Player Board Setup
int *setup; // sets up player board.

printf("\n#\tClass of ship\tSize\n");
printf("1\tCarrier \t5\n");
printf("2\tBattleship \t4\n");
printf("3\tCruiser \t3\n");
printf("4\tSubmarine \t3\n");
printf("5\tDestroyer \t2\n");

for (ship = 1; ship<6;ship++){
	printf("\n\t ***** FOR SHIP #%i *****\n", ship);
	printf("Please indicate the row you would like to place the ship (A-J):\n");
	printf("> ");
	scanf("%s", &val);
	row = toupper(val) - 65; //val stores as ASCII. Subtracting 65 = letter decimal value.
	printf("DEBUG: %i\n", row);
	printf("Please indicate the column you would like to place the ship (1-10):\n");
	printf("> ");
	scanf("%i", &col);
	printf("Which way would you like your ship to point (N,S,E,W)?\n");
	printf("> ");
	scanf("%s", &val);
	direction = val;
	printf("DEBUG: %i = ship %s = row, %i= col, %c=direction", ship, row, col, toupper(direction));
	
}
return 0;	
}
	
