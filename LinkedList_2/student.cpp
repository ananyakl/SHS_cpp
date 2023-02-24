#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

void Student::setFirst(char* first) {
  firstName = new char[30];
  strcpy(firstName, first);
}

char* Student::getFirst() {
  return firstName;
}

void Student::setLast(char* last) {
  lastName = new char[30];
  strcpy(lastName, last);
}

char* Student::getLast() {
  return lastName;
}

void Student::setId(int i) {
  id = i;
}

int Student::getId() {
  return id;
}

void Student::setGpa(float g) {
  gpa = g;
}

float Student::getGpa() {
  return gpa;
}
