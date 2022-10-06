#include <iostream>
#include <string.h>
#include <cctype>
#include <cstring>

using namespace std;


void game();
void printBoard();

int main() {
  int BLANK = 0;
  int X_MOVE = 1;
  int O_MOVE = 2;
  int X_TURN = 0;
  int O_TURN = 1;
  int turn = X_TURN;
  int X_SCORE = 0;
  int O_SCORE = 0;

  bool testBool = true;

  printBoard(bool testBool);

}


void game() {
  while (testBool == True) {

  }
}



void printBoard(bool testBool) {
  int board[3][3];
  char alpha[3] = {'a', 'b', 'c'};  //https://stackoverflow.com/questions/62006349/how-to-get-an-easier-way-of-generating-the-alphabet-in-c by user '463035818_is_not_a_number'
  cout << "  1 2 3" << endl;
  for (int row = 0; row < 3; row++) {
    cout << alpha[row] << " "; 
    for (int column = 0; column < 3; column++) {
      cout << "  ";
    }
    cout << endl;
  }
  game(testBool);
}
