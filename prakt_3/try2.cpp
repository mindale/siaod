#include <iostream>
#include <stack>
#include <string>
#include <windows.h>
using namespace std;

void removeBetweenBrackets(string& sentence) {
    stack<int> indexes;
    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] == '(') {
            indexes.push(i);
        } else if (sentence[i] == ')' and !indexes.empty()) {
            int start = indexes.top();
            int end = i;
            int count = 0;
            if (end-start != 0){count = end - start - 1;}

            string replacement = to_string(count);
            if (count != 0){sentence.replace(start + 1, count, replacement);}
//            else {sentence.insert(start+1, "0");}
            else{sentence.replace(start+1, 0, replacement);}
            indexes.pop();
        }
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    cout << "Введите строку: ";
    string sentence;
    cin >> sentence;

    removeBetweenBrackets(sentence);

    cout << sentence << std::endl;

    return 0;
}
