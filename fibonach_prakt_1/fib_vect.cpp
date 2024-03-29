#include <iostream>
#include <cmath>
#include <list>
#include <windows.h>
#include <vector>

using namespace std;
const int maxStaticSize = 10;

bool fibArray(int len_i, int i) {//Ф-ия нахождения фиб.
    int k = 1;
    while (len_i + 1 != k) {//Цикл который перебирает значения, до тех пор, переменная k != к длинне числа
        int x1 = (i / (int)pow(10, len_i - k)) % 10;//Разделение числа на цифры
        if (len_i - k - 1 == 0)return false;
        int x2 = (i / (int)pow(10, len_i - k - 1)) % 10;//Разделение числа на цифры
        int x3 = (i / (int)pow(10, len_i - k - 2)) % 10;//Разделение числа на цифры
        if (x1 + x2 == x3)return true;//Если 1ц + 2ц == 3ц, вывод
        k++;
    }
    return false;
}

void fillArray(int arr[], int n){//заполнение списка
    for(int i = 0; i < n; i++){
        cout << "Input value: ";
        cin >> arr[i];
    }
}

int printArray(vector<int>& arrayToPrint, int& size)//Вывод спика
{
    cout << " ";
    for (int i = 0; i < size; i++)
        cout << arrayToPrint[i] << " ";
    cout << endl;
    return 0;
}

int VectorArray(vector<int>& staticArray, int& size, int newNumber)//добавление нового элемента
{
    staticArray.push_back(newNumber);
    size++;
    return 0;
}

int RemoveFromArray(vector<int>& staticArray, int& size, int position)//удаление элемента
{
    if (size <= 0)
        return -1;
    if (position >= size)
        return -2;
    for (int i = position; i < size - 1; i++)
        staticArray[i] = staticArray[i + 1];
    size--;
    return 0;
}

int findArray(vector<int>& staticArray, int& size, int toFinstaticArrayNumber)//Нахождение элемента
{
    for (int i = 0; i < size; i++)
        if (staticArray[i] == toFinstaticArrayNumber)
            return i;
    return -1;
}


int countArray(int& n){//Нахождение длинны числа
    int len_i = 0;
    while (n > 0) {
        n /= 10;
        len_i++;
    }
    return len_i;
}

int fib2Array(vector<int>& staticArray, int& size){//Проврека на фибаначи и вывод индекса
    int ind = 0;
    for (int i = 0; i < size; i++) {//Пробежка по значениям цикла
        int x = staticArray[i];
        // cout << i << endl << x;
        // cout << x << " ";
        int len_i = countArray(x);
        // cout << len_i;
        if (len_i >= 3) {//Условие на то, чтобы число было больше 3
            if (fibArray(len_i, x)) {//Проврека на фибоначи
                // int size_sp = sizeof(staticArray)/sizeof(staticArray[0]);//Нахождение размера списка
                // for(int l = 0; l < size; l++){
                //     if (staticArray[l] == staticArray[i]){//Нахождение индекса числа фибоначи
                // ind = l;//присвоение индекса переменной
                // break;
                // }
                ind = i;
            }
        }
    }
    return ind;
}

void dopolneniyeArray(vector<int>& staticArray, int& size, int value){
//    if (fib2Array(staticArray, size) == 0) return 0;
//    cout << "FIB Number is "<< fib2Array(staticArray, size);
    size++;
//    staticArray.push_back(value);
    staticArray.insert(staticArray.begin() + fib2Array(staticArray, size) + 1, value);
//    return 0;
}


int main() {
    // int staticArray[] = {123, 232, 3545, 12358};//Список с числами
    vector<int> staticArray;
    SetConsoleOutputCP(CP_UTF8);
    int size = 0;
    int tempNumber;
    int result;
//    int staticArray[maxStaticSize];// = {123, 234, 354};//
    // cout << staticArray;
    // for(int i : staticArray)
    // fillArray(staticArray, size);


    cout << "1. Вывод массива\n"
         << "2. Добавить элемент\n"
         << "3. Удалить элемент\n"
         << "4. Найти элемент\n"
         << "5. Индекс элемента массива, цифры которого (слева направо) образуют последовательность Фибоначчи.:\n"
         << "6. Вставить новый элемент после элемента, цифры которого упорядочены по возрастанию\n"
         << "7. Удалить число, которое расположено перед числом, цифры которого упорядочены по возрастанию\n"
         << "0. Выход\n";



    char menu;
    while (true)
    {
        cout << "Введите действие: ";
        cin >> menu;
        switch (menu){
            case '1':
                cout << "Кол-во элементов:" << size << endl;
                cout << "Элементы массива:";
                printArray(staticArray, size);
                break;
            case '2':
                cout << "Введите число: ";
                cin >> tempNumber;
                if (VectorArray(staticArray, size, tempNumber) == -1)
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
                cout << fib2Array(staticArray, size) << endl;
                break;

            case '6':

                if (fib2Array(staticArray, size) == 0) cout << "Числа Фибоначи нету!";
                else{
                    cout << "Введите число, которое хотите добавить после индекса Фибоначи:";
                    cin >> tempNumber;
                    dopolneniyeArray(staticArray, size, tempNumber);
                    printArray(staticArray, size);
                }
                break;
            case '7':
                switch (RemoveFromArray(staticArray, size, fib2Array(staticArray, size)-1 ))
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
                     << "0. выход\n"
                     << "Выберите действие: ";
                break;
        }
    }


    return 0;
}
