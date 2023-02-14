#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
#include "Hash.h"

using namespace std;

int main()
{
  add();
  return 0;
}


void add() {
  int a[10];
  for (int i = 0; i < 10; i++) {
    a[i] = rand() % 101;
  }
  int n = sizeof(a)/sizeof(a[0]);

  Hash h(100) = new Hash();   
  
  for (int i = 0; i < n; i++) {
    h->insertItem(a[i]);
  }
  
  h->deleteItem(12);
  H-> displayHash();
}
