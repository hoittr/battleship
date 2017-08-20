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

int drawBoard(int (*board)[][10]) {
  printf("# - A - B - C - D - E - F - G - H - I - J\n");
  printf("-----------------------------------------\n");
  for (int i = 0; i < 10; i++) {
    printf("%i |", i);
    for (int j = 0; j < 10; j++) {
      printf(" %i  ", (*board)[i][j]);
    }
    printf("\n");
  }
  return 0;
}
