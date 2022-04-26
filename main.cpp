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

	switch (version) {
	case 1:
		seq_search(size, key);
		break;

	case 2:
		//binary search
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