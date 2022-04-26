#pragma once

template <class Record>
class Sortable_list :public List<Record> {
public:
	Sortable_list();
	void insertion_sort();
private:

};

template<class Record>
inline Sortable_list<Record>::Sortable_list()
{
}

template <class Record>
void Sortable_list<Record>::insertion_sort()
/*
Post: The entries of the Sortable_list have been rearranged so that
      the keys in all the  entries are sorted into nondecreasing order.
Uses: Methods for the class Record; the contiguous List implementation of
      Chapter 6
*/
{
    int first_unsorted;    //  position of first unsorted entry
    int position;          //  searches sorted part of list
    Record current;        //  holds the entry temporarily removed from list

    for (first_unsorted = 1; first_unsorted < count; first_unsorted++)
        if (entry[first_unsorted] < entry[first_unsorted - 1]) {
            position = first_unsorted;
            current = entry[first_unsorted];         //  Pull unsorted entry out of the list.
            do {               //  Shift all entries until the proper position is found.
                entry[position] = entry[position - 1];
                position--;                           //  position is empty.
            } while (position > 0 && entry[position - 1] > current);
            entry[position] = current;
        }
}

