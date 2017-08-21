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

#define SCREENSIZE 100

int boardAI[10][10];
int (*boardAIaddr)[10][10] = &boardAI;
int boardPlayer[10][10];
int (*boardPlayeraddr)[10][10] = &boardPlayer;
int length;

char playerName [20];

void gameSetup();
void clearScreen ();
int processTurn();
int processAITurn();


int main() {
  time_t t;
  srand((unsigned) time(&t)); // Init the RNG

  clearScreen(); // Clear the screen

  gameSetup(); // Ask player for name, ship placement, and setup the AI board.

  int playerShipsRemaining = 1;
  int AIShipsRemaining = 1;

  while (playerShipsRemaining > 0 && AIShipsRemaining > 0) {
    processTurn();
    processAITurn();
    clearScreen();
    playerShipsRemaining = checkProgress(boardPlayeraddr);
    AIShipsRemaining = checkProgress(boardAIaddr);
    printf("=====COMPUTER BOARD===== (%i) SHIPS REMAINING ======\n", AIShipsRemaining);
    drawBoard(boardAIaddr, 1); // 1 = CHEATMODE 0 = NORMAL MODE
    printf("\n=====PLAYER BOARD===== (%i) SHIPS REMAINING ======\n", playerShipsRemaining);
    drawBoard(boardPlayeraddr, 1);
  }

  if (AIShipsRemaining == 0 ) {
    printf("\nYOU WON!\n");
  } else {
    printf("\nYOU LOST!\n");
  }

}

int processAITurn () {
  int row = rand() % 9;
  int col = rand() % 9;
  return fireMissile(boardPlayeraddr,row,col);
}

int processTurn () {
  int row, col; // Init variables
  char val;
  printf("Fire Missle!!!\n");
  printf("(A-J): \n");
  printf("> ");
  scanf("%s", &val);
  col = toupper(val) - 65; //val stores as ASCII. Subtracting 65 = letter decimal value.
  printf("(0-9):\n");
  printf("> ");
  scanf("%i", &row);
  printf("Fired Missle at %i %i\n", col, row);
  if (fireMissile(boardAIaddr,row,col) != 0) {
    printf("HIT!!!\n");
  } else {
    printf("MISS\n");
  }
  return 0;
}



void clearScreen () {
  for (int i = 0; i < SCREENSIZE; i++) {
    printf("\n");
  }
}

void gameSetup () {
  char direction;

  int row=0, col=0, val=0, i =0;

  /* Welcome / Prompt User for Name */
  printf("\t*** BATTLESHIP ***\n");
  printf("Please enter your name: ");
  fgets(playerName, 20, stdin); //changed to fgets to read whitespace. -sc
  printf ("Welcome to BATTLESHIP, %s!\n", playerName);
  printf("\n\t\t ***RULES***\n"); //added rules -sc
  printf("Place your ships on your grid based upon the coordinates.\n");
  printf("You and the computer player will take turns guessing\n");
  printf("Each other's ship coordinates.\n");
  printf("Whoever sinks the other player's ships first\n");
  printf("will be declared the winner!\n");
  printf("\n\t\t***LEGEND***\n");
  printf(" m = MISS!\n");
  printf(" X = HIT!\n");
  


  for (int ship = 1; ship<6;ship++){
  	//Player Board Setup

  	printf("\n#\tClass of ship\tSize\n");
  	printf("1\tCarrier \t5\n");
  	printf("2\tBattleship \t4\n");
  	printf("3\tCruiser \t3\n");
  	printf("4\tSubmarine \t3\n");
  	printf("5\tDestroyer \t2\n");
  	printf("\n\t ***** FOR SHIP #%i *****\n", ship);
  	printf("Please indicate the column to place the bow (FRONT) of your ship: (A-J):\n");
  	printf("> ");
  	scanf("%s", &val);
  	col = toupper(val) - 65; //val stores as ASCII. Subtracting 65 = letter decimal value.
  	printf("Please indicate the column you would like to place the ship (0-9):\n");
  	printf("> ");
  	scanf("%i", &row);
  	printf("Which way would you like the bow (FRONT) to face (N,S,E,W)?\n");
  	printf("> ");
  	scanf("%s", &val);
  	char direction = val;
  	length = getLength(ship);
  	printf("You have selected: %i = ship, %i = row, %i= col, %c= direction, %i = length\n", ship, row, col, toupper(direction), length);

  	if (placement(boardPlayeraddr,row,col,ship,toupper(direction)) !=0) { //check if player inputs are off board
  	  ship--; // decrement counter to repeat loop
  	  printf("\nInvalid placement. Please try again.");
    } else {
      clearScreen();
  	  drawBoard(boardPlayeraddr, 1);
  	}

  }

  // Place the AI ships on the board randomly
  for (int x = 0; x < 6; x++) {
    while(AIPlacement(boardAIaddr, x) > 0) {
      //Dont do anything, RNG is placing ships.
    }
  }
}
