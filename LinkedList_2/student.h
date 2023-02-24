#include <iostream>
#include <cstring>

using namespace std;

class Student {

 public:
  Student();
  void setFirst(char *first);
  char *getFirst();
  void setLast(char *last);
  char *getLast();
  void setId(int id);
  int getId();
  void setGpa(float gpa);
  float getGpa();


 private:
  char *firstName;
  char *lastName;
  int id;
  float gpa;
};
