#include <iostream>
#include <random>
#include <fstream>
#include <cmath>
#include <time.h>

using namespace std;

void randomFile(int ln)
{
    random_device rd;
    mt19937 gen(rd());

    int *arr = new int[ln];
    for (int i = 0; i < ln; ++i)
    {
        arr[i] = i;
    }

    int buffer, rd_index;
    for (int i = 0; i < ln; ++i)
    {
        rd_index = rd() % ln;
        buffer = arr[rd_index];
        arr[rd_index] = arr[i];
        arr[i] = buffer;
    }

    ofstream A;
    A.open("input.txt");
    A << arr[0];
    for (int i = 1; i < ln * 0.75; ++i)
    {
        A << '\n'
          << arr[i];
    }
    A.close();
    delete[] arr;
};

void bit_sort(int ln)
{
    ifstream A;
    A.open("input.txt");

    int arr_ln = ceil(ln / 8.0);
    int num;
    unsigned char bit_one = 1;
    unsigned char *bit_array = new unsigned char[arr_ln];
    for (int i = 0; i < arr_ln; ++i) {
        bit_array[i] = 0;
    }

    while (!A.eof())
    {
        A >> num;
        bit_array[((arr_ln - 1) - num / 8)] = bit_array[((arr_ln - 1) - num / 8)] | (bit_one << (num % 8));
    }
    A.close();

    ofstream B;
    B.open("B_output.txt");

    bool is_written = false;

    for (int i = 0; i < ln; ++i) {
        if (bit_array[((arr_ln - 1) - i / 8)] & (bit_one << (i % 8))) {
            if (is_written) {
                B << "\n";
            }
            is_written = true;
            B << i;
        }
    }
    B.close();

    double size = sizeof(bit_array[0]) * arr_ln / 1024.0;
    printf("Объём памяти, занимаемый битовым массивом: %f Кбайт", size);
    delete[] bit_array;
}

int main()
{
    const int ln = 10;
    randomFile(ln);
    clock_t start = clock();
    bit_sort(ln);
    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;
    cout << endl << "Время работы программы: " << duration << " секунд" << endl;
    return 0;
}