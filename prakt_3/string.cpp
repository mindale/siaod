#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

void replaceArray(string& sentence) {
    int temp = 0;
    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] == '(') {
            temp = i;
        } else if (sentence[i] == ')' and temp != 0) {
            int start = temp;
            int end = i;
            int count = 0;
            if (end-start != 0){count = end - start - 1;}

            string replacement = to_string(count);
            if (count != 0){sentence.replace(start + 1, count, replacement);}
            else{sentence.replace(start+1, 0, replacement);}
            temp = 0;
        }
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    cout << "Введите строку: ";
    string sentence;
    cin >> sentence;
    replaceArray(sentence);
    cout << sentence << std::endl;

    return 0;
}
