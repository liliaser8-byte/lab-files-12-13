#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("number.txt"); // відкриваємо файл для читання
    if (!fin) {
        cout << "Не вдалося відкрити файл number.txt!" << endl;
        return 1;
    }

    int num;
    long long product = 1; // змінна для добутку чисел
    bool found = false;    // прапорець для перевірки, чи є кратні 5

    while (fin >> num) { // зчитуємо числа з файлу
        if (num % 5 == 0) { // перевірка на кратність 5
            product *= num; // множимо на добуток
            found = true;
        }
    }

    fin.close(); // закриваємо файл

    if (found)
        cout << "Добуток чисел, кратних 5 = " << product << endl;
    else
        cout << "У файлі немає чисел, кратних 5." << endl;

    return 0;
}