/* Draw Board.h
   Handles drawing the game board.
   INPUTS:
    int *playerBoard -- a pointer to the players game board [10x10 array of ints]
    int *computerBoard -- a pointer to the computers game board [10x10 array of ints]

    RETURNS:
      integer
      0 - Success
      1 - Fail Out of Bounds.
      2 - Fail would intersect another ship.
      3 - Fail ship already placed.
*/

int drawBoard(int (*playerBoard)[][10], int (*computerBoard)[][10]);
