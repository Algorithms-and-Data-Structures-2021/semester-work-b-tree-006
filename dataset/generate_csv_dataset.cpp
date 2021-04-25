#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <thread>


using namespace std;


// Определите путь до проекта
const string path_to_project = "C:\\Users\\username\\acd-projects\\semester-work-b-tree-006";

// Максимальное значение элементов генерации
const int max_rand = 5000;

// Наборы данных(кол-во элементов в каждом наборе)
int sizes_dataset[10] = {100, 500, 1000, 10000, 50000, 250000,
                         500000, 1000000, 2500000, 5000000};

int main() {

  for (int size_dataset : sizes_dataset) {
    for (int i = 1; i <= 10; i++) {
      
      // функция при помощи которой при каждом выполнении программы генерируются случайные числа      
      srand(static_cast<unsigned int>(time(0)));
      
      string PATH = path_to_project + "\\dataset\\data\\add\\0" + to_string(i) + "\\";

      string filename = to_string(size_dataset) + ".txt";

      ofstream fout(PATH + filename);

      if (!fout.is_open()) {
        cout << "open error" << endl;
        return -1;
      }

      for (int j = 0; j < size_dataset; j++) {
        fout << (rand() * rand()) % max_rand + 1 << endl;
      }

      fout.close();
      
      this_thread::sleep_for(1000ms);


      srand(static_cast<unsigned int>(time(0)));

      string PATH1 = path_to_project + "\\dataset\\data\\search\\0" + to_string(i) + "\\";

      string filename1 = to_string(size_dataset) + ".txt";

      ofstream fout1(PATH1 + filename1);

      if (!fout1.is_open()) {
        cout << "open error" << endl;
        return -1; // если файл не открылся, выводим ошибку
      }

      for (int k = 0; k < size_dataset; k++) {
        fout1 << (rand() * rand()) % max_rand + 1 << endl;
      }

      fout1.close();
      
      this_thread::sleep_for(1000ms);
      

      srand(static_cast<unsigned int>(time(0)));

      string PATH2 = path_to_project + "\\dataset\\data\\remove\\0" + to_string(i) + "\\";

      string filename2 = to_string(size_dataset) + ".txt";

      ofstream fout2(PATH2 + filename2);

      if (!fout2.is_open()) {
        cout << "open error" << endl;
        return -1;
      }

      for (int k1 = 0; k1 < size_dataset; k1++) {
        fout2 << (rand() * rand()) % max_rand + 1 << endl;
      }

      fout2.close();
      
      this_thread::sleep_for(1000ms);
    }
    cout << size_dataset << " elements generated" << "\n";
  }
  return 0;
}
