#pragma once

#include "Node.h"
#include "Utility.h"

template <class List_entry>
class List {
public:
	//  Specifications for the methods of the list ADT go here.

	List();
	int size() const;
	bool full() const;
	bool empty() const;
	void clear();
	void traverse(void(*visit)(List_entry&));
	Error_code retrieve(int position, List_entry& x) const;
	Error_code replace(int position, const List_entry& x);
	Error_code remove(int position, List_entry& x);
	Error_code insert(int position, const List_entry& x);

	//  The following methods replace compiler-generated defaults.
	~List();
	List(const List<List_entry>& copy);
	void operator =(const List<List_entry>& copy);
protected:
	//  Data members for the linked list implementation now follow.
	int count;
	Node<List_entry>* head;
	mutable int current_position;
	mutable Node<List_entry>* current;

	//  The following auxiliary function is used to locate list positions
	void set_position(int position) const;
};

template <class List_entry>
List<List_entry>::List()
/*

Post: The List is initialized to be empty.

*/

{
	count = 0;
	head = NULL;
}

template <class List_entry>
void List<List_entry>::clear()
/*

Post: The List is cleared.

*/

{
	Node<List_entry>* p, * q;

	for (p = head; p; p = q) {
		q = p->next;
		delete p;
	}
	count = 0;
	head = NULL;
}

template <class List_entry>
int List<List_entry>::size() const
/*

Post: The function returns the number of entries in the List.

*/

{
	return count;
}

template <class List_entry>
bool List<List_entry>::empty() const
/*

Post: The function returns true or false according as the List is empty or not.

*/

{
	return count <= 0;
}

template <class List_entry>
bool List<List_entry>::full() const
/*

Post: The function returns 1 or 0 according as the List is full or not.

*/

{
	return false;
}

template <class List_entry>
void List<List_entry>::traverse(void(*visit)(List_entry&))
/*

Post: The action specified by function (*visit) has been performed on every
entry of the List, beginning at position 0 and doing each in turn.

*/

{
	Node<List_entry>* q;

	for (q = head; q; q = q->next)
		(*visit)(q->entry);
}
/*
template <class List_entry>
Error_code List<List_entry>::insert(int position, const List_entry &x)


Post: If the List is not full and 0 <= position <= n,
where n is the number of entries in the List,
the function succeeds:
Any entry formerly at
position and all later entries have their
position numbers increased by 1, and
x is inserted at position of the List.


Else:
The function fails with a diagnostic error code.


{
	if (position < 0 || position > count)
	{
		return utility_range_error;
	}

	Node<List_entry> *new_node, *previous, *following;
	if (position > 0) {
		previous = set_position(position - 1);
		following = previous->next;
	}
	else
	{
		previous = set_position(NULL);
		following = head;
	}
	new_node = new Node<List_entry>(x, following);
	if (new_node == NULL)
		return overflow;
	if (position == 0)
		head = new_node;
	else
		previous->next = new_node;
	count++;
	return success;
}
*/
template <class List_entry>
Error_code List<List_entry>::retrieve(int position, List_entry& x) const
/*

Post: If the List is not full and 0 <= position < n,
where n is the number of entries in the List,
the function succeeds:
The entry in position is copied to x.
Otherwise the function fails with an error code of range_error.

*/

{
	//Node<List_entry> *current;
	if (position < 0 || position >= count)
	{
		return utility_range_error;
	}
	//current = set_position(position);
	set_position(position);
	x = current->entry;
	return success;
}

template <class List_entry>
Error_code List<List_entry>::replace(int position, const List_entry& x)
/*

Post: If 0 <= position < n,
where n is the number of entries in the List,
the function succeeds:
The entry in position is replaced by x,
all other entries remain unchanged.
Otherwise the function fails with an error code of range_error.

*/

{
	Node<List_entry>* current;
	if (position < 0 || position >= count) return range_error;
	current = set_position(position);
	current->entry = x;
	return success;
}

/*

Post: If 0 <= position < n,
where n is the number of entries in the List,
the function succeeds:
The entry in position is removed
from the List, and the entries in all later positions
have their position numbers decreased by 1.
The parameter x records a copy of
the entry formerly in position.
Otherwise the function fails with a diagnostic error code.

*/

template <class List_entry>
Error_code List<List_entry>::remove(int position, List_entry& x)
{
	Node<List_entry>* prior, * current;
	if (count == 0) return fail;
	if (position < 0 || position >= count) return range_error;

	if (position > 0) {
		prior = set_position(position - 1);
		current = prior->next;
		prior->next = current->next;
	}

	else {
		current = head;
		head = head->next;
	}

	x = current->entry;
	delete current;
	count--;
	return success;
}
/*
template <class List_entry>
Node<List_entry> *List<List_entry>::set_position(int position) const

Pre:   position is a valid position in the List;
0 <= position < count.
Post: Returns a pointer to the Node in position.

{
	Node<List_entry> *q = head;
	for (int i = 0; i < position; i++)
	q = q->next;
	return q;
}
*/
template <class List_entry>
List<List_entry>::~List()
/*

Post: The List is empty: all entries have been removed.

*/

{
	clear();
}

template <class List_entry>
List<List_entry>::List(const List<List_entry>& copy)
/*

Post: The List is initialized to copy the parameter copy.

*/

{
	count = copy.count;
	Node<List_entry>* new_node, * old_node = copy.head;

	if (old_node == NULL) head = NULL;
	else {
		new_node = head = new Node<List_entry>(old_node->entry);
		while (old_node->next != NULL) {
			old_node = old_node->next;
			new_node->next = new Node<List_entry>(old_node->entry);
			new_node = new_node->next;
		}
	}
}

template <class List_entry>
void List<List_entry>::operator =(const List<List_entry>& copy)
/*

Post: The List is assigned to copy a parameter

*/

{
	List new_copy(copy);
	clear();
	count = new_copy.count;
	head = new_copy.head;
	new_copy.count = 0;
	new_copy.head = NULL;
}

template <class List_entry>
void List<List_entry>::set_position(int position) const
/*
Pre:  position is a valid position in the List: 0 <= position < count.
Post: The current Node pointer references the Node at position.
*/
{
	if (current_position <= position)
		for (; current_position != position; current_position++)
			current = current->next;
	else
		for (; current_position != position; current_position--)
			current = current->back;
}


template <class List_entry>
Error_code List<List_entry>::insert(int position, const List_entry& x)
/*
Post: If the List is not full and 0 <= position <= n,
where n is the number of entries in the List, the function succeeds:
Any entry formerly at position and all later entries have their
position numbers increased by 1 and x is inserted at position of the List.
Else: the function fails with a diagnostic error code.
*/
{
	Node<List_entry>* new_node, * following, * preceding;
	if (position < 0 || position > count) return utility_range_error;
	if (position == 0) {
		if (count == 0) following = NULL;
		else {
			set_position(0);
			following = current;
		}
		preceding = NULL;
	}
	else {
		set_position(position - 1);
		preceding = current;
		following = preceding->next;
	}
	new_node = new Node<List_entry>(x, preceding, following);

	if (new_node == NULL) return overflow;
	if (preceding != NULL) preceding->next = new_node;
	if (following != NULL) following->back = new_node;
	current = new_node;
	current_position = position;
	count++;
	return success;
}

