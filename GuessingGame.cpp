#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
  bool playing = true; //Is using playing the game
  
  while (playing) { //if user is playing game
    int count = 0;
    int correctAnswer;
    bool gotAnswer = true;
    srand(time(NULL)); //seed for random number
    correctAnswer = rand() % 101; //random number from 0-100
    //cout << correctAnswer; 

    while (gotAnswer == true) { //if user did not get answer yet
      int userInput;
      cout << "\nEnter guess:  ";
      cin >> userInput; //take user input
      count++ ;

      if (userInput < correctAnswer) { //if input is less than number
          cout << "Input is less than secret number. Try again.";
      }
      else if (userInput > correctAnswer) { //if input is greater than number
          cout << "Input is greater than secret number. Try again.";
      }
      else { //input correct number
	  cout << "Correct! It took you " << count << " guesses. ";
	  gotAnswer = false; //don't go back to loop
	  char keepPlaying;
	  cout << "Do you want to continue playing (y/n)?";
	  cin >> keepPlaying;

	  if (keepPlaying == 'y') { //if user says yes to play, keep playing
	      playing = true;
	  }
	  else { //if user says no, stop.
	      cout << "Ok. Bye.";
	      playing = false;
	  }
      }
    }
  }
   return 0;
}
