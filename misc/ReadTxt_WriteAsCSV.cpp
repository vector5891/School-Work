/*
 * reads txt file and outputs it as a csv
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
int main() {
    ifstream infile;
    infile.open ("/Desktop/stuff/federalfunds.txt");    //path to txt file
    if (infile.is_open()) {
        cout << "file is opened" << endl;               //used for debugging
    }
    if (infile.fail()) {
        cerr << "Error file not found" << endl;
        return 1;
    }
    ofstream out("/Desktop/stuff/test.csv", ios::app);  //path to output
    cout << "output file created" << endl;              //used for debugging

    string line, field;
    vector< vector<string> > array;
    vector<string> v;

    while (getline(infile, line)) {
        v.clear();
        stringstream ss(line);
        while (getline(ss, field, ','))  {
            v.push_back(field);
        }
        array.push_back(v);
    }
    for (size_t i = 0; i< array.size(); ++i) {
        string values;
        for (size_t j = 0; j< array[i].size(); ++j) {
            out << array[i][j];
            out << ',';
        }
    }

    //end
    cout << "done" << endl;
    out.close();
    infile.close();
    return 0;
}
