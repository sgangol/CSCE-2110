/********************************************************************
 
 *	Author:			Srizan Gangol
 *	Email:			SrizanGangol@my.unt.edu 
 *	Date:			11/11/2016
 *	Assignment:		CSCE 2110 Program 2
 
 *	DESCRIPTION:	HashTable Header File
		> Datastructure: Node
				- key		>int
				- ID		>int
				- GPA		>double
				- Major		>string
				
				next 		->Node
		> Class: HashTable
				- Private
					> LinkedList	-> 
					> hashlength	> int
					> HashFunction	> int FUNCTION - Returns hash value
				- Public
					> Constructor
					> De-constructor

 *	Resources:
		> LinkedList.h
		
 
 ********************************************************************/
#include "LinkedList.h"

class HashTable
{
private:
    
    LinkedList * list; 				// linked list
    
    int hashLength; 				// size of the hash table
    
    int HashFunction(int hashKey); 	//returns the hash value
    
public:
    
	//Constructor
    HashTable(int hashTableLength = 10); // Set by default 
	
	    
    void insert(Node *newNode); 		// hash insert
    
    bool remove(int hashKey); 			// hash delete
    
    Node *lookUp(int hashKey); 			// hash lookup
    
    int getLength(); 					// returns number of locations
    
    int getNumberOfNodes(); 			// returns number of nodes in the hash table
	
	void printBucketValues(); 			// detailed print of the hash table
    
    void printHistogram(); 				// higher-level view of the table
    
	//De-constructor
    ~HashTable();
};