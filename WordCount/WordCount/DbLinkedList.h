// Rephael Edwards
// CMPS 3013 Program 2
// File: DbLinkedList.h

#pragma once

#include <iostream>
#include <string>
using namespace std;

struct ListNode
{
	string item;
	int count =0;
	ListNode *next;
	ListNode *prev;
	
	ListNode(string item1, int count1, ListNode *prev1 = NULL, ListNode *next1 = NULL)
	{
		item = item1;
		next = next1;
		count = count1;
		prev = prev1;
	}
};
class DbLinkedList
{
public:


	DbLinkedList();
	// Purpose: Constructor
	// Returns: another node in the list

	DbLinkedList(DbLinkedList & other);
	// Purpose: Copy  constructor

	void clearList();
	// Purpose: Make the list empty
	// Returns: A head node which points to null

	bool isFull() const;
	// Purpose: To determine if the list is full
	// Returns: False as dynamic list is never full

	bool isEmpty() const;
	// Purpose: To determine if the list is empty
	// Returns: True if the list is empty and false otherwise

	int getLength() const;
	// Purpose: To find the length of the list
	// Returns: The number of items in the list

	void insertItem(const string & item);
	//Purpose: Inserts the item in the Doubly Linked list in the proper place     
	//Returns: The list with the item inserted current position will be 
	//			at the item inserted

	bool searchItem(const string & item);
	// Purpose: To locate an item in the list.
	// Returns: True if item found in Unsorted list or false otherwise
	//         current position will be at the item if found

	void removeItem(const string & item);
	// Purpose: Removes the first occurrence of the item from the Doubly Linked list.
	// Returns: The List without one occurence of the item & the current position
	//			will be at the item after the item removed, otherwise it will be at the end.

	void resetList();
	// Purpose: To set the current position to the first item in the list if there is one
	// Returns: 

	bool atEnd();
	// Purpose: 
	// Returns: True if current position is at the end of the list

	void getNext(string & item, int & count);
	//Returns: The item that the current position is at, if current position
	//         is at a item AND  the current position is advanced to the next item

	~DbLinkedList();
	//Destructs the list

	//virtual string toString();
	//returns the string representation of the items in the list


private:

	string word;
	int length;
	ListNode *current;
	ListNode *head;
};


