#pragma once
#include "Utility.h"
#include "List.h"
#include "Key.h"
#include "Record.h"
#include "Ordered_list.h"

class Search
{
public:
	Search();
	Error_code sequential_search(const List<Record>& the_list,
		const Key& target, int& position);
	Error_code binary_search_1(const Ordered_list& the_list,
		const Key& target, int& position);
};

