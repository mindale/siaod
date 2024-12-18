//2a
#include <windows.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    // Инициализация переменных
    unsigned char bitArray = 0; // Битовый массив в виде unsigned char (8 бит)
    vector<int> inputNumbers;  // Вводимая последовательность чисел
    int number;

    // Ввод чисел пользователем
    cout << "Введите до 8 чисел от 0 до 7 (для завершения введите -1):" << endl;
    while (inputNumbers.size() < 8) {
        cin >> number;
        if (number == -1) break; // Завершение ввода
        if (number < 0 || number > 7) {
            cout << "Число вне диапазона. Попробуйте снова." << endl;
            continue;
        }
        inputNumbers.push_back(number);
        bitArray |= (1 << number); // Установка бита в 1 для введённого числа
    }

    // Вывод битового массива
    cout << "Битовый массив: ";
    for (int i = 7; i >= 0; --i) {
        cout << ((bitArray >> i) & 1);
    }
    cout << endl;

    // Сортировка и вывод отсортированной последовательности
    cout << "Отсортированная последовательность: ";
    for (int i = 0; i < 8; ++i) {
        if ((bitArray >> i) & 1) { // Проверка, установлен ли бит
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
