/* Placement.h
   Handles placement of pieces into the game board.
   INPUTS:
    int *board -- a pointer to the game board [10x10 array of ints]
    int row -- the row in which the player wants to place the bow of their ship.
    int col -- the column where the bow of the ship will be placed.
    int ship -- an int containing:
        #	Class of ship	Size
        1	Carrier	5
        2	Battleship	4
        3	Cruiser	3
        4	Submarine	3
        5	Destroyer	2
    char direction - which way does the ship point? N, S, E, W

    RETURNS:
      integer
      0 - Success
      1 - Fail Out of Bounds.
      2 - Fail would intersect another ship.
      3 - Fail ship already placed.
*/

int placement(int (*board)[10][10], int row, int col, int ship, char direction);
int sanityCheck(int (*board)[10][10], int row, int col, int length, char direction);
int AIPlacement(int (*boardaddr)[10][10], int ship);
int getLength(int ship);
