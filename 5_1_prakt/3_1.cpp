#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <bitset>
#include <ctime>
#include <windows.h>

using namespace std;

const int MAX_MEMORY = 1024 * 1024;  // 1 МБ
const int BATCH_SIZE = MAX_MEMORY / sizeof(int) + 1;  // Количество чисел в 1 МБ

// Функция для чтения данных из файла порциями
vector<int> read_batch(ifstream& infile, int batch_size) {
    vector<int> batch;
    int num;
    while (batch.size() < batch_size && infile >> num) {
        batch.push_back(num);
    }
    return batch;
}

// Функция для сортировки и записи порции данных в промежуточный файл
void sort_and_write_batch(const vector<int>& batch, int batch_num) {
    vector<int> sorted_batch = batch;
    sort(sorted_batch.begin(), sorted_batch.end());  // Сортировка порции
    string filename = "batch_" + to_string(batch_num) + ".txt";
    ofstream outfile(filename);
    for (int num : sorted_batch) {
        outfile << num << endl;  // Записываем отсортированную порцию в файл
    }
}

// Функция для слияния отсортированных файлов
void merge_sorted_files(int num_batches, const string& output_filename) {
    vector<ifstream> files(num_batches);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

    // Открытие всех промежуточных файлов и помещение в кучу их первых элементов
    for (int i = 0; i < num_batches; ++i) {
        string filename = "batch_" + to_string(i) + ".txt";
        files[i].open(filename);
        int num;
        if (files[i] >> num) {
            min_heap.push({num, i});
        }
    }

    // Открытие выходного файла
    ofstream outfile(output_filename);

    // Слияние всех файлов
    while (!min_heap.empty()) {
        auto [min_val, file_index] = min_heap.top();
        min_heap.pop();
        outfile << min_val << endl;

        int next_num;
        if (files[file_index] >> next_num) {
            min_heap.push({next_num, file_index});
        }
    }

    // Закрытие файлов
    for (int i = 0; i < num_batches; ++i) {
        files[i].close();
    }
//    cout << "Размер битового массива: " << sizeof(files) << endl;
}

// Основная функция сортировки
void external_sort(const string& input_filename, const string& output_filename) {
    ifstream infile(input_filename);
    int batch_num = 0;

    // Чтение и сортировка порций данных
    while (!infile.eof()) {
        vector<int> batch = read_batch(infile, BATCH_SIZE);
        if (!batch.empty()) {
            sort_and_write_batch(batch, batch_num);
            batch_num++;
        }
    }
    infile.close();

    // Слияние отсортированных файлов
    merge_sorted_files(batch_num, output_filename);
}


void calculateMemoryUsage() {
    size_t bitArraySizeBytes = BATCH_SIZE / CHAR_BIT; // Размер в байтах
    std::cout << "Размер битового массива: " << bitArraySizeBytes << " байт." << std::endl;
    std::cout << "Размер битового массива: " << bitArraySizeBytes / 1024 << " КБ." << std::endl;
}



int main() {
    SetConsoleOutputCP(CP_UTF8);
    string input_filename = "input.txt";  // Входной файл
    string output_filename = "sorted_output.txt";  // Выходной файл

    // Измерение времени работы программы
    clock_t start = clock();

    // Внешняя сортировка
    external_sort(input_filename, output_filename);

    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Время работы программы: " << duration << " секунд" << endl;
    calculateMemoryUsage();
    return 0;
}
