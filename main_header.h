#pragma once

//Libraries
#include "List.h"
#include "Node.h"
#include "RANDOM.h"
#include "Record.h"
#include "Search.h"
#include "Sort.h"
#include "Timer.h"
#include "Utility.h"

using namespace std;

//Sequential search test (task 1)
void seq_search(const int& size, const int& key) {

	List<Record> list;
	Search search;
	int position;

	for (int i = 1; i <= size; ++i) {
		Record rec;
		rec.set_data(i);
		list.insert(i - 1, rec);
	}

	Timer timer;
	timer.reset();
	if (search.sequential_search(list, key, position) == success) {
		double time = timer.elapsed_time();
		timer.reset();
		cout << "Key found in position: " << position << endl;
		cout << "Time: " << time << endl;
	}

	else {
		cout << "Key was not found in the list." << endl;
	}
}

void bin_search(const int& size, const int& key) {

	List<Record> list;
	Search search;
	int position;

	for (int i = 1; i <= size; ++i) {
		Record rec;
		rec.set_data(i);
		list.insert(i - 1, rec);
	}
	Timer timer;
	timer.reset();
	if (search.binary_search_1(list, key, position) == success) {
		double time = timer.elapsed_time();
		timer.reset();
		cout << "Key found in position: " << position << endl;
		cout << "Time: " << time << endl;
	}

	else {
		cout << "Key was not found in the list." << endl;
	}
}

void ins_sort(const List<Record>& list, const int& size) {

	
}