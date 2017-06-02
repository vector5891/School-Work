// pointer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int x[1] = { 50 };
	int* p = &x[0];
	int y = *p;

	cout <<  p << endl;  //prints the address of &x[0]                            output: random address
	cout << *p << endl;  //prints the value of *p which points at &x[0]           output: 50
	cout <<  y << endl;  // prints the value of *p; y is set to equal *p          output: 50

	system("PAUSE");
    return 0;
}

