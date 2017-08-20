/*
// Testing out the "branch" feature! (sc)
CS-133U-0-33547 - C Programming
Professor Janik
Group Project
    Landon Winstead - landon.winstead@pcc.edu
    Ryan Hoitt - ryan.hoitt@pcc.edu
    Samantha Cleary - samantha.cleary@pcc.edu
Battleship game for CS133U
https://github.com/hoittr/battleship/
Project: We will be programming a single player “Battleship” game.
In Scope
- Single Player vs Computer
- Automatic or Random placement of ships
- 10x10 Game Board (Graphical Text Representation)
- Computer AI will be simple RNG + Logic
- In-game help screen & guidance
Out of Scope
- Dual Player (Could do this if we have time.)
- Adaptive AI
- Save & resume function
*/
#include <stdio.h>
#include <stdlib.h>
#include "placement.h"
#include "drawboard.h"
#include <time.h>
#include <ctype.h>

int AIPlacement(int (*boardaddr)[10][10], int ship); // Placement FUNCTION
int boardAI[10][10];
int (*boardAIaddr)[10][10] = &boardAI;
int boardPlayer[10][10];
int (*boardPlayeraddr)[10][10] = &boardPlayer;
int length;

int main() {
  char playerName [20];
  char direction;
  time_t t;
  int row=0, col=0, val=0, ship, i =0;
  srand((unsigned) time(&t)); // Init the RNG

/* Welcome / Prompt User for Name */
printf("\t*** BATTLESHIP ***\n");
printf("Please enter your name: ");
scanf ("%s", &playerName);
printf ("Welcome to BATTLESHIP, %s!\n", playerName);


for (ship = 1; ship<6;ship++){
	//Player Board Setup
	int *setup; // sets up player board.
	printf("\n#\tClass of ship\tSize\n");
	printf("1\tCarrier \t5\n");
	printf("2\tBattleship \t4\n");
	printf("3\tCruiser \t3\n");
	printf("4\tSubmarine \t3\n");
	printf("5\tDestroyer \t2\n");
	printf("\n\t ***** FOR SHIP #%i *****\n", ship);
	printf("Please indicate where you'd like to place the bow (FRONT) of your ship: (A-J):\n");
	printf("> ");
	scanf("%s", &val);
	row = toupper(val) - 65; //val stores as ASCII. Subtracting 65 = letter decimal value.
	printf("Please indicate the column you would like to place the ship (0-9):\n");
	printf("> ");
	scanf("%i", &col);
	printf("Which way would you like the bow (FRONT) to face (N,S,E,W)?\n");
	printf("> ");
	scanf("%s", &val);
	char direction = val;
	length = getLength(ship);
	printf("You have selected: %i = ship, %i = row, %i= col, %c= direction, %i = length\n", ship, row, col, toupper(direction), length);

	if (sanityCheck(boardPlayeraddr, row, col, length, toupper(direction)) !=0) { //check if player inputs are off board
	  ship--; // decrement counter to repeat loop
	  printf("\nInvalid placement. Please try again.");
	}
	else {
	  placement(boardPlayeraddr,row,col,ship,toupper(direction));
	  drawBoard(boardPlayeraddr, boardPlayeraddr);
	}

  }

  // Place the AI ships on the board randomly
  for (int x = 0; x < 6; x++) {
    while(AIPlacement(boardAIaddr, x) > 0) {
      //Dont do anything
    }
  }


  // DEBUGGING NOT FOR GAME UUSE
  drawBoard(boardAIaddr, boardAIaddr);
  drawBoard(boardPlayeraddr, boardPlayeraddr);

}

/*/=================================================================
  // AUTOMATIC TESTING FOR PLACEMENT FUNCTION
  // Uncomment this section to isolate and test placement.c
  // Leave commented normally.
  int board[10][10];
  int (*boardaddr)[10][10] = &board;
  // WHY DO I NEED THIS?!?!?
  // Compiler / CPU error? When I init the array without clearing it, it is full
  // of junk data?!?
  // https://stackoverflow.com/questions/1414215/initial-value-of-int-array-in-c
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      board[i][j] = 0;
    }
  }
  int res;
  for (int x = 0; x < 6; x++) {
    while(AIPlacement(boardaddr, x) > 0) {
      //Dont do anything
    }
  }
  drawBoard(boardaddr, boardaddr);
// =================================================================
*/


int AIPlacement(int (*boardaddr)[10][10], int ship) {
  int row = rand() % 9;
  int col = rand() % 9;
  int cardinal[4] = {78,83,69,87};
  int random = rand ()%4;
  char direction = cardinal[random];
  return placement(boardaddr,row,col,ship,direction);
}



