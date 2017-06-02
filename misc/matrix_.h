#pragma once
#ifndef Matrix_h
#define Matrix_h
#include <iostream>
#include <vector>
using namespace std;

class Matrix {
private:
	int rows = 0;
	int columns = 0;
	vector <vector<int>> mat;
public:
	Matrix(int r, int c) {
		if (mat.empty()) {
			rows = r;
			columns = c;
			mat.resize(rows);

			for (int i = 0; i < mat.size(); i++) {
				mat[i].resize(columns);
			}
		}
	}
	void populate_matrix() {
		for (int i = 0; i < mat.size(); i++) {
			for (int j = 0; j < mat[i].size(); j++) {
				cout << "insert value for cell[" << i << "][" << j << "]" << endl;
				cin >> mat[i][j];
			}
		}
		cout << "Matrix has been fully populated \n";
	}
public:
	void print() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				cout << mat[i][j] << endl;
			}
		}
	}
	Matrix multiply_matrix(Matrix m1, Matrix m2) {
		if (m1.rows != m2.columns) {
			cerr << "miss match matrix sizes \n";
			EXIT_FAILURE;
		}
		Matrix product(m1.rows, m2.columns);
		for (int i = 0; i<m1.rows; i++) {
			for (int j = 0; j<m2.columns; j++) {
				product.mat[i][j] = 0;
				for (int k = 0; k<m2.columns; k++) {
					product.mat[i][j] = m1.mat[i][j] + (m1.mat[i][k] * m2.mat[k][j]);
				}
			}
		}
		return product;
	}
	
};
#endif // !Matrix_h