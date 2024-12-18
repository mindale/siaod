//2b
#include <windows.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    // Инициализация переменных
    unsigned long long bitArray = 0; // Битовый массив в виде 64-битного числа
    vector<int> inputNumbers;       // Вводимая последовательность чисел
    int number;

    // Ввод чисел пользователем
    cout << "Введите до 64 чисел от 0 до 63 (для завершения введите -1):" << endl;
    while (inputNumbers.size() < 64) {
        cin >> number;
        if (number == -1) break; // Завершение ввода
        if (number < 0 || number > 63) {
            cout << "Число вне диапазона. Попробуйте снова." << endl;
            continue;
        }
        inputNumbers.push_back(number);
        bitArray |= (1ULL << number); // Установка бита в 1 для введённого числа
    }

    // Вывод битового массива
    cout << "Битовый массив: ";
    for (int i = 63; i >= 0; --i) {
        cout << ((bitArray >> i) & 1);
    }
    cout << endl;

    // Сортировка и вывод отсортированной последовательности
    cout << "Отсортированная последовательность: ";
    for (int i = 0; i < 64; ++i) {
        if ((bitArray >> i) & 1) { // Проверка, установлен ли бит
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
