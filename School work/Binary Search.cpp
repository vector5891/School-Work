// Binary Search.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int binary_search(int *arr, int begin, int end, int target);

int main() {
	int target;
	const int size = 15;
	int arr[size] = { 3, 6, 19, 20, 20, 22, 30, 32, 33, 45, 60, 67, 77, 82, 90 };

	cout << "what value are you looking for?" << endl;
	cin >> target;

	int location = binary_search(arr, 0, size, target);
	if (location != 9999999999999999) {
		cout << "target is located: " << location << " in the array" << endl;
	}

	system("PAUSE");
	return 0;
}

int binary_search(int *arr, int begin, int end, int target) {

	while (end > begin) {
		int midpoint = ((begin + end) / 2);

		//if value at midpoint is larger than target value
		if (arr[midpoint] > target) {
			end = midpoint;
			binary_search(arr, begin, end, target);
		}
		//if value at midpoint is smaller than target value
		if (arr[midpoint] < target) {
			begin = midpoint;
			binary_search(arr, begin, end, target);
		}
		if (arr[midpoint] == target){
			
			return midpoint;
		}
		else
			cout << "target not found \n";
	}
	
	return 9999999999999999;
}
