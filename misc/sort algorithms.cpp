
#include "stdafx.h"
#include <iostream>
using namespace std;

void insert_sort(int arr[], int size);
void select_sort(int arr[], int size);
void bubble_sort(int arr[], int size);
void print_arr(int arr[], int size);
int main()
{
	const int n = 10;
	int arr[n] = { 15,3,1,17,10,20,60,3,9,10 };

	//insert sort
	insert_sort(arr, n);
	cout << endl;
	//print array
	cout << "Insert Sort : ";
	print_arr(arr, n);
	
	cout << endl;
	system("PAUSE");
    return 0;
}

void print_arr(int arr[], int size){
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}

// 15,3,1,17,10,20,60,3,9,10
void insert_sort(int arr[], int size) {

	for (int i = 0; i < size; i++) {
		int j = i;
		while ((j > 0) && (arr[j - 1] > arr[j])) {
			swap(arr[j], arr[j - 1]);
			j--;
		}
	}
}
void select_sort(int arr[], int size)
{
	int min, temp;
	for (int i = 0; i < size - 1; i++){
		min = i;
		for (int j = i + 1; j < size; j++){
			if (arr[j] < arr[min])
				min = j;
		}
		if (min != i){
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}
void bubble_sort(int arr[], int size) {

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
