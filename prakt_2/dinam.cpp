#include <iostream>
#include <windows.h>
#include <ctime>
using namespace std;
void printArray(int** Array, int row, int column){
    for (int i = 0; i < row; i++) {
        for (int i1 = 0; i1 < column; i1++) {
            cout << Array[i][i1] << " ";
        }
        cout <<"\n";
    }
}
int minpobArray(int** d, int row, int column){
    int sum_d = 0;
    for (int k = 0; k < column; ++k) {
        int m = d[k][column-1-k];
        for (int l = column-k; l < column; ++l) {
            sum_d += d[k][l];
        }
        sum_d += m;
    }
    return sum_d;
}
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    srand(time(0));
    int userinput;
    int column;//ряд, столбец
    char menu;
    cout << "Введите размер квадратной матрицы: \n";
    cin >> column;

    int **Array = new int* ;
    for (int i = 0; i < column; i++) {
        Array[i] = new int[column];
    }

    cout << "Выберите способ заполнения массива:\n"
         << "1 Вручную\n"
         << "2 Случайно\n";
    while (true) {
        cin >> userinput;
        if (userinput == 1) {
            cout << "Вводите массив\n";
            for (int i = 0; i < column; i++) {
                for (int i1 = 0; i1 < column; i1++) {
                    cin >> Array[i][i1];
                }
            }
            cout << "Массив успешно введен\n";
            break;
        }
        if (userinput == 2) {
            int end = 10, start = 0;
            for (int i = 0; i < column; i++) {
                for (int i1 = 0; i1 < column; i1++) {
                    Array[i][i1] = rand() % (end - start + 1) + start;
                }
            }
            cout << "Массив успешно сгенерирован\n";
            break;
        }
    }
    cout << "1 Вывести Массив\n"
         << "2 Найти минимальное значение среди элементов, расположенных над побочной диагональю.\n";
    while (true) {
        cout <<"Выберите действие : \n";
        cin >> menu;
        switch (menu) {
            case '1':
                printArray(Array, column, column);
                break;

            case '2':
                cout << minpobArray(Array, column, column) << endl;
                break;
        }
    }

}