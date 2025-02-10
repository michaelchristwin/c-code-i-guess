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

bool check_win(char board[3][3], char symbol) {
  // Check rows
  for (int row = 0; row < 3; row++) {
    if (board[row][0] == symbol && board[row][1] == symbol &&
        board[row][2] == symbol) {
      return true;
    }
  }

  // Check columns
  for (int col = 0; col < 3; col++) {
    if (board[0][col] == symbol && board[1][col] == symbol &&
        board[2][col] == symbol) {
      return true;
    }
  }

  // Check diagonals
  if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
    return true;
  }
  if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
    return true;
  }

  return false;
}

bool check_draw(char board[3][3]) {
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      if (board[row][col] == ' ') {
        return false; // There's an empty cell, so it's not a draw
      }
    }
  }
  return true; // All cells are filled
}

int tic_tac_toe() {
  printf("Welcome to Tic-Tac-Toe!\n");
  printf("Player 1: X\n");
  printf("Player 2: O\n");
  printf("Enter the row and column (e.g., 1 2) to make your move.\n");

  char board[3][3] = {
      {' ', ' ', ' '}, // Row 1
      {' ', ' ', ' '}, // Row 2
      {' ', ' ', ' '}  // Row 3
  };

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
    if (scanf("%d %d", &row, &col) != 2) {
      printf("Invalid input! Please enter two numbers.\n");
      while (getchar() != '\n')
        ;       // Clear the input buffer
      continue; // Skip the rest of the loop and prompt again
    }

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

    // Check for a win
    if (check_win(board, current_player_symbol)) {
      print_board(board);
      printf("Player %d (%c) wins! Congratulations!\n", current_player,
             current_player_symbol);
      break; // Exit the game loop
    }

    // Check for a draw
    if (check_draw(board)) {
      print_board(board);
      printf("It's a draw! Better luck next time.\n");
      break; // Exit the game loop
    }

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