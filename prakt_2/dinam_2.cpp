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

void new_3_Array(int num, float** points, float** n_points){

}

float proverka(float** points, float* r_c, int num){
    float counter = 0;
    for(int i; i < num; i++){
        float l1 = pow((points[i][0] - r_c[0]),2);
        float l2 = pow((points[i][1] - r_c[1]), 2);
        if ((l1 + l2) <= pow(r_c[2], 2)){
            counter++;
        }
    }
    return counter;
}


float* rad_center_Array(float** points){
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
    float Xc = -(X[0]);
    float Yc = -(X[1]);
    center[0] = -(X[0]); center[1] = -(X[1]);
    float R = sqrt(pow(Xc, 2) + pow(Yc, 2) - X[2]);
    float *answer = new float[3];
    answer[0] = Xc; answer[1] = Yc; answer[2] = R;
    return answer;


}


int main(){
    SetConsoleOutputCP(CP_UTF8);
    int num;
    char menu;
    cout << "Введите кол-во точек:"; cin >> num;
    float **points = new float*[num];
    handcompl_Array(num, points);

    if (num > 3){
        float max_R = 0;
        float *end_res = new float[3];
        float **res_t = new float*[3];
        for(int i = 0; i < num; i++){
            for(int j = i+1; j < num; j++){
                for(int k = j+1; k < num; k++){
                    float **sevpoints = new float*[3];
                    sevpoints[0] = points[i];
                    sevpoints[1] = points[j];
                    sevpoints[2] = points[k];
//                    cout << "X центр = " << rad_center_Array(sevpoints)[0] << endl;
//                    cout << "Y центр = " << rad_center_Array(sevpoints)[1] << endl;
                    float R = rad_center_Array(sevpoints)[2];
//                    cout << "R = " << R << endl;
                    if (R > max_R){
                        res_t[0] = points[i];
                        res_t[1] = points[j];
                        res_t[2] = points[k];
                        max_R = R;
                        end_res[0] = rad_center_Array(sevpoints)[0];
                        end_res[1] = rad_center_Array(sevpoints)[1];
                        end_res[2] = proverka(points, rad_center_Array(sevpoints), num);
                    }
//                    cout << "Кол-во точек внутри = " << proverka(points, rad_center_Array(sevpoints), num);
                    delete[] sevpoints;
                }
            }
        }
        cout << "X центр = " << end_res[0] << endl;
        cout << "Y центр = " << end_res[1] << endl;
        cout << "R = " << max_R << endl;
        cout << "Кол-во точек внутри = " << end_res[2] << endl;
        cout << "Точки, образующие окр: " << *res_t[0] << " " << *res_t[1] << " " << *res_t[2];
    }
    else{
        cout << "X центр = " << rad_center_Array(points)[0] << endl;
        cout << "Y центр = " << rad_center_Array(points)[1] << endl;
        cout << "R = " << rad_center_Array(points)[2] << endl;
        cout << "Кол-во точек внутри = " << proverka(points, rad_center_Array(points), num);
    }

}
