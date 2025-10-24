#include <stdio.h>

// this function prints the board
void print_board(char *a) {
  for (int i = 1, k = 0; i <= 7; i++) {
    for (int j = 1; j <= 7; j++) {
      if (i % 2 != 0 || j % 2 != 0) {
        printf("• ");
      } else {
        printf("%c ", a[k]);
        k++;
      }
    }
    printf("\n");
  }
}

// this function checks if winning condition is satisfied
int isWin(char *a) {
  if ((a[0] == a[1]) && (a[1] == a[2]) && (a[0] == a[2]) ||
      (a[3] == a[4]) && (a[4] == a[5]) && (a[3] == a[5]) ||
      (a[6] == a[7]) && (a[7] == a[8]) && (a[6] == a[8])) {
    return 1;
  } else if ((a[0] == a[3]) && (a[3] == a[6]) && (a[0] == a[6]) ||
             (a[1] == a[4]) && (a[4] == a[7]) && (a[1] == a[7]) ||
             (a[2] == a[5]) && (a[5] == a[8]) && (a[2] == a[8])) {
    return 1;
  } else if ((a[0] == a[4]) && (a[4] == a[8]) && (a[0] == a[8]) ||
             (a[2] == a[4]) && (a[4] == a[6]) && (a[2] == a[6])) {
    return 1;
  } else {
    return 0;
  }
}

// this function puts marks on the board
void put_mark(char *a, int n, char m) { a[n] = m; }

// this function checks if the input is invalid
int isInvalidInput(int n) {
  if (0 <= n && n <= 8) {
    return 0;
  }
  printf("invalid input!\n");
  return 1;
}

/*this function checks if the cell that is selected for
putting value is already occupied
*/
int isOccupied(char *a, int n) {
  if (a[n] == 'X' || a[n] == 'o') {
    printf("%d Cell is occupied!\n", n);
    return 1;
  }
  return 0;
}

int main() {
  printf("Here is a simple 2 player tic-tac-toe game:\n");
  printf("Players are requested to enter cell\nnumbers (0-8) according to the "
         "shown diagram:\n");
  int Q = 5;
  while (Q == 5) {
    char a[9];
    for (int i = 0; i < 9; i++) {
      a[i] = '0' + i;
    }
    int n;
    print_board(a);
    int i = 0;
    int winner = 0;
    while (i < 9) {
      do {
        printf("Player 1,enter cell number:");
        scanf("%d", &n);
      } while (isInvalidInput(n) || isOccupied(a, n));
      put_mark(a, n, 'X');
      i++;
      if (i == 9) {
        break;
      }
      print_board(a);
      if (isWin(a)) {
        winner = 1;
        break;
      }
      do {
        printf("Player 2,enter cell number:");
        scanf("%d", &n);
      } while (isInvalidInput(n) || isOccupied(a, n));
      put_mark(a, n, 'o');
      i++;
      print_board(a);
      if (isWin(a)) {
        winner = 2;
        break;
      }
    }
    printf("Final result:\n");
    print_board(a);
    if (winner) {
      printf("Winner is player %d!\n", winner);
    } else {
      printf("Draw!\n");
    }
    printf("Enter 5 to replay or 1 to end:");
    scanf("%d", &Q);
  }
  if (Q == 1) {
    printf("Game ended\nThank you for playing!");
  }
  return 0;
}
