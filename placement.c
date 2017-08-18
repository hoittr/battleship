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
*/

#include <stdio.h>
#include "placement.h"

int getLength(int ship){

  switch(ship) { // Depending on the ship selected, we have different lengths.
    case 1: // Carrier
      return 5;
      break;
    case 2: // Battleship
      return 4;
      break;
    case 3: // Cruiser
      return 3;
      break;
    case 4: //Submarine
      return 3;
      break;
    case 5: //Destroyer
      return 2;
      break;
      break;
  }
}

int placement(int (*board)[][10], int row, int col, int ship, char direction) {
  int length; // Init variable to hold length
  switch(ship) { // Depending on the ship selected, we have different lengths.
    case 1: // Carrier
      length = 5;
      break;
    case 2: // Battleship
      length = 4;
      break;
    case 3: // Cruiser
      length = 3;
      break;
    case 4: //Submarine
      length = 3;
      break;
    case 5: //Destroyer
      length = 2;
      break;
      break;
  }

  // Check to see if we would collide with another ship.
  switch (sanityCheck(board, row, col, length, direction)) {
    case 0: // Sanity checks passed. Continue on with placing ship.
      break;
    case 1: // Sanity check failed for OOB condition.
      //printf("Ship would be out of bounds, please try again.\n");
      return 1; // Error code for OOB
    case 2: // Sanity check failed for intersecting with another ship.
      //printf("Ship would intersect another, please try again.\n");
      return 2; // Error code for intersect
  }

  // Now that sanity checks have passed, and we know how long the ship is
  // modify the array to show our ships locations.
  switch(direction) {
    case 'N': // Bow of ship faces north, we add to the row but stay in same col.
      for(int i = 0; i < length; i++) { // Loop until length is hit.
        (*board)[row + i][col] = ship; // Fill the array locations with ship.
      }
      break;
    case 'S': // Bow of ship faces south.
      for(int i = 0; i < length; i++) {
        (*board)[row - i][col] = ship;
      }
      break;
    case 'E': // Bow of ship faces east.
      for(int i = 0; i < length; i++) {
        (*board)[row][col - i ] = ship;
      }
      break;
    case 'W': // Bow of ship faces west.
      for(int i = 0; i < length; i++) {
        (*board)[row][col + i] = ship;
      }
      break;
  }

  return 0; // Return Success
}

// Checks to see if other ships are in the way, or if placement would result
// in part of the ship being out of bounds.
int (sanityCheck(int (*board)[10][10], int row, int col, int length, char direction)) {
  switch(direction) {
    case 'S':
      if (row + length >= 10|| row >= 10|| col >= 10 ) { // Check to see if we would be out of bounds.
        return 1; // Error return
      }
      for(int i = 0; i < length; i++) {
        if ((*board)[row + i][col] != 0) {
            return 2; // Error return
        }
      }
      break;
    case 'N':
      if (row - length <= -1|| row >= 10|| col >= 10 ) { // Check to see if we would be out of bounds.
        return 1; // Error return
      }
      for(int i = 0; i < length; i++) {
        if ((*board)[row - i][col] != 0) {
            return 2; // Error return
        }
      }
      break;
    case 'W':
      if (col - length <= -1|| row >= 10|| col >= 10 ) { // Check to see if we would be out of bounds.
        return 1; // Error return
      }
      for(int i = 0; i < length; i++) {
        if ((*board)[row][col - i] != 0) {
            return 2; // Error return
        }
      }
      break;
    case 'E':
      if (col + length >= 10|| row >= 10|| col >= 10 ) { // Check to see if we would be out of bounds.
        return 1; // Error return
      }
      for(int i = 0; i < length; i++) {
        if ((*board)[row][col + i] != 0) {
            return 1; // Error return
        }
      }
      break;
  }
  return 0;
}
