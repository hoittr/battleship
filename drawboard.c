/* Draw Board.c
   Handles drawing the game board.


   INPUTS:
    int *playerBoard -- a pointer to the players game board [10x10 array of ints]
    int *computerBoard -- a pointer to the computers game board [10x10 array of ints]

    RETURNS:
      integer
      0 - Success
      1 - Fail.


          #	Class of ship	Size
          1	Carrier	5
          2	Battleship	4
          3	Cruiser	3
          4	Submarine	3
          5	Destroyer	2
*/
#include <stdio.h>
#include "drawboard.h"

int drawBoard(int (*board)[][10], int hideShips) {
  printf("# - A - B - C - D - E - F - G - H - I - J\n");
  printf("-----------------------------------------\n");
  for (int i = 0; i < 10; i++) {
    printf("%i |", i);
    for (int j = 0; j < 10; j++) {
      if (!hideShips) { // Ships are hidden, only show ? or X
        switch ((*board)[i][j]) {
          case 9:
            printf(" X  ");
            break;
          case 8:
            printf(" M  ");
            break;
          default:
            printf(" ?  "); 
            break;
        }
      } else {
        switch ((*board)[i][j]) {
          case 0:
            printf(" ?  "); 
            break;
          case 1:
            printf(" C  ");
            break;
          case 2:
            printf(" B  ");
            break;
          case 3:
            printf(" R  ");
            break;
          case 4:
            printf(" S  ");
            break;
          case 5:
            printf(" D  ");
            break;
          case 8:
            printf(" M  ");
            break;
          case 9:
            printf(" X  ");
            break;
          default:
            printf(" ?  "); 
            break;
        }
      }
    }
    printf("\n");
  }
  return 0;
}



/* INPUTS:
 int *board -- a pointer to the game board [10x10 array of ints]
 int row -- row to fire at
 int col -- col to fire at

 RETURNS:
   int
   0 - Miss
   1 - Hit
*/
int fireMissile(int (*board)[][10],int row, int col) {
  if ((*board)[row][col] != 0) {
    (*board)[row][col] = 9; // Mark as hit on the board
    return 1; // return sucessful hit
  } else {
    (*board)[row][col] = 8; // Mark as miss on the board
    return 0; // MISS
  }

}

/* INPUTS:
 int *board -- a pointer to the game board [10x10 array of ints]


 RETURNS:
   int number of ships remaining
*/
int checkProgress(int (*board)[][10]) {
  int one = 0, two = 0, three = 0, four = 0, five = 0, count = 0;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      switch ((*board)[i][j]) {
        case 1:
          one++;
          break;
        case 2:
          two++;
          break;
        case 3:
          three++;
          break;
        case 4:
          four++;
          break;
        case 5:
          five++;
          break;
      }
    }
  }
  if (one > 0) {
    count++;
  }
  if (two > 0) {
    count++;
  }
  if (three > 0) {
    count++;
  }
  if (four > 0) {
    count++;
  }
  if (five > 0) {
    count++;
  }

  return count;
}
