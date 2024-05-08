#include <iostream>
#include <math.h>
#include <windows.h>
using namespace std;

#define N 3 // Количество уравнений
void handcompl_Array(int num, float** points){
    for(int i = 0; i < num; i++){
        points[i] = new float[2];
        cout << "Введите x и y:";
        cin >> points[i][0];
        cin >> points[i][1];
    }
}


void rad_center_Array(float** points){
    float A[N][N] = {
            {2 * points[0][0], 2 * points[0][1], 1},
            {2 * points[1][0], 2 * points[1][1], 1},
            {2 * points[2][0], 2 * points[2][1], 1}
    };
    float b0 =-(pow(points[0][0], 2) + pow(points[0][1], 2));
    float b1 = -(pow(points[1][0], 2) + pow(points[1][1], 2));
    float b2 = -(pow(points[2][0], 2) + pow(points[2][1], 2));

    float B[N] = {b0, b1, b2};

    float X[N]; // Массив для хранения решения

    // Прямой ход метода Гаусса
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            float ratio = A[j][i] / A[i][i];
            for (int k = 0; k < N; k++) {
                A[j][k] -= ratio * A[i][k];
            }
            B[j] -= ratio * B[i];
        }
    }

    // Обратный ход метода Гаусса
    for (int i = N - 1; i >= 0; i--) {
        X[i] = B[i];
        for (int j = i + 1; j < N; j++) {
            X[i] -= A[i][j] * X[j];
        }
        X[i] /= A[i][i];
    }
    float *center = new float[2];
    center[0] = -(X[0]); center[1] = -(X[1]);
    float R = sqrt(pow(center[0], 2) + pow(center[1], 2) - X[2]);
    cout << "X и Y центра окружности: "; cout << center[0]; cout << ":";cout << center[1]; cout << endl;
    cout << "Радиус окружности: "; cout << R;

}


int main(){
    SetConsoleOutputCP(CP_UTF8);
    int num;
    char menu;
    cout << "Введите кол-во точек:"; cin >> num;

    float **points = new float*[num];
    if (num > 3){
        for(int i = 0; i < num; i++){

        }
    }
    handcompl_Array(num, points);
    rad_center_Array(points);
}
