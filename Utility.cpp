#include "Utility.h"
#include <iostream>
using namespace std;

bool user_says_yes()
{
	int c;
	bool initial_response = true;

	do {  //  Loop until an appropriate input is received.
		if (initial_response)
			cout << " (y,n)? " << flush;

		else
			cout << "Respond with either y or n: " << flush;

		do { //  Ignore white space.
			c = cin.get();
		} while (c == '\n' || c == ' ' || c == '\t');
		initial_response = false;
	} while (c != 'y' && c != 'Y' && c != 'n' && c != 'N');
	return (c == 'y' || c == 'Y');
}

int chooseVersion()
{
	int v;

	while (true){
	cout << "Test bed for search and / or sorting algorithms" << endl
		<< "Choose version to run:" << endl
		<< "1: Make sequential seach. (task 1)" << endl
		//<< "2: Make binary search (task 2)" << endl
		<< flush;

	if (cin >> v)
		if (v == 1 || v == 2)
			return v;

		else
			cin.clear();
			cin.ignore(INT_MAX, '\n');
	}
}
