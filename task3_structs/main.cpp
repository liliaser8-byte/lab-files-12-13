#include <iostream>
#include <string>
#include <fstream>   // для роботи з файлами
using namespace std;

// Структура Zodiak
struct Zodiak {
    string fullname;   // Прізвище і ім'я
    string sign;       // Знак Зодіаку
    int birth[3];      // Дата народження: день, місяць, рік
};

// Функція для сортування масиву за місяцем народження
void sortByMonth(Zodiak arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i].birth[1] > arr[j].birth[1]) {
                Zodiak temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Функція для виведення людей за місяцем народження (на екран і у файл)
void printByMonth(Zodiak arr[], int size, int month, ofstream &fout) {
    bool found = false;
    fout << "\nРезультати пошуку (місяць " << month << "):\n";
    cout << "\nРезультати пошуку (місяць " << month << "):\n";

    for (int i = 0; i < size; i++) {
        if (arr[i].birth[1] == month) {
            cout << "Ім'я: " << arr[i].fullname
                 << ", Знак: " << arr[i].sign
                 << ", Дата народження: "
                 << arr[i].birth[0] << "."
                 << arr[i].birth[1] << "."
                 << arr[i].birth[2] << endl;

            fout << "Ім'я: " << arr[i].fullname
                 << ", Знак: " << arr[i].sign
                 << ", Дата народження: "
                 << arr[i].birth[0] << "."
                 << arr[i].birth[1] << "."
                 << arr[i].birth[2] << endl;

            found = true;
        }
    }
    if (!found) {
        cout << "Людей, народжених у цьому місяці, немає." << endl;
        fout << "Людей, народжених у цьому місяці, немає." << endl;
    }
}

int main() {
    const int SIZE = 8;
    Zodiak people[SIZE];

    ofstream fout("results.txt"); // відкриваємо файл для запису
    if (!fout.is_open()) {
        cout << "Помилка відкриття файлу results.txt!" << endl;
        return 1;
    }

    // Введення даних
    for (int i = 0; i < SIZE; i++) {
        cout << "Введіть дані для людини " << i + 1 << ":\n";
        cout << "Прізвище і ім'я: ";
        getline(cin, people[i].fullname);
        cout << "Знак Зодіаку: ";
        getline(cin, people[i].sign);
        cout << "Дата народження (день місяць рік через пробіл): ";
        cin >> people[i].birth[0] >> people[i].birth[1] >> people[i].birth[2];
        cin.ignore();

        //  Записуємо у файл
        fout << people[i].fullname << ", " << people[i].sign << ", "
             << people[i].birth[0] << "." << people[i].birth[1] << "." << people[i].birth[2] << endl;
    }

    // Сортування за місяцем народження
    sortByMonth(people, SIZE);
    fout << "\n=== Відсортований список за місяцем народження ===\n";
    for (int i = 0; i < SIZE; i++) {
        fout << people[i].fullname << ", " << people[i].sign << ", "
             << people[i].birth[0] << "." << people[i].birth[1] << "." << people[i].birth[2] << endl;
    }

    // Введення місяця для пошуку
    int searchMonth;
    cout << "\nВведіть номер місяця для пошуку: ";
    cin >> searchMonth;

    // Виведення результатів пошуку
    printByMonth(people, SIZE, searchMonth, fout);

    fout.close(); //  закриваємо файл

    cout << "\nДані збережено у файлі results.txt " << endl;

    return 0;
}
