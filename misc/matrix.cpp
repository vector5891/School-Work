// matrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include "matrix_.h"
using namespace std;

int main()
{	
	//matrix(rows, columns)
	Matrix m(8, 6);
	m.populate_matrix();
	m.print();
	int r, c;
	cout << "enter rows and columns for matrix 2 \n";
	cin >> r >> c;
	Matrix m2(r, c);
	m2.print();
	Matrix result = m.multiply_matrix(m, m2);
	result.print();

	system("PAUSE");
    return 0;
}
