#include <stdio.h>
#include <iostream>
using namespace std;
int main() {
	int T;
	cin >> T;
	int n = 1; //increment by 1
	for(int i = 0; i < T; i++){
        for(int j = 0; j <= i; j++){
            if(j <= i){
                cout << n++ << " ";
            }
            if(j == i){
                cout << endl;
            }
        }
	}
	return 0;
}

//http://practice.geeksforgeeks.org/problems/floyds-triangle/0
