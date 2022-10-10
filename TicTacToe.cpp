#include <iostream>
#include <string.h>
#include <cctype>
#include <cstring>

using namespace std;


void game();
void printBoard(bool testBool);

int main() {
  //int BLANK = 0;
  //int X_MOVE = 1;
  //int O_MOVE = 2;
  int X_TURN = 0;
  int O_TURN = 1;
  int turn = X_TURN;
  int X_SCORE = 0;
  int O_SCORE = 0;

  bool testBool = true;

  printBoard(testBool);

}


void game(bool testBool) {
  while (testBool == true) {
    char input[2];;
    cout << "Enter the coordinate:  " << endl;
    cin >> input;
    cout << "You entered: " << input << endl;
    //Check if Coordinate is valid
    if ( (((input[0] == 'a')||(input[0] == 'b') || (input[0] == 'c')) && ((input[1] == '1')||(input[1] == '2') || (input[1] == '3'))) && (strlen(input))) {
      cout << "This works\n" << endl;
    }
    else {
      cout << "Enter a proper coordinate with a letter followed by a number\n" << endl;
    }
    
  }
}



void printBoard(bool testBool) {
  int board[3][3];
  int BLANK = 0;
  int X_MOVE = 0;
  int O_MOVE = 0;

  
  char alpha[3] = {'a', 'b', 'c'};  //https://stackoverflow.com/questions/62006349/how-to-get-an-easier-way-of-generating-the-alphabet-in-c by user '463035818_is_not_a_number'
  cout << "  1 2 3" << endl;
      
  for (int row = 0; row < 3; row++) {
    cout << alpha[row] << " "; 
    for (int column = 0; column < 3; column++) {
      cout << BLANK << " ";
    }
    cout << endl;
  }
  game(testBool);
}
