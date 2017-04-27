// Rephael Edwards
// CMPS 3013 Program 2 - Word Count 
// WordCount.cpp
// This program reads in a paragraph and outputs each word in alphabetical
// order as well as the number of occurrences for each word.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <ctype.h>
#include "DbLinkedList.h"

using namespace std;

// Precondition: The ouput file is opened.
// Postcondition: A header is printed.
// Check: none 
void printHeader(ofstream &outfile);

// Precondition: The user enters a name for the input file.
// Postcondition: The input file is opened.
// Check: If the input file does not exist, an error message is given.
void openFileRead(ifstream& infile);

// Precondition: The user enters a name for the output.
// Postcondition: The output file is opened.
// Check: none
void openFileWrite(ofstream& outfile);

// Precondition: The input file must be opened.
// Postcondition: Each word in the document is read in and stored in 
//				  a sorted doubly linked list.
// Check: 
void readParagraph(ifstream &infile, DbLinkedList &wordList);

// Precondition: The output file is opened and the list is not empty.
// Postcondition: The contens of the linked list are printed.
// Check: None
void printOutput(ofstream & outfile, DbLinkedList &wordList);


void main()
{
	// list and file declarations
	DbLinkedList wordList;
	ifstream infile;
	ofstream outfile;

	//open files
	openFileRead(infile);
	openFileWrite(outfile);

	// function calls
	printHeader(outfile);
	readParagraph(infile, wordList);
	printOutput(outfile, wordList);
	system("pause");
}


void printHeader(ofstream &outfile)
{
	outfile << " \t\t\t Word Count \n";
	outfile << "\t\t by Rephael Edwards \n";
	outfile << "\t\t\t CMPS 3013\n\n";
	outfile << "  This program reads in a paragraph and gives an alphabetized list \n ";
	outfile << "  of each word. It also gives the number of occurrences of each word \n";
	outfile << "  in the paragraph.\n\n";
}

void openFileRead(ifstream& in)
{
	char inFileName[40];
	cout << "Enter the input file name: ";
	cin >> inFileName;
	in.open(inFileName);
	// Print an error message if file fails to open.
	if (in.fail())
	{
		cout << "Could not open file. \n";
		cout << "Check file name and location. \n\n";
		system("pause");
		exit(0);
	}
}

void openFileWrite(ofstream& out)
{
	char outFileName[40];
	cout << "Enter the output file name: ";
	cin >> outFileName;
	out.open(outFileName);
}


void readParagraph(ifstream &infile, DbLinkedList &wordList)
{
	string aWord, newWord;
	int len;
	int aNum;
	bool pMark;
	// for each word in the paragraph, read in 
	infile >> aWord;
	while (infile)
		// change to lower case
	{
		len = aWord.length();
		// ensure that all of the letters are in lower case
		for (int i = 0; i <= len; i++)
		{
			aNum = tolower(aWord[i]);
			aWord[i] = static_cast<char>(aNum);
		}

		// check for punctuation at the end of the word
		pMark = ispunct(static_cast<char>(aWord[(aWord.length() - 1)]));

		// if there is a punctuation mark, erase it and store the word
		// as a new variable to be inserted.
		if (pMark)
			newWord = aWord.erase((aWord.length() - 1));
		else
			newWord = aWord;

		// search for the word If it is not in the list then add it to the list
		if (!wordList.searchItem(newWord))
		wordList.insertItem(newWord);	

		infile >> aWord;
	}	
}

void printOutput(ofstream & outfile, DbLinkedList &wordList)
{
	int count;
	string item;
	outfile << "This is a list of the words and the number of times each occured:\n\n";
	wordList.resetList();

	while (!wordList.atEnd())
	{		
		wordList.getNext(item, count);
		outfile << item;
		outfile << "  " << count << endl;
	}
	
}