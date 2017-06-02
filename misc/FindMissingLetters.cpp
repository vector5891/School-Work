#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

string toLower(string s);
string removeSpaces(string s);
string findNonMatching(string s, string s1);
int main() {
    string inputString;
    cout << "input a string \n";
    getline(cin, inputString);
    inputString = toLower(inputString);
    inputString = removeSpaces(inputString);
    string output = "abcdefghijklmnopqrstuvwxyz";
    output = findNonMatching(inputString, output);
    cout << output << endl;

    return 0;
}

string toLower(string s) {
    for (int i = 0; i < s.size(); i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}
string removeSpaces(string s) {
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    return s;
}
string findNonMatching(string s, string s1) {
    //s = input string, s1 output string
    //recursion on s1
    while(!s.empty()){
        for(int i = 0; i < s.length(); i++) {
            for (int j = 0; j < s1.length(); j++) {
                if (s[i] == s1[j]) {
                    s1.erase(j,1);
                }
            }
            s.erase(i,1);
        };
        s1 = findNonMatching(s, s1);
    }
    return s1;
}
