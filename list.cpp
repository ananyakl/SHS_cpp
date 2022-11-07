//Student List
//Add and remove students from list
//Ananya lanka

#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>

using namespace std;

struct Student { //creating a Student struct
  char firstName[10];
  char lastName[10];
  int studentId;
  float gpa;
};

void add(vector<Student*> &Vector);
void del(vector<Student*> &Vector);
void print(vector<Student*> &Vector);
void askQuestion(vector<Student*> &Vector);

int main() {
  vector<Student*> Vector; //creating Student Vector
  bool playing = true;
  
  askQuestion(Vector);
  cout << "Done.  " << endl;
    
  return 0;
}

void askQuestion(vector<Student*> &Vector) { //asks user what they want to do 
    cout << "What do you want to do: ADD, DELETE, PRINT, or QUIT? " << endl; 
    char userInput[10];
    cin >> userInput;

    if (strcmp(userInput, "ADD")==0) { //if user inputs 'ADD'
      cout << "adding" << endl;
      add(Vector);
    }
    else if (strcmp(userInput, "DELETE")==0) { //if user inputs 'DELETE'
      cout << "deleting" << endl;
      del(Vector);
    }
    else if (strcmp(userInput, "PRINT")==0) { //if user inputs 'PRINT'
      cout << "printing" << endl;
      print(Vector);
    }
    else if (strcmp(userInput, "QUIT")==0) { //if user inputs 'QUIT'
      cout << "quiting" << endl;
    }
    else {
      cout << "You can only enter the following commands: ADD, DELETE, PRINT, QUIT" << endl;
    }

}

void add(vector<Student*> &Vector) { //add student to vector
  Student* student = new Student; //add new student object
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
  askQuestion(Vector);
}

void print(vector<Student*> &Vector) { //print all the students
  for (vector<Student*>::iterator i = Vector.begin(); i != Vector.end(); i++) { // for length of vector, print student and information about studnet//code and help for all iterations rceived from Shreya Suresh
    cout << (*i) -> firstName << " ";
    cout << (*i) -> lastName << ",    ";
    cout << (*i) -> studentId << ",   ";
    //rounds gpa to 2 places
    cout << fixed << setprecision(2) << (*i) -> gpa << endl;  
  }
  askQuestion(Vector);
}

void del(vector<Student*> &Vector) { //find student number and delete, else not found
  cout << "Please enter student ID of the student you wish to remove." << endl;
  int num;
  cin >> num;
  for (vector<Student*>::iterator i = Vector.begin(); i !=Vector.end(); i++) { //for length of vector
    if ((*i) -> studentId == num) { //if student ID is found
      delete Vector[i-Vector.begin()]; //remove them
      Vector.erase(i);
      break;
    }
    else { //else student id is not found
      cout << "Student ID is not found. Please try again later. " << endl;
    }
			       
  }
  askQuestion(Vector);
}
