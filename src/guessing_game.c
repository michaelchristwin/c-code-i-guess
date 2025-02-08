
#include "../include/guessing_game.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void try(int b) {
  int a;
  printf("Guess a number between 1 to 100: ");
  scanf("%d", &a);

  if (a < b) {
    printf("your choice is less than \n");
    try(b);
  } else if (a > b) {
    printf("your choice is greater than \n");
    try(b);
  } else {
    printf("Correct ✅🥳 \n");
  }
}
int guesser() {
  srand(time(NULL));
  int number = rand() % 100 + 1;
  try(number);
  return 0;
}
