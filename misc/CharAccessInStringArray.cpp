#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    const int ArrSize = 5;
    string Arr[ArrSize] = {"hello", "world", "how", "are", "you"};
    for(int i = 0; i < ArrSize; i++) {
        cout << Arr[i][Arr[i].length()-1];
    }
    return 0;
}
