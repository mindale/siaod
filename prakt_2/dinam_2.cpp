#include <iostream>
#include <math.h>
#include <windows.h>
using namespace std;

#define N 3 // Количество уравнений

float radius_Array(float A[N][N], float B[N]) {
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

    // Выводим решение
//    for (int i = 0; i < N; i++) {
//        std::cout << "X[" << i << "] = " << X[i] << std::endl;//x[0] = a; x[1] = b; x[2] = c;
//
//    }
    float Xc = -(X[0]);
    float Yc = -(X[1]);
    float R = sqrt(pow(Xc, 2) + pow(Yc,2) - X[2]);
    return R;
}
//
int main(){
    SetConsoleOutputCP(CP_UTF8);
    int num;
    float x[num];
    float y[num];
    cout << "Введите кол-во точек:"; cin >> num;
    for(int i = 0; i < num; i++){
        cout << "Введите x и y:"; cin >> x[i]; cin >> y[i];
    }
    float A[N][N] = {
            {2*x[0], 2*y[0], 1},
            {2*x[1], 2*y[1], 1},
            {2*x[2], 2*y[2], 1}
    };
    float b0 =-(pow(x[0],2) + pow(y[0],2));
    float b1 = -(pow(x[1],2)+pow(y[1],2));
    float b2 = -(pow(x[2],2) + pow(y[2],2));
    float B[N] = {b0, b1, b2};

    float R = radius_Array(A, B);
    cout << R;


}
