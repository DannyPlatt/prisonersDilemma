/*------------------------------------------
Author: Daniel Platt
Program: cardinalSort.c
Purpose: recreate the prisoners dilemma
Date: Dec. 25th 2023
--------------------------------------------*/
#include <stdio.h>

int eval(int player1, int player2, int choice1, int choice2) {
  // I can just run it with booleans
  int total = choice1 + choice2;

  switch (total) {

  case 2:
    player1 += 3;
    player2 += 3;
    printf("Neither player defected.\n3 points awarded to both\n");
    break;
  case 1:
    if (choice1) {
      player2 += 5;
      printf("Player2 defected\n5 points awarded to Player2\n");
    } else {
      player1 += 5;
      printf("Player1 defected\n5 points awarded to Player1\n");
    }
    break;
  case 0:
    player1 += 1;
    player2 += 1;
    printf("both players defected\n1 points awarded to both\n");
    break;
  }
  return 0;
}

int main() {
  int player1 = 0, player2 = 0;
  int choice1 = 1, choice2 = 0;
  eval(player1, player2, choice1, choice2);
  return 0;
}
