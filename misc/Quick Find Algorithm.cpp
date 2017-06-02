// Quick Find Algorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void printArr(int arr[], int arrsize);
void connectNodes(int arr[], int arrsize, int node1, int node2);
bool Equivalance(int arr[], int arrsize, int node1, int node2);
vector<int> groupNodes(int arr[], int arrsize);
void loopcheck(int arr[], int arrsize);
int main()
{
	const int arrSize = 10;
	int pID[arrSize] = { 0,1,2,3,4,5,6,7,8,9 };
	printArr(pID, arrSize);
	//components {0,5,6}, {1,2,7}, {8,3,4,9}
	//find the IDs
	connectNodes(pID, arrSize, 0, 5);
	connectNodes(pID, arrSize, 5, 6);
	connectNodes(pID, arrSize, 1, 2);
	connectNodes(pID, arrSize, 2, 7);
	connectNodes(pID, arrSize, 8, 3);
	connectNodes(pID, arrSize, 3, 4);
	connectNodes(pID, arrSize, 4, 9);
	loopcheck(pID, arrSize);
	printArr(pID, arrSize);
	vector<int> n = groupNodes(pID, arrSize);

	for (int i = 0; i < n.size(); i++) {
		cout << n[i];
		if (i < n.size() - 1) {
			cout << ", ";
		}
	}
	cout << endl;

	system("PAUSE");
	return 0;
}

void printArr(int arr[], int arrsize) {
	for (int i = 0; i < arrsize; i++) {
		cout << arr[i];
		if (i < arrsize - 1) {
			cout << ", ";
		}
	}
	cout << endl;
}
void connectNodes(int arr[], int arrsize, int node1, int node2) {
	//select the nodes to connect
	//the value of node 2 changes to the value of node 1
	arr[arrsize];
	arr[node2] = arr[node1];
}
bool Equivalance(int arr[], int arrsize, int node1, int node2) {
	return arr[node1] == arr[node2];
}
vector<int> groupNodes(int arr[], int arrsize) {
	vector<int> temp;
	temp.empty();
	//start with the first node in the array, check for equivalences
	for (int i = 0; i < arrsize; i++) {
		temp.push_back(arr[i]);
	}
	sort(temp.begin(), temp.end());
	return temp;
}
void loopcheck(int arr[], int arrsize) {
	char Y_N = 'x';
	while ((Y_N != 'N') && (Y_N != 'n')) {
		int n1, n2 = 0;
		cout << "which nodes do you want to check? \n";
		cin >> n1, n2;
		if (Equivalance(arr, arrsize, n1, n2) == true)
			cout << "those nodes are connected \n";
		if (Equivalance(arr, arrsize, n1, n2) == false)
			cout << "those nodes are not connected \n";
		
		cout << "play check another? Y/N \n";
		cin >> Y_N;
	}
}