#include <iostream>
#include <fstream>
using namespace std;

int main() {

    const int n = 4; // розмірність матриці 4x4
    double A[n][n]; // матриця дійсних чисел

    ifstream fin("matrix.txt"); // відкриваємо файл для зчитування
    if (!fin.is_open()) {
        cout << "Помилка відкриття файлу matrix.txt!" << endl;
        return 1;
    }

    // Зчитування елементів матриці з файлу
    cout << "Зчитані елементи матриці A (4x4):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fin >> A[i][j];
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }

    fin.close(); // закриваємо файл

    cout << "\nСереднє арифметичне додатних елементів кожного стовпця:\n";

    // Обчислення середнього арифметичного для кожного стовпця
    for (int j = 0; j < n; j++) {
        double sum = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (A[i][j] > 0) { // перевіряємо додатність елемента
                sum += A[i][j];
                count++;
            }
        }

        if (count > 0) {
            double average = sum / count;
            cout << "Стовпець " << j + 1 << ": " << average << endl;
        } else {
            cout << "Стовпець " << j + 1 << ": додатних елементів немає.\n";
        }
    }

    return 0;
}