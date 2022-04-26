#include "main_header.h"

int main() {

	int size, key;

	int version = chooseVersion();

	if (version == 1 || version == 2) {
		cout << "Enter size of the list: ";
		cin >> size;

		cout << "Number to search from the list: ";
		cin >> key;
	}

	if (version == 3) {
		List<Record> list;
		Random rand;

		cout << "Enter size of the list: ";
		cin >> size;
		
		//filling list with random integers between 1 and size of the list
		for (int i = 0; i < size; ++i) {
			Record r;
			r = rand.random_integer(1, size);
			list.insert(i, r);
		}
	}

	switch (version) {
	case 1:
		seq_search(size, key);
		break;

	case 2:
		bin_search(size, key);
		break;

	case 3:
		//insertion sort with randomized data
		break;

	case 4:
		//sorting performance with randomized data

	default:
		break;
	}
}