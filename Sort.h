#pragma once
#include "List.h"
#include "Node.h"

template <class Record>
class Sortable_list :public List<Record> {
public:
    Sortable_list();
    void insertion_sort(Sortable_list<Record>& list);
    void quick_sort(Sortable_list<Record>& list);
    void recursive_quick_sort(Sortable_list<Record>& list, int low, int high);
    int partition(Sortable_list<Record>& list, int low, int high);
    void swap(Sortable_list<Record>& list, int low, int high);
    void recursive_merge_sort(Node<Record>*& sub_list);

};

template<class Record>
inline Sortable_list<Record>::Sortable_list()
{
}

template <class Record>
inline void Sortable_list<Record>::insertion_sort(Sortable_list<Record>& list)
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

    for (first_unsorted = 1; first_unsorted < list.count; first_unsorted++)
        if (list.entry[first_unsorted] < list.entry[first_unsorted - 1]) {
            position = first_unsorted;
            current = list.entry[first_unsorted];         //  Pull unsorted entry out of the list.
            do {               //  Shift all entries until the proper position is found.
                list.entry[position] = list.entry[position - 1];
                position--;                           //  position is empty.
            } while (position > 0 && list.entry[position - 1] > current);
            list.entry[position] = current;
        }
}

template <class Record>
inline void Sortable_list<Record>::quick_sort(Sortable_list<Record>& list)
/*
Post: The entries of the Sortable_list have been rearranged so
      that their keys are sorted into nondecreasing order.
Uses: The contiguous List implementation of Chapter 6, recursive_quick_sort.
*/
{
    recursive_quick_sort(list, 0, list.count - 1);
}

template <class Record>
inline void Sortable_list<Record>::recursive_quick_sort(Sortable_list<Record>& list, int low, int high)
/*
Pre:  low and high are valid positions in the Sortable_list.
Post: The entries of the Sortable_list have been
      rearranged so that their keys are sorted into nondecreasing order.
Uses: The contiguous List implementation of Chapter 6,
      recursive_quick_sort, and partition.
*/
{
    int pivot_position;
    if (low < high) {   //   Otherwise, no sorting is needed.
        pivot_position = partition(list, low, high);
        recursive_quick_sort(list, low, pivot_position - 1);
        recursive_quick_sort(list, pivot_position + 1, high);
    }
}

template <class Record>
inline int Sortable_list<Record>::partition(Sortable_list<Record>& list, int low, int high)
/*
Pre:  low and high are valid positions of the Sortable_list, with low <= high.
Post: The center (or left center) entry in the range between indices
      low and high of the Sortable_list
      has been chosen as a pivot.  All entries of the Sortable_list
      between indices low and high, inclusive, have been
      rearranged so that those with keys less than the pivot come
      before the pivot and the remaining entries come
      after the pivot.  The final position of the pivot is returned.
Uses: swap(int i, int j) (interchanges entries in positions
      i and j of a Sortable_list), the contiguous List implementation
      of Chapter 6, and methods for the class Record.
*/
{
    Record pivot;
    int i,            //  used to scan through the list
        last_small;   //  position of the last key less than pivot
    swap(list, low, (low + high) / 2);
    pivot = list.entry[low];   //  First entry is now pivot.
    last_small = low;
    for (i = low + 1; i <= high; i++)
        /*
        At the beginning of each iteration of this loop, we have the following
        conditions:
                If low < j <= last_small then entry[j].key < pivot.
                If last_small < j < i then entry[j].key >= pivot.
        */
        if (list.entry[i] < pivot) {
            last_small = last_small + 1;
            swap(list, last_small, i);  //  Move large entry to right and small to left.
        }
    swap(list, low, last_small);      //  Put the pivot into its proper position.
    return last_small;
}

template <class Record>
void Sortable_list<Record>::swap(Sortable_list<Record>& list, int low, int high)
/*
Pre:  low and high are valid positions in the Sortable_list.
Post: The entry at position low is swapped with the entry at position high.
Uses: The contiguous List implementation of Chapter 6.
*/
{
    Record temp;
    temp = list.entry[low];
    list.entry[low] = list.entry[high];
    list.entry[high] = temp;
}