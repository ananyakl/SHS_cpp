#include <iostream>
#include <string.h>
#include <cctype>
#include <cstring>

using namespace std;

//char[] editInput();


int editInput() {
  char userInput[80];
  char editedWord[80];
  
  cout << "Input word" << endl;
  cin.get(userInput, 80);

  
  //int countOrig = 0;
  //int countMod = 0;

  for (int i = 0; i < strlen(userInput); i++) { //copies a word
    //cout << strlen(userInput);
    if (userInput[i] != '\0') {
      userInput[i] = tolower(userInput[i]);
      if ( (47<int(userInput[i])<58) || (96<int(userInput[i]<123)) ) {
        cout << userInput[i];
        //countOrig++;
      }
    }
    else {
      editedWord[i] = '\0';
    }
  }

  //if 

  //cout << userInput << endl;
  //cout << editedWord << endl;
  return 0 ;

}

int main()
{
  //int editInput();
  editInput();
  //cout << "Edited Word is: ";
}

