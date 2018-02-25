#include "HashTable.h"
#include <string.h>
#include <stdio.h>

int main()
{
	FILE *fp; // FILE pointer to manipulate our input file i.e input.txt

	fp = fopen("input.txt", "r"); // Open input.txt in read mode

	//Create new (empty) hash table
    HashTable table;

	if(fp == NULL ) {
		// if fp is NULL after fopen(), then it means that either the file doesn't exists
		// or we don't have a permission to read it
		cout << "Error opening input.txt";
	} else {

		cout << "Opening file: input.txt...";

		while(!feof(fp)) { // execute the following statements until it's not end of file

			Node *mNode = new Node; // create a new node for the current line in the file
			// read formatted data from the current line and store it in our newNode's members
			fscanf(fp, "%u,%lf,%s", &mNode->id, &mNode->gpa, mNode->major);
			mNode->next = NULL;
			table.insert(mNode); // insert newNode to our HashTable
		}

		cout << "\nStudent records found and inserted successfully.";

	}
	
	cout << "\n\nPrinting Detailed View (Bucket per Bucket) of the Hash Table with inserted values...:";
	//Show per bucket per node view
    table.printBucketValues();
    // print High level Hash Table view
    table.printHistogram();
	
    return 0;
}