#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <bitset>
#include <vector>

using namespace std;
int main() {
    SetConsoleOutputCP(CP_UTF8);
//#1.a.
//    unsigned char x = 255; //8-разрядное двоичное число 11111111
//    unsigned char maska = 1;
//    x = x & (~(maska << 4));//11110111 //сдвиг влево двоичного кода, инверсия, запись в бит 0
//    cout << int(x) << " " << x;
//1.b.
//    unsigned char x = 255; //8-разрядное двоичное число 11111111
//    unsigned char maska = 1;
//    x = x|(~(maska<<6));//11110111
//    cout << int(x) << endl;
//1.c.
//Битовые операции
    using namespace std;
    unsigned int x = 25;
    const int n = sizeof(int)*8; //=32 - количество разрядов в числе типа int
    unsigned maska = (1 << n - 1); //1 в старшем бите 32-разрядной сетки
    cout << "Начальный вид маски: " << bitset<n> (maska) << endl;
    cout << "Результат: ";
    for (int i = 1; i <= n; i++) //32 раза - по количеству разрядов:
        cout << ((x & maska) >> (n - i));
    maska = maska >> 1; //смещение 1 в маске на разряд вправо
    cout << endl;
    system ("pause");
    return 0;
}


