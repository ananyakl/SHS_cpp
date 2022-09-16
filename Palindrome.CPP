#include <iostream>
#include <string.h>

using namespace std;

char[] editInput();

int main()
{
  cout << "Edited Word is: " << editInput();
}


char[] editInput() {
    char userInput[80];
  char editedWord[80];
  cin.get(userInput, 20);
  cin.get();


  int count = 0;
  for (int i = 0; i < 80; i++) {
    if (userInput[i] != '\0') {
      editedWord[count] = userInput[count];
      count++;
    }
    else {
      editedWord[i] = '\0'
    }
  }

  cout << userInput << endl;
  cout << editedWord << endl;
  return editedWord;

}
