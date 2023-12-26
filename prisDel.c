/*------------------------------------------
Author: Daniel Platt
Program: cardinalSort.c
Purpose: recreate the prisoners dilemma
Date: Dec. 25th 2023
--------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int eval(int player1[], int player2[]) {
  // I can just run it with booleans
  int total = player1[0] + player2[0];
  switch (total) {

  case 2:
    player1[1] += 3;
    player2[1] += 3;
    // printf("Neither player defected.\n3 points awarded to both\n");
    break;
  case 1:
    if (player1[0]) {
      player2[1] += 5;
      // printf("Player2 defected\n5 points awarded to Player2\n");
    } else {
      player1[1] += 5;
      // printf("Player1 defected\n5 points awarded to Player1\n");
    }
    break;
  case 0:
    player1[1] += 1;
    player2[1] += 1;
    // printf("both players defected\n1 points awarded to both\n");
    break;
  }
  return 0;
}
void randomTest(int player1[], int player2[]) {
  /* Purpose: run test with purely randomly selected values
   * PreReq: must run srand before usuing for different values
   */
  player1[0] = rand() % 2;
  player2[0] = rand() % 2;
  eval(player1, player2);
  printf("----------\nplayer1:%d\nplayer2:%d\n", player1[1], player2[1]);
  if ((player1[1] <= 100) && (player2[1] <= 100)) {
    randomTest(player1, player2);
  } else
    return;
}

int main() {
  int player1[2] = {0}, player2[2] = {0};
  /* player1[0] = 1, player2[0] = 1;
  printf("player1:%d\n", player1[0]);
  eval(player1, player2);
  printf("player1:%d\n", player1[1]); */
  srand(time(0)), randomTest(player1, player2); // sets new random seed
  printf("\n================\nTotal:\nPlayer1: %d\nPlayer2: %d\n", player1[1],
         player2[1]);
  return 0;
}
