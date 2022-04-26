#pragma once

//Libraries
#include "Key.h"
#include "List.h"
#include "Node.h"
#include "Ordered_list.h"
#include "RANDOM.h"
#include "Record.h"
#include "Search.h"
#include "Timer.h"
#include "Utility.h"

using namespace std;

//Sequential search test (task 1)
void seq_search(int size, int key) {

	List<Record> list;
	Search search;
	int position;

	for (int i = 1; i <= size; ++i) {
		int x = i * 2 - 1;
		Record rec;
		rec.set_data(i);
		list.insert(i - 1, rec);
	}

	if (search.sequential_search(list, key, position) == success) {
		cout << "Key found in position: " << position << endl;
	}

	else {
		cout << "Key was not found in the list." << endl;
	}
}