#include <stdio.h>
#include "placement.h"

int placement(int (*board)[10][10], int row, int col, int ship, char direction) {
  printf("Called me!\n Char: %c\n", direction);
  printf("[2][4] = : %i", (*board)[2][4]);
  return 1;
}
