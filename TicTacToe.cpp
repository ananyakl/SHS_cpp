//Tic Tac Toe game
//Ananya Lanka
//Referenced 2021-2022 Java TicTacToe assignment


#include <iostream>
#include <string.h>
#include <cctype>
#include <cstring>

using namespace std;


void game(int (&board)[3][3], bool &turn, int &X_SCORE, int &O_SCORE, int &TIE);
void printBoard(bool &stillPlaying, char (&board)[3][3], bool &Xturn, int &X_SCORE, int &O_SCORE, int &TIE);
bool checkWin(bool &stillPlaying, bool &Xturn, char (&board)[3][3], int &X_SCORE, int &O_SCORE, int &TIE);
bool checkTie(bool &stillPlaying, char (&board)[3][3], int &X_SCORE, int &O_SCORE, int &TIE);
int playAgain(bool &stillPlaying, char (&board)[3][3], bool &Xturn, int &X_SCORE, int &O_SCORE, int &TIE);
void endGame();

int main() { //main method
  
  bool X_TURN = true; //x's turn if true, o's turn if false
  int X_SCORE = 0;
  int O_SCORE = 0;
  int TIE = 0;
  char board[3][3];

  for (int row = 0; row < 3; row++) { //create empty board
    for (int column = 0; column < 3; column++) {
      board[row][column] = ' ';
    }
  }

  bool stillPlaying = true; //game still playing

  printBoard(stillPlaying, board, X_TURN, X_SCORE, O_SCORE, TIE);

  return 0;
}


void game(bool &stillPlaying, char (&board)[3][3], bool &Xturn, int &X_SCORE, int &O_SCORE, int &TIE) { //Actual game
  while (stillPlaying == true) { //While still playing
    
    char input[2];;
    cout << endl << "Enter the coordinate:  ";
    cin >> input;
    cout << "You entered: " << input[0] << input[1] << endl;
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

      if (board[row][column] != ' ') { //if board is already filled
	cout << "That is already filled. Try again" << endl;
	game(stillPlaying, board, Xturn, X_SCORE, O_SCORE, TIE);
      }
      else if (Xturn == true) { //if x's turn
	board[row][column] = 'X';
	if ((checkWin(stillPlaying, Xturn, board, X_SCORE, O_SCORE, TIE) == true)){ //check for win
	  cout << "X wins!" << endl;
	  X_SCORE = X_SCORE + 1;
	  playAgain(stillPlaying, board, Xturn, X_SCORE, O_SCORE, TIE); 
	  break;
	}
	if ((checkTie(stillPlaying, board, X_SCORE, O_SCORE, TIE) == true)) { //check for tie
	  cout << "It is a tie." << endl;
	  TIE = TIE + 1;
	  playAgain(stillPlaying, board, Xturn, X_SCORE, O_SCORE, TIE);
          break;
	}
	Xturn = false; //if not win or tie
	printBoard(stillPlaying, board, Xturn, X_SCORE, O_SCORE, TIE);
      }
      
      else if (Xturn == false) { //if o's turn
  	board[row][column] = 'O';
	if (checkWin(stillPlaying, Xturn, board, X_SCORE, O_SCORE, TIE) == true) { //check for win
	  cout << "O wins!" << endl;
	  O_SCORE = O_SCORE + 1;
	  playAgain(stillPlaying, board, Xturn, X_SCORE, O_SCORE, TIE); 
	  break;
	}
	Xturn = true;
	printBoard(stillPlaying, board, Xturn, X_SCORE, O_SCORE, TIE);
	//checkWin(true, false, board);
      }
    }
    else { //if improper coordinate is entered
      cout << "Enter a proper coordinate with a letter followed by a number\n" << endl;
      game(stillPlaying, board, Xturn, X_SCORE, O_SCORE, TIE);
    }
    
  }
}


void printBoard(bool &stillPlaying, char (&board)[3][3], bool &Xturn, int &X_SCORE, int &O_SCORE, int &TIE) { // print the board

  char alpha[3] = {'a', 'b', 'c'};  //https://stackoverflow.com/questions/62006349/how-to-get-an-easier-way-of-generating-the-alphabet-in-c by user '463035818_is_not_a_number'
  cout << "  1 2 3" << endl;    
  for (int row = 0; row < 3; row++) {
    cout << alpha[row] << " "; 
    for (int column = 0; column < 3; column++) {
      cout << board[row][column] << " ";
    }
    cout << endl;
  }
  game(stillPlaying, board, Xturn, X_SCORE, O_SCORE, TIE);
}


bool checkWin(bool &stillPlaying, bool &Xturn, char (&board)[3][3], int &X_SCORE, int &O_SCORE, int &TIE) { //check for a win if all coordinates on board are same
  //cout << "Nice try" << endl;
  if ((board[0][0] == board[0][1]) && (board[0][1] == board[0][2]) && board[0][1] != ' ') {
    stillPlaying = false;
    return true;
  }
  if ((board[1][0] == board[1][1]) && (board[1][1] == board[1][2]) && board[1][1] != ' ') {
    stillPlaying = false;
    return true;
  }
  if ((board[2][0] == board[2][1]) && (board[2][1] == board[2][2]) && board[2][1] != ' ') {
    stillPlaying = false;
    return true;
  }
  if ((board[0][0] == board[1][0]) && (board[1][0] == board[2][0]) && board[1][0] != ' ') {
    stillPlaying = false;
    return true;
  }
  if ((board[0][1] == board[1][1]) && (board[1][1] == board[2][1]) && board[1][1] != ' ') {
    cout << "You win " << stillPlaying << endl;
    stillPlaying = false;
    return true;
  }
  if ((board[0][2] == board[1][2]) && (board[1][2] == board[2][2]) && board[1][2] != ' ') {
    cout << "You win " << stillPlaying << endl;
    stillPlaying = false;
    return true;
  }
  if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) && board[1][1] != ' ') {
    cout << "You win " << stillPlaying << endl;
    stillPlaying = false;
    return true;
  }
  if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && board[1][1] != ' ') {
    cout << "You win " << stillPlaying << endl;
    stillPlaying = false;
    return true;
  }
  return false;
}

bool checkTie(bool &stillPlaying, char (&board)[3][3], int &X_SCORE, int &O_SCORE, int &TIE) { //Check if there is a tie
  for (int row = 0; row < 3; row++) { //for board length
    for (int column = 0; column < 3; column++) { //for board width
      if (board[row][column] == ' ') {
	return false;
      }
    }
  }
  cout << "It's a tie!" << endl;
  return true;
}

int playAgain(bool &stillPlaying, char (&board)[3][3], bool &Xturn, int &X_SCORE, int &O_SCORE, int &TIE) { //asks players if they want to play again or not
  char input;
  cout << "# of X wins: " << X_SCORE << " and # of O wins: " << O_SCORE << " and # of ties: " << TIE << endl;
  cout << "Play again? (y/n) " << endl; 
  cin >> input;

  if (input == 'y') { //if they say yes
    for (int row = 0; row < 3; row++) { // creates three rows
      for (int column = 0; column < 3; column++) {
        board[row][column] = ' '; //reset board
      }
    }
    Xturn = true;
    stillPlaying = true;
    printBoard(stillPlaying, board, Xturn,  X_SCORE, O_SCORE, TIE);

  }
  else { //if they say otherwise
    cout << "Game Over." << endl;
    endGame(); //end game
  }
  return 0;
}

void endGame() { //end game

}
