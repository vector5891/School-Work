#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

int main() {
	//init time
	time_t now = time(NULL);
	struct tm local;
	localtime_s(&local, &now);
	int prev = local.tm_sec;
	//init time hh/mm/ss 
	int seconds = 0;
	int minutes = 0;
	int hours = 0;

	while (true) {
		now = time(NULL);
		localtime_s(&local, &now);
		if (local.tm_sec != prev) {
			prev = local.tm_sec;
			++seconds;
			if (seconds == 60) {
				seconds = 0;
				++minutes;
			}
			if (minutes == 60) {
				minutes = 0;
				++hours;
			}
			system("cls"); //clears console
			//cout using iomanip set precision and fill with a '0' where the width does not == 2
			cout << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds << endl;
		}
	}


	system("PAUSE");
	return 0;
}