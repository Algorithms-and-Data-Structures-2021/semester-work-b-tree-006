#include <iostream>

#include "data_structure.hpp"

using namespace std;
using namespace itis;

int main() {
  // Создаем В-дерево с степенью t=50
  BTree tree(50);

  // Добавляем ключи 1...10
  for (int i = 1; i <= 10; i++) {
    tree.insert(i);
  }

  // Удаляем ключ со значением 5
  tree.remove(5);

  // Проходимся по В-дереву (ключи выводятся в консоль)
  tree.traverse();

  // Выводим в консоль результат поиска ключа(1-есть в дереве, 0 - нет)
  cout << "\n" <<bool(tree.search(5));
}