// Rephael Edwards
// CMPS 3013
// File: DbLinked List.cpp - Implements DbLinkedList.h

#include <iostream>
#include "DbLinkedList.h"


DbLinkedList::DbLinkedList()
{
	length = 0;
	current = NULL;
	head = NULL;
}

// copy constructor
DbLinkedList::DbLinkedList(DbLinkedList & other)
{
	int count;
	string item;

	length = 0;
	current = NULL;
	head = NULL;

	other.resetList();
	resetList();
	while (!(other.atEnd())){
		other.getNext(item, count);
		insertItem(item);
	}
}


void DbLinkedList::clearList()
{
	ListNode *next; 
	ListNode *prev;

	current = head;
	while (current != NULL)
	{
		prev = current;
		current = current->next;
		delete prev;
		length--;
	}

	head = NULL;
}

bool DbLinkedList::isFull() const
{
	return false;
}

bool DbLinkedList::isEmpty() const
{
	if (length == 0)
		return true;
	else
		return false;
}

int DbLinkedList::getLength() const
{
	return length;
}

void DbLinkedList::insertItem(const string & item)
{
	ListNode *newNode;
	newNode = new ListNode(item, 1, NULL, NULL);

	if (head == NULL)
	{
		head = newNode;
		current = head;		
		current->next = NULL;				
	}

	// if the item needs to be inserted at the beginning
	else if (head->item > item)
	{
		current = head;
		head = newNode;
		head->next = current;
		current->prev = head;
	}
	else
	{
		current = head;
		// if there is something in the list check and advance the pointer	
		while (current->next != NULL && current->next->item < item)
		{
			current = current->next;
		}
		// if the next position is NULL
		if (current->next == NULL)
		{
			newNode->next = current->next;
			current->next = newNode;
			newNode->prev = current;
		}
		//if a node is found that is > the item to be inserted
		else
		{
			// insert the item between this node and the previous one
			newNode->next = current->next;
			newNode->prev = current;
			current->next = newNode;
			current = newNode->next;
			current->prev = newNode;
		}		
	}	
	length++;
}

bool DbLinkedList::searchItem(const string & item)
{
	bool found = false;
	current = head;

	while (!found && !atEnd())
	{
		if (current->item == item)
		{
			found = true;
			current->count++;
		}
			
		else
			current = current->next;
	}

	return found;
}

void DbLinkedList::removeItem(const string & item)
{
	ListNode *prev = NULL;

	//if the list is empty, do nothing
	if (!head)
		return;

	//Determine if the first node is the one to delete
	if (head->item == item)
	{
		current = head;
		head = head->next;
		delete current;
		current = head;
	}
	else
	{
		current = head;


		//skip all nodes whose item member is not equal to item
		while (current != NULL && current->item != item)
		{
			prev = current;
			current = current->next;
		}
		//link the previous node to the node after current, then delete currrent
		if (current)
		{
			//update next field of previous node 
			prev->next = current->next;
			//delete the current node 
			delete current;
			//update the current pointer
			current = prev;			
		}
	}
	length--;
}

void DbLinkedList::resetList()
{
	current = head;
}

void DbLinkedList::getNext(string & item, int & count)
{
	if (current == NULL)
		cout << "ERROR: You are at the end of the list.";
	else
	{
		item = current->item;
		count = current->count;
		current = current->next;
	}
}

bool DbLinkedList::atEnd()
{
	if (current == NULL)
		return true;
	else
		return false;
}

DbLinkedList::~DbLinkedList()
{
	clearList();
	length = -1;
}