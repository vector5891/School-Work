// compare three arrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool compare_vectors(vector<int> v1, vector<int> v2, vector<int> v3);
vector<int> convert_to_vector(int arr[], int arr_size);
int main()
{
	//sample arrays
	const int arr_len = 10;
	int arr1[arr_len] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[arr_len] = { 10,9,8,7,6,5,4,3,2,1 };
	int arr3[arr_len] = { 10,2,3,4,5,6,7,8,9,1 };

	//flipped through the internet and remembered that turning the array into vectors will make my work easier

	vector<int>vect1 = convert_to_vector(arr1, arr_len);
	vector<int>vect2 = convert_to_vector(arr2, arr_len);
	vector<int>vect3 = convert_to_vector(arr3, arr_len);

	bool areequal = compare_vectors(vect1, vect2, vect3);

	if (areequal == true)
		cout << "vectors are equal \n";
	else
		cout << "vectors not equal \n";
	system("PAUSE");
    return 0;
}

vector<int> convert_to_vector(int arr[], int arr_size) {
	vector<int> conversion(arr, arr + arr_size);
	sort(conversion.begin(), conversion.end());            //comment this line out to stop this function from sorting the vectors, by doing so it'll alter the result of the comparison
	return conversion;
}
//returns true only if all conjunctions(&&) are true
bool compare_vectors(vector<int> v1, vector<int> v2, vector<int> v3) {
	return ((equal(v1.begin(), v1.end(), v2.begin(), v2.end())) && (equal(v2.begin(), v2.end(), v3.begin(), v3.end())) && (equal(v1.begin(), v1.end(), v3.begin(), v3.end())));
}

//this is scaleable to more than 3 arrays/vectors simply by changing the number of parameters.
