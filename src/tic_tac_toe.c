#include "../include/tic_tac_toe.h"
#include <stdbool.h>
#include <stdio.h>

void print_board(char board[3][3]) {
  printf("  1   2   3\n");
  printf("-------------\n");
  for (int row = 0; row < 3; row++) {
    printf("%d | %c | %c | %c |\n", row + 1, board[row][0], board[row][1],
           board[row][2]);
    printf("-------------\n");
  }
}

int tic_tac_toe() {
  printf("Welcome to Tic-Tac-Toe!\n");
  printf("Player 1: X\n");
  printf("Player 2: O\n");
  printf("Enter the row and column (e.g., 1 2) to make your move.\n");
  // char array[3][3];
  // for (int i = 0; i < 3; i++) {
  //   for (int j = 0; j < 3; j++) {
  //     array[i][j] = '-';
  //   }
  // }
  bool gameover = false;
  char board[3][3] = {
      {' ', ' ', ' '}, // Row 1
      {' ', ' ', ' '}, // Row 2
      {' ', ' ', ' '}  // Row 3
  };

  // Print the column numbers
  // print_board(board);
  // while (!gameover) {
  // }
  int current_player = 1;           // Player 1 starts
  char current_player_symbol = 'X'; // Player 1 uses 'X'

  while (1) {
    // Print the board
    print_board(board);

    // Prompt the current player for input
    printf("Player %d (%c), enter row and column (e.g., 1 2): ", current_player,
           current_player_symbol);

    // Read the input
    int row, col;
    scanf("%d %d", &row, &col);

    // Adjust to 0-based indexing
    row--;
    col--;

    // Validate the input
    if (row < 0 || row > 2 || col < 0 || col > 2) {
      printf("Invalid input! Row and column must be between 1 and 3.\n");
      continue; // Skip the rest of the loop and prompt again
    }

    if (board[row][col] != ' ') {
      printf("Cell already occupied! Try again.\n");
      continue; // Skip the rest of the loop and prompt again
    }

    // Update the board
    board[row][col] = current_player_symbol;

    // Switch players
    if (current_player == 1) {
      current_player = 2;
      current_player_symbol = 'O';
    } else {
      current_player = 1;
      current_player_symbol = 'X';
    }
  }
  return 0;
}
