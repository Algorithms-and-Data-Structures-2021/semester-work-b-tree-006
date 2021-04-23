#include <iostream>

#include "data_structure.hpp"

using namespace std;
using namespace itis;

int main() {
  BTree tree(50);
  for (int i = 1; i <= 10; i++) {
    tree.insert(i);
  }
  tree.remove(5);
  tree.traverse();
  cout << "\n" <<bool(tree.search(5));
}