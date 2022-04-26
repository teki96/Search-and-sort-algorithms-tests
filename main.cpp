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
		bin_search(size, key);
		break;

	case 3:
		ins_sort();
		break;

	case 4:
		//sorting performance with randomized data

	default:
		break;
	}
}