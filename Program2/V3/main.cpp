/********************************************************************
 **        NAME:         Srizan Gangol         USERID:sg0440      	**
 **        ASSIGNMENT:   CSCE2110		  				            **
 **        DESCRIPTION:  Main File                                  **
 **        Project:      HashTable Program {Program 1}              **
 **        Email:        SrizanGangol@my.unt.edu                    **
 **         														**
 ********************************************************************/

#include "HashTable.h"


int main()
{
	// Create new nodes
	//*****************START*****************
	Node *A = new Node;
	A -> key = 1;
	A -> next = NULL;
	A -> ID = 1;
	A -> GPA = 3.0;
	A -> Major = "CS";

    Node * B = new Node; 
	B -> key = 2;
	B -> next = NULL;
	B -> ID = 2;
	B -> GPA = 2.9;
	B -> Major = "CS";
	
    Node * C = new Node; 
	C -> key = 3; 
	C -> next = NULL;
	C -> ID = 3;
	C -> GPA = 3.5;
	C -> Major = "CS";

	//*****************DONE*****************
	std::cout << "1\n";
	//Create new (empty) hash table
    HashTable table;
	std::cout << "2\n";
    
	//Insert some data
    table.insert(A);
    table.insert(B);
    table.insert(C);
	std::cout << "3\n";
	
	//NOTE: The given hash function is not a good hash function
	//		You are required to research and submit your own
	//		Don't forget to properly cite your resource(s)
	
	//Show Update
    table.printBucketValues();
    table.printHistogram();
    
	//Remove a Node
    //TODO: Given a value, remove it from the hash table (if it exists)
	table.remove(1);
		
	//Show Update
    table.printBucketValues();
    table.printHistogram();
	
	//TODO: Insert the rest of our data

	for(int i=4; i<=26; i++)
	{
        Node * N = new Node; 
	    N -> key = i; 
	    N -> next = NULL;
	    N -> ID = i;
	    N -> GPA = ((i-13)/13.0)+3.0;
	    N -> Major = "CS";
	    table.insert(N);
	}
	
	//Show update
    table.printBucketValues();
    table.printHistogram();
	
	
	//Perform a LookUp and Print the node to the screen
	int randStudentID=19;	// No more cin :) #HardCoded
	
	
    std::cout << "Looking up Student " << randStudentID << " \n" ;
    Node *N = table.lookUp(randStudentID);

    if(N!=NULL)
    {
        std::cout << "Student " << randStudentID <<" FOUND! Printing out Student " << randStudentID << " Data:\n";
        std::cout << "ID: "<< N->ID << "\n";
        std::cout << "GPA: " << N->GPA <<"\n";
        std::cout << "Major: "<< N->Major <<"\n";
    }
    else
    {
        std::cout << "Student " << randStudentID << " NOT FOUND!\n";
	}
    return 0;
}
