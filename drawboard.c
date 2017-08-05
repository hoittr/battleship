/* Draw Board.c
   Handles drawing the game board.
   INPUTS:
    int *playerBoard -- a pointer to the players game board [10x10 array of ints]
    int *computerBoard -- a pointer to the computers game board [10x10 array of ints]

    RETURNS:
      integer
      0 - Success
      1 - Fail.
*/
#include <stdio.h>
#include "drawboard.h"

int drawBoard(int (*playerBoard)[][10], int (*computerBoard)[][10]) {
  printf("# - 0 - 1 - 2 - 3 - 4 - 5 - 6 - 7 - 8 - 9\n");
  printf("-----------------------------------------\n");
  for (int i = 0; i < 10; i++) {
    printf("%i |", i);
    for (int j = 0; j < 10; j++) {
      printf(" %i  ", (*playerBoard)[i][j]);
    }
    printf("\n");
  }
  return 0;
}
