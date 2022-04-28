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

//Sequential search performance (task 1)
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
		cout << "Time: " << time << " seconds" << endl;
	}

	else {
		cout << "Key was not found in the list." << endl;
	}
}

//Binary search performance (task 2)
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
		cout << "Time: " << time << " seconds" << endl;
	}

	else {
		cout << "Key was not found in the list." << endl;
	}
}

//Insertion sort performance (task 3)
void ins_sort() {

	Timer timer;
	Record r;
	Random rand;
	Sortable_list<Record> list;
	int size;
	
	cout << "Enter size of the list: ";
	cin >> size;

	//filling list with random integers between 1 and size of the list
	for (int i = 0; i < size; ++i) {
		Record r;
		r = rand.random_integer(1, size);
		list.insert(i, r);
	}

	cout << "Print first 100 values from unsorted list?" << endl;

	if(user_says_yes()){
	cout << "First 100 values from the list unsorted:" << endl;
	for (int i = 0; i < 100; ++i) {
		list.retrieve(i, r);
		cout << r.get_key_data() << " ";
	}
	system("pause");
	}


	

	timer.reset();
	list.insertion_sort(list);
	double time = timer.elapsed_time();
	timer.reset();

	cout << "List is now sorted" << endl
		 << "Time: " << time << " seconds" << endl;

		cout << "Print first 100 values from sorted list?" << endl;

		if (user_says_yes()) {
			cout << "First 100 values from sorted list: " << endl;
			for (int i = 0; i < 100; ++i) {
				list.retrieve(i, r);
				cout << r.get_key_data() << " ";
			}
		}
	
}


//Merge sort performance (task 3)
void quickSort() {

	Timer timer;
	Record r;
	Random rand;
	Sortable_list<Record> list;
	int size;

	cout << "Enter size of the list: ";
	cin >> size;

	//filling list with random integers between 1 and size of the list
	for (int i = 0; i < size; ++i) {
		Record r;
		r = rand.random_integer(1, size);
		list.insert(i, r);
	}

	cout << "Print first 100 values from unsorted list?" << endl;

	if (user_says_yes()) {
		cout << "First 100 values from the list unsorted:" << endl;
		for (int i = 0; i < 100; ++i) {
			list.retrieve(i, r);
			cout << r.get_key_data() << " ";
		}
		system("pause");
	}


	

	timer.reset();
	list.quick_sort(list);
	double time = timer.elapsed_time();
	timer.reset();

	cout << "List is now sorted" << endl
		<< "Time: " << time << " seconds" << endl;

	cout << "Print first 100 values from sorted list?" << endl;

	if (user_says_yes()) {
		cout << "First 100 values from sorted list: " << endl;
		for (int i = 0; i < 100; ++i) {
			list.retrieve(i, r);
			cout << r.get_key_data() << " ";
		}
	}

}