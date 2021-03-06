#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string>       // string, stoi
#include <string_view>  // string_view
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds

// подключаем вашу структуру данных
#include "btree.hpp"

using namespace std;
using namespace itis;

// Определите путь до проекта
const string path_to_project = "C:\\Users\\username\\acd-projects\\semester-work-b-tree-006";

// абсолютный путь до набора данных и папки проекта
static const auto kDatasetPathAdd = path_to_project + "\\dataset\\data\\add\\";
static const auto kDatasetPathSearch = path_to_project + "\\dataset\\data\\search\\";
static const auto kDatasetPathRemove = path_to_project + "\\dataset\\data\\remove\\";

//100, 500, 1000, 10000, 50000, 250000, 500000, 1000000, 2500000, 5000000
static const int kSizeDataset = 500;

int main() {
  // работа с набором данных
  string path = kDatasetPathAdd;

  string path2 = kDatasetPathSearch;

  string path3 = kDatasetPathRemove;

  for (int i = 1; i <= 10; i++) { // для каждого из 10 наборов(папки: 01, 02, 03 и т.д.)
    auto input_file = ifstream(path + "0" + to_string(i) + "\\" + to_string(kSizeDataset) + ".txt");
    if (!input_file.is_open()) {
      cout << "open " << path + "0" + to_string(i) + "\\" + to_string(kSizeDataset) + ".txt" << " error!" << endl;
      return -1; // если файл не открылся, выводим ошибку
    }

    BTree b_tree(50); //создаем B-дерево со степенью t=50

    const auto time_point_before = chrono::steady_clock::now(); // запоминаем время начала операции

    while(!input_file.eof()){
      int temp;
      input_file >> temp;
      b_tree.insert(temp); // заполняем пустое дерево данными из файла
    }

    const auto time_point_after = chrono::steady_clock::now(); // запоминаем время конца операции

    // измеряем разницу по времени
    const auto time_diff = time_point_after - time_point_before;
    // переводим время в наносекунды
    const long long time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();

    cout << "Time elapsed to adding (ns): " << time_elapsed_ns << '\n';

    /* далее те же самые действия выполняется для операции поиска и удаления, в которых
     * используется уже созданное дерево, заполненное первым набором.
     */
    //================================================================

    auto input_file2 = ifstream(path2 + "0" + to_string(i) + "\\" + to_string(kSizeDataset) + ".txt");
    if (!input_file2.is_open()) {
      cout << "open " << i << " error!" << endl;
      return -1;
    }

    const auto time_point_before2 = chrono::steady_clock::now();

    while(!input_file2.eof()){
      int temp;
      input_file2 >> temp;
      b_tree.search(temp);
    }

    const auto time_point_after2 = chrono::steady_clock::now();

    // переводим время в наносекунды
    const auto time_diff2 = time_point_after2 - time_point_before2;
    const long long time_elapsed_ns2 = chrono::duration_cast<chrono::nanoseconds>(time_diff2).count();

    cout << "Time elapsed to searching (ns): " << time_elapsed_ns2 << '\n';

    //==================================================================

    auto input_file3 = ifstream(path3 + "0" + to_string(i) + "\\" + to_string(kSizeDataset) + ".txt");
    if (!input_file3.is_open()) {
      cout << "open " << i << " error!" << endl;
      return -1;
    }

    const auto time_point_before3 = chrono::steady_clock::now();

    while(!input_file3.eof()){
      int temp;
      input_file3 >> temp;
      b_tree.remove(temp);
    }

    const auto time_point_after3 = chrono::steady_clock::now();

    // переводим время в наносекунды
    const auto time_diff3 = time_point_after3 - time_point_before3;
    const long long time_elapsed_ns3 = chrono::duration_cast<chrono::nanoseconds>(time_diff3).count();
    cout << "Time elapsed to removing (ns): " << time_elapsed_ns3 << '\n';

    // каждый проход выводится после нажатия любой клавиши(раскомментируйте по желанию)
    // system("pause");
  }
  return 0;

}
