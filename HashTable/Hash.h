#ifndef HASH_H
#define HASH_H
#include <iostream>
#include <bits/stdc++.h>
#include <cstring>

using namespace std;

class Hash { //https://www.geeksforgeeks.org/c-program-hashing-chaining/

  int size; //size of list
  list<int> *table;

  public:
    Hash(int V);  // Constructor
    int insertItem(int x, list<int> *table);
    int deleteItem(int key, list<int> *table);
    int hashFunction(int x);
    int displayHash(list<int> *table);
};

#endif
