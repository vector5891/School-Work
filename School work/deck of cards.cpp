// deck of cards.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class deck {
public:
	int suits = 4;
	int values = 13;
	const string suit[4] = { "Diamond", "Clubs", "Hearts", "Spades" };
	vector<vector <string>> cards;
public:
	deck::deck(){
		cards.resize(suits);

		for (int i = 0; i < cards.size(); i++) {
			cards[i].resize(values);
		}

		for (int i = 0; i < cards.size(); i++)
		{
			for (int j = 0; j < cards[i].size(); j++)
			{
				cards[i][j] = to_string(j+1) + " of " + suit[i];
			}
		}
		cout << "init deck \n";
	}

	~deck() {
		while (!cards.empty()) {
			cards.pop_back();
		}
		cout << "deck empty \n";
	}
public:
	void print_deck() {
		for (int i = 0; i < suits; i++) {
			for (int j = 0; j < values; j++) {
				cout << cards[i][j] << endl;
			}
		}
	}
};


int main()
{
	deck* deck1 = new deck;
	deck1 -> print_deck();
	delete deck1;

	system("PAUSE");
    return 0;
}

