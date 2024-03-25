#include <iostream>
using namespace std;
//void udArray(string n){
//    string new_n = "";
//    string temp_n = n;
//    int temp_s = 0;
//    for(int i = 0; i < size(n); i++) {
//        if(n[i] == '('){
//            for(int k = i; i < size(temp_n); k++){
//                if (temp_n[k] != ')'){
//                    temp_s+=1;
//                }
//                else{break;}
//            }
//            if (size(temp_n)-i == temp_s){cout << "Второй скобки не обнаружено!";}
//
////        cout << n[i];
//    }
////    cout << new_n.type_info();
//}}
//    return new_n;


string resizeArray(string s, int index_1, int index_2){//Удаление определнных элементов с определнным индексом
    string new_s = "";
    string temp = "";
    for(int i = 0; i<index_1; i++){
        temp += s[i];
    }
    new_s += temp;
    temp = "";
    for(int i = index_2+1; i < size(s); i++){
        temp += s[i];
    }
    new_s += temp;
    return new_s;
}
int main(){
    string s = "zlatovlas";
//    udArray(s);
    cout << resizeArray(s, 1, 4);
}