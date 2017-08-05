/*
// Testing out the "branch" feature! (sc)
CS-133U-0-33547 - C Programming
Professor Janik

Group Project
    Landon Winstead -
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
#include "placement.h"
#include "drawboard.h"

int main() {

/* =================================================================

  // AUTOMATIC TESTING FOR PLACEMENT FUNCTION
  // Uncomment this section to isolate and test placement.c
  // Leave commented normally.

  int board[10][10];
  int (*boardaddr)[10][10] = &board;

  // WHY DO I NEED THIS?!?!?
  // Compiler / CPU error? When I init the array without clearing it, it is full
  // of junk data?!?
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      board[i][j] = 0;
    }
  }
  int res;

  // TEST 1 - Should succeed. Places carrier in 0 0 N
  res = placement(boardaddr, 6, 6, 1, 'N');
  if (res != 0) {
    printf("TEST FAIL: ERROR CODE: %i\n", res);
  } else {
    printf("TEST PASS\n");
  };

  drawBoard(boardaddr, boardaddr);
=================================================================
*/

}
