#include <iostream>
#include <string.h>
#include <cctype>
#include <cstring>

using namespace std;


void game(int (&board)[3][3], bool turn);
void printBoard(bool testBool, char (&board)[3][3], bool turn);

int main() {
  //int BLANK = 0;
  //int X_MOVE = 1;
  //int O_MOVE = 2;
  bool X_TURN = true;
  //int O_MOVE = 1
  bool turn = X_TURN;
  int X_SCORE = 0;
  int O_SCORE = 0;
  char board[3][3];

  for (int row = 0; row < 3; row++) {
    for (int column = 0; column < 3; column++) {
      board[row][column] = ' ';
    }
  }

  bool testBool = true;

  printBoard(testBool, board, turn);

  return 0;
}


void game(bool testBool, char (&board)[3][3], bool Xturn) {
  while (testBool == true) {
    char BLANK = ' ';
    char X_MOVE = 'X';
    char O_MOVE = 'O';

    char input[2];;
    cout << "Enter the coordinate:  " << endl;
    cin >> input;
    cout << "You entered: " << input << endl;
    int row = 0;
    int column = 0;
    //Check if Coordinate is valid
    if ( ((((input[0] == 'a')||(input[0] == 'b') || (input[0] == 'c')) && ((input[1] == '1')||(input[1] == '2') || (input[1] == '3'))) && (strlen(input)))) {
      if (input[0] == 'a') { row = 0;}
      if (input[0] == 'b') { row = 1;}
      if (input[0] == 'c') { row = 2;}
      if (input[1] == '1') { column = 0;}
      if (input[1] == '2') { column = 1;}
      if (input[1] == '3') { column = 2;}

      if (board[row][column] != ' ') { cout << "That is already filled. Try again" << endl; game(testBool, board, Xturn); }
      else if (Xturn == true) { board[row][column] = X_MOVE; printBoard(testBool, board, false); }
      else { board[row][column] = O_MOVE; printBoard(testBool, board, true); }
    }
    else {
      cout << "Enter a proper coordinate with a letter followed by a number\n" << endl;
    }
    
  }
}



void printBoard(bool testBool, char (&board)[3][3], bool turn) {

  
  
  char alpha[3] = {'a', 'b', 'c'};  //https://stackoverflow.com/questions/62006349/how-to-get-an-easier-way-of-generating-the-alphabet-in-c by user '463035818_is_not_a_number'
  cout << "  1 2 3" << endl;
      
  for (int row = 0; row < 3; row++) {
    cout << alpha[row] << " "; 
    for (int column = 0; column < 3; column++) {
      cout << board[row][column] << " ";
    }
    cout << endl;
  }
  game(testBool, board, turn);
}
