#include <bits/stdc++.h>
#include <stdlib.h>
#include <cstdlib> 
#include <iostream>
#include "Hash.h"

using namespace std;
 

Hash::Hash(int V, list<int> *table)
{
    this->size = V;
    table = new list<int>[size];
}

int Hash::hashFunction(int x) {
  return (x % size);
}

int Hash::insertItem(int key, list<int> *table)
{
  int index = hashFunction(key);
  table[index].push_back(key);
  return 0;
}
 
int Hash::deleteItem(int key, list<int> *table)
{
  int index = hashFunction(key); 
  list <int> :: iterator i;
  for (i = table[index].begin(); i != table[index].end(); i++) {
    if (*i == key) {
      break;
    }
  }
  if (i != table[index].end()) {
    table[index].erase(i);
  }
  return 0;
}
 

int Hash::displayHash(list<int> *table) {
  for (int i = 0; i < size; i++) {
    cout << i;
    for (auto x : table[i]) {
      cout << " --> " << x;
    }
    cout << endl;
  }
  return 0;
}

