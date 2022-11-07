#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>

using namespace std;

struct Student {
  char firstName[10];
  char lastName[10];
  int studentId;
  float gpa;
};

void add(vector<Student*> &Vector);
void del(vector<Student*> &Vector);
void print(vector<Student*> &Vector);


int main() {
  vector<Student*> Vector;
  bool playing = true;

  while (playing == true) {
    cout << "What do you want to do: ADD, DELETE, PRINT, or QUIT? " << endl;
    char userInput[10];
    cin.get(userInput, 10);

    if (strcmp(userInput, "ADD")==0) {
      cout << "adding" << endl;
      add(Vector);
    }
    else if (strcmp(userInput, "DELETE")==0) {
      cout << "deleting" << endl;
      del(Vector);
    }
    else if (strcmp(userInput, "PRINT")==0) {
      cout << "printing" << endl;
      print(Vector);
    }
    else if (strcmp(userInput, "QUIT")==0) {
      cout << "quiting" << endl;
      playing = false;
    }
    else {
      cout << "You can only ent+er the following commands: ADD, DELETE, PRINT, QUIT" << endl;
    }
  }
  
  return 0;
}

void add(vector<Student*> &Vector) {
  Student* student = new Student;
  cout << "First Name: " << endl;
  cin >> student -> firstName;
  cin.ignore(10, '\n');
  cout << "Last Name: " << endl;
  cin >> student -> lastName;
  cin.ignore(10, '\n');
  cout << "Student ID: " << endl;
  cin >> student -> studentId;
  cin.ignore(6, '\n');
  cout << "GPA: " << endl;
  cin >> student -> gpa;
  cin.ignore(4, '\n');

  Vector.push_back(student);  
}

void print(vector<Student*> &Vector) {
  for (vector<Student*>::iterator i = Vector.begin(); i != Vector.end(); i++) { //help recieved from Shreya Suresh
    cout << (*i) -> firstName << " ";
    cout << (*i) -> lastName << ",    ";
    cout << (*i) -> studentId << ",   ";
    //rounds gpa to 2 places
    cout << fixed << setprecision(2) << (*i) -> gpa << endl;
    
  }
}

void del(vector<Student*> &Vector) {
  cout << "Please enter student ID of the student you wish to remove." << endl;
  int num;
  cin >> num;
  for (vector<Student*>::iterator i = Vector.begin(); i !=Vector.end(); i++) {
    if ((*i) -> studentId == num) {
      delete Vector[i-Vector.begin()];
      Vector.erase(i);
      break;
    }
    else {
      cout << "Student ID is not found. Please try again later. " << endl;
    }
			       
  }
}

