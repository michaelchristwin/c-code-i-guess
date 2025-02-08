#include "../include/tic_tac_toe.h"
#include <stdio.h>

int tic_tac_toe() {
  printf("Welcome to Tic-Tac-Toe!\n");
  printf("Player 1: X\n");
  printf("Player 2: O\n");
  printf("Enter the row and column (e.g., 1 2) to make your move.");
  char array[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      array[i][j] = '-';
    }
  }
  return 0;
}