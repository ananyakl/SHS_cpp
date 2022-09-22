#include <iostream>
#include <string.h>
#include <cctype>
#include <cstring>

using namespace std;

int editInput() {
  char userInput[80]; //initialize variables
  char editedWord[80];
  bool Palindrome = true;
  
  cout << "Input word" << endl;
  cin.get(userInput, 80);

  
  int countOrig = 0;

  for (int i = 0; i < strlen(userInput); i++) { //copies only lower case and numbers
    if (userInput[i] != '\0') {
      userInput[i] = tolower(userInput[i]);
      if ( ((int(userInput[i])>47)&&(int(userInput[i])<58)) || ((int(userInput[i])>96)&&(int(userInput[i])<123))) { //checks for only numbers and letters
	editedWord[countOrig] = userInput[i];
	countOrig++;
      }
    }
  }

  for (int j = 0; j < strlen(editedWord); j++) { //check if same front and back, check if palindrome
    if (editedWord[j] != editedWord[strlen(editedWord) - j - 1]) {
      Palindrome = false;
    }
  }

  if (Palindrome == true) { //if palindrome, say so. Otherwise say it's not a palindrome.
    cout << "It is a palindrome.";
  }
  else {
    cout << "It is not a palindrome.";
  }
  
  return 0 ;

}

int main() //main
{
  editInput();
}

