#pragma once
#ifndef restaurants_
#define restaurants_

#include "stdafx.h"
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class sku_search {
public:
	//declaration of varables
	string Master_ID;
	ifstream in_;
	//file declaration
	string dhaba = "dhaba.csv";
	string chola = "chola.csv";
	string chote = "chote.csv";
	string haldi = "haldi.csv";
	string m_marke = "malai_marke.csv";


	//read csv files and retreive SKUs
	string read_file(string restaurant_name, string master_id)
	{
		string restaurant_SKU;
		string file;
		//restaurant name check -> decide which file to open
		if (restaurant_name == "Dhaba") {
			file = dhaba;
		}
		if (restaurant_name == "Chola") {
			file = chola;
		}
		if (restaurant_name == "Chote wab") {
			file = chote;
		}
		if (restaurant_name == "Haldi") {
			file = haldi;
		}
		if (restaurant_name == "Malai Marke") {
			file = m_marke;
		}

		//opening restaurant file && error report
		in_.open(file);
		if (in_.is_open()) {
			cout << file << " file is open" << endl;
		}
		else
			cerr << file << " failed to open" << endl;

		string line_, field_;
		vector< vector<string> > array_;
		vector<string> v_;
		cout << "reading restaurant file" << endl;
		while (getline(in_, line_)) {
			v_.clear();
			stringstream ss(line_);
			// break line into comma delimitted fields
			while (getline(ss, field_, ',')) {
				v_.push_back(field_);
			}

			array_.push_back(v_);  // add the 1D array to the 2D array
		}

		cout << "searching for restaurant SKU" << endl;
		//search for matching master_ID and output the SKU
		for (size_t i = 0; i < array_.size(); ++i) {
			for (size_t j = 0; j < array_[i].size(); ++j) {
				//cout << array[i][j] << "|";
				//use this place to operate
				if (array_[i][5] == master_id) {
					restaurant_SKU = array_[i][6];
				}
			}
		}

		in_.close();
		return restaurant_SKU;
	}
};


#endif

/*
create a function to close the files at the end of the program for better memory management.
*/