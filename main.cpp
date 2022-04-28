
 // Search and sort algorithm test program

#include "main_header.h"

int main() {

	switch (int version = chooseVersion()) {
	case 1:
		seq_search();
		break;

	case 2:
		bin_search();
		break;

	case 3:
		ins_sort();
		break;

	case 4:
		quickSort();
		break;

	default:
		break;
	}
}