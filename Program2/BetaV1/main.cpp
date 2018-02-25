/********************************************************************
 
 *	Author:			Srizan Gangol
 *	Email:			SrizanGangol@my.unt.edu 
 *	Date:			11/11/2016
 *	Assignment:		CSCE 2110 Program 2
 
 *	DESCRIPTION:	Main File
		> Gives the size for the HashTable
		> Opens the file
		> Imports the database
		> Closes the file
		> Gives error if unsuccessful
		> Prints BucketValues
		> Prints Histogram
		> Exits the Program

 *	Resources:
		> HashTable.h
			- LinkedList.h
		> input.txt
		
		> HashTable.cpp
		> LinkedList.cpp
		
 *	Libraries:
		<cstdio>
		<cstdlib>
		<iostream>
		
			<string> - LinkedList.cpp
 
 ********************************************************************/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "HashTable.h"


int main()
{
	// Giving size to the HashTable
	HashTable table(500);			

	// Opening the input file
    FILE* f = fopen("input.txt", "r");	
	
	// if input file is successful
    if (f)
    {
		// Print out the operation being carried out
		cout << "\n\n>>> Opening File: input.txt" << endl;
        
		
		// Importing Data until end of the file #eof
		while(!feof(f)) {
            int id;
			double gpa;
            char major[15];
            if (fscanf(f, "%d,%lf,%s", &id, &gpa, major)==3) 
            {
                Node* node = new Node();
                node->GPA = gpa;
                node->ID = id;
                node->Major = major;
                node->key = id;
                node->next = NULL;
				
                table.insert(node);
            }
        }
		
		// Print out the operation success
       cout << "\n\n>>> Database imported sucessfully" << endl;
		
		// Close the file
		fclose(f);
		
		// OUTPUT
		
	    // Print out the Bucket Values
		table.printBucketValues();
        
		// Print out the Histogram
		table.printHistogram();
    }
	// In case of input failure, print our Error Message
    else
        cout << ">>>>> ERROR: Cannot open input.txt file" << endl;
	
	cout << "\n\n >>> Program END \n\n";

    // Exit the program regardless the import is succes or not	
    return 0;
}
