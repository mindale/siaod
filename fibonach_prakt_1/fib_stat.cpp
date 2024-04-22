#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;
const int maxStaticSize = 10;

void fillArray(int arr[], int n, int &size){//заполнение списка
    if (2 <= n <= 4)cout << "Введите " << n << " числа/чисел: ";
    if (n == 1) cout << "Введите число: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        size++;
    }
}

int printArray(int arrayToPrint[], int size)//Вывод спика
{
    cout << " ";
    for (int i = 0; i < size; i++)
        cout << arrayToPrint[i] << " ";
    cout << endl;
    return 0;
}

int addToArray(int staticArray[], int& size, int newNumber)//добавление нового элемента
{
    if (size >= maxStaticSize)
        return -1;
    staticArray[size] = newNumber;
    size++;
    return 0;
}

int RemoveFromArray(int staticArray[], int& size, int position){
    if (size <= 0)
        return -1;
    if (position >= size)
        return -2;
    for (int i = position; i < size - 1; i++)
        staticArray[i] = staticArray[i + 1];
    size--;
    return 0;
}

int findArray(int staticArray[], int& size, int toFinstaticArrayNumber)//Нахождение элемента
{
    for (int i = 0; i < size; i++)
        if (staticArray[i] == toFinstaticArrayNumber)
            return i;
    return -1;
}



int countArray(int& n){//Нахождение длинны числа
    int len_i = 0;
    int temp_n = n;
    while (temp_n > 0) {
        temp_n /= 10;
        len_i++;
    }
    return len_i;
}

int fibonachArray(int staticArray[], int& size){//Проврека на фибаначи и вывод индекса
    int ind = -1;
    for (int i = 0; i < size; i++) {//Пробежка по значениям цикла
        int &x = staticArray[i];
        int len_i = countArray(x);
        if (len_i >= 3) {//Условие на то, чтобы число было больше 3
            int k = 1;
            while (len_i + 1 != k) {//Цикл который перебирает значения, до тех пор, переменная k != к длинне числа
                int x1 = (x / (int)pow(10, len_i - k)) % 10;//Разделение числа на цифры
                if (len_i - k - 1 == 0)break;
                int x2 = (x / (int)pow(10, len_i - k - 1)) % 10;//Разделение числа на цифры
                int x3 = (x / (int)pow(10, len_i - k - 2)) % 10;//Разделение числа на цифры
                if (x1 + x2 == x3)ind=i;break;//Если 1ц + 2ц == 3ц, вывод
                k++;
            }
        }
    }
    return ind;
}


void dopolneniyeArray(int staticArray[], int size, int value){//Ф-ия, добавляющая входящее значение после числа фибоначи
    for(int i = fibonachArray(staticArray, size) + 2 ; i < size + 1; i++){
        staticArray[i] = staticArray[i-1];
    }
    staticArray[fibonachArray(staticArray, size) + 1] = value;
}

int RemovefibArray(int staticArray[], int& size){
    int position = fibonachArray(staticArray, size) - 1;
    if (size <= 0)
        return -1;
    if (position >= size)
        return -2;
    for (int i = position; i < size - 1; i++)
        staticArray[i] = staticArray[i + 1];
    size--;
    return 0;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int size = 0;
    int tempNumber;
    int result;
    int staticArray[maxStaticSize];// = {123, 234, 354};//


    cout << "1. Вывод массива\n"
         << "2. Добавить элемент\n"
         << "3. Удалить элемент\n"
         << "4. Найти элемент\n"
         << "5. Индекс элемента массива, цифры которого (слева направо) образуют последовательность Фибоначчи.\n"
         << "6. Вставить новое значение после Фибоначчи\n"
         << "7. Удалить элемент, стоящий перед Фибоначчи.\n"
         << "8. Заполнить массив.\n"
         << "0. Выход\n";



    char menu;
    while (true)
    {
        cout << "Введите действие: ";
        cin >> menu;
        switch (menu){
            case '1':
                printArray(staticArray, size);
                break;
            case '2':
                cout << "Введите число: ";
                cin >> tempNumber;
                if (addToArray(staticArray, size, tempNumber) == -1)
                    cout << "List full\n";
                else
                    cout << "Элемент успешно добавлен!\n";
                break;
            case '3':
                cout << "Введите позицию: ";
                cin >> tempNumber;
                switch (RemoveFromArray(staticArray, size, tempNumber))
                {
                    case 0:
                        cout << "Элемент успешно удален\n";
                        break;
                    case -1:
                        cout << "Массив пуст\n";
                        break;
                    case -2:
                        cout << "Такого элемента нет\n";
                        break;
                }
                break;
            case '4':
                cout << "Введите число: ";
                cin >> tempNumber;
                result = findArray(staticArray, size, tempNumber);
                if (result == -1)
                    cout << "Элемент не найден\n";
                else
                    cout << "Элемент" << tempNumber << "найден в позиции" << result << "\n";
                break;
            case '5':
                if (fibonachArray(staticArray, size)==-1)cout<<"В массиве нету числа Фиббоначи!" << endl;
                else cout << fibonachArray(staticArray, size) << endl;
                break;

            case '6':
                cout << "Введите число, которое хотите добавить после индекса Фибоначи:";
                cin >> tempNumber;
                dopolneniyeArray(staticArray, size, tempNumber);
                size++;
                printArray(staticArray, size);
                break;
            case '7':
                switch (RemovefibArray(staticArray, size))
                {
                    case 0:
                        cout << "Элемент перед фибоначи удален!\n";
                        break;
                    case -1:
                        cout << "Массив переполнен\n";
                        break;
                    case -2:
                        cout << "Элемент не обнаружен!\n";
                        break;
                }
                break;
            case '8':
                int n;
                cout << "Введите размер массива "; cin >> n;
                fillArray(staticArray, n, size);
                break;
            case '0':
                return 0;
                break;
            default:
                cout << "Неверный ввод!\n";
                cout << "1. Вывод массива\n"
                     << "2. Добавить элемент\n"
                     << "3. Удалить элемент\n"
                     << "4. Найти\n"
                     << "5. Найти индекс элемента массива, цифры которого упорядочены по возрастанию\n"
                     << "6. Вставить новый элемент после элемента, цифры которого упорядочены по возрастанию\n"
                     << "7. Удалить число, которое расположено перед числом, цифры которого упорядочены по возрастанию\n"
                     << "0. Выход\n"
                     << "Выберите действие: ";
                break;
        }
    }


    return 0;
}
