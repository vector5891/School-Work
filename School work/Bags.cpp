// Bags.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"     //delete this if you arent using visual studio as your compiler
#include <iostream>
#include <string>
using namespace std;

class bags {
protected:
	string type_of_bag;//handbag, speghetti strand, shoulder bag, etc
	string feature; //insulated, waterproof, water resistant, etc
	string color;
public:
	bags::bags(string type_, string feature_, string color_) {
		type_of_bag = type_;
		feature = feature_;
		color = color_;
	}
	///
	string get_color() { return color; }
	string get_feature() { return feature; }
	string get_type() { return type_of_bag; }
	//
	void describe_bag() {
		cout << "the bag is a " << type_of_bag << ", its " << color << " and it is " << feature << endl;
	}
	~bags() {
		cout << "boom" << endl;
	}
};
class bags_for_cars : virtual public bags {                                  // by adding virtual, bags for cars can access functions from the parent class bags
	string _type_;
	string features;
	string colors;
public:
	bags_for_cars::bags_for_cars(string t, string f, string c) : bags(t, f, c) {      //constructor
		_type_ = t;
		features = f;
		colors = c;
	}

};
class bags_for_schools : virtual public bags { 
	string typeofbag;
	string feat;
	string colorS;
public:
	bags_for_schools::bags_for_schools(string type_, string feature_, string color_) : bags(type_, feature_, color_) {   //constructure
		typeofbag = type_;
		feat = feature_;
		colorS = color_;
	}
	~bags_for_schools() {   //desctructor
		delete this; //unsafe XDDD
	}
};

int main()
{
	
	bags b1("handbag", "waterproof", "blue");
	b1.describe_bag();

	bags_for_schools b2("messenger", "made of nylon", "black"); //created a bag that is used and sold at schools
	b2.describe_bag();                                          // as you can see, in the bags for schools class, the describe bag function does not exist, it is an inherited
																// function from the parent class bags
	
	system("PAUSE");        //you dont need this if you arent using visual studo as a compiler
    return 0;
}

