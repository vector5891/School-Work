// Bubble Sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
//sort smallest to largest
void sort(int *arr, int size);

int main()
{
	//initialize
	const int n = 10;
	int arr[n] = { 13, 6, 17, 18, 2, 3, 1, 0, 10, 10 };



	//print unsorted array
	cout << "unsorted array: " << endl;
	for (int x = 0; x < n; x++) {
		cout << arr[x] << " ";
	}
	cout << endl;
	//sort
	sort (arr, n);
	//print sorted array
	cout << "sorted array:" << endl;
	for (int x = 0; x < n; x++) {
		cout << arr[x] << " ";
	}

	system("PAUSE");
    return 0;
}

void sort(int *arr, int size) {
	
	int temp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++)
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
	}		
}