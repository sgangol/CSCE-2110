/********************************************************************
 
 *	Author:			Srizan Gangol
 *	Email:			SrizanGangol@my.unt.edu 
 *	Date:			11/11/2016
 *	Assignment:		CSCE 2110 Program 2
 
 *	DESCRIPTION:	HashTable CPP File
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
		> HashTable.h
			- LinkedList.h	
		
 
 ********************************************************************/
#include "HashTable.h"

void HashTable::insert(Node *newNode)
{
    int position=(unsigned)HashFunction(newNode->key) % hashLength;    

    list[position].insert(newNode);    
}

int HashTable::HashFunction(int hashKey)
{
    return (hashKey) % hashLength;
}

bool HashTable::remove(int hashKey)
{
    int position=(unsigned)HashFunction(hashKey) % 10;    
    return list[position].remove(hashKey);    
}

Node * HashTable::lookUp(int hashKey)
{
    int position=(unsigned)HashFunction(hashKey) % 10;    
    return list[position].getNode(hashKey);    
}


// Function to get number of the Nodes
int HashTable::getNumberOfNodes()
{
    int NodeCount = 0;
    for ( int i = 0; i < hashLength; i++ )
    {
        NodeCount += list[i].getLength();
    }
    return NodeCount;
}

// Function to Print Bucket Values
void HashTable::printBucketValues()
{
	cout << "\n\n>> Printing Detailed View (Bucket per Bucket) of the Hash Table with inserted values..:" << endl;
	
    cout << "\n\n> Hash Table Bucket Values:\n";
    
	// Print until the end of the length
	for ( int i = 0; i < hashLength; i++ )
    {
        cout << "Bucket " << i + 1 << ": ";
        list[i].printList();
    }
}

// Function to Print Histogram
void HashTable::printHistogram()
{
    cout << "\n\n>> Printing High-Level View of the Hash Table..:" << endl;
	cout << "\n\n> Hash Table Contains ";
    cout << getNumberOfNodes() << " Nodes total\n";
    for ( int i = 0; i < hashLength; i++ )
    {
        cout << i + 1 << ":\t";
        for ( int j = 0; j < list[i].getLength(); j++ )
            cout << " O";
        cout << "\n";
    }
}

// Constructor
HashTable::HashTable(int hashTableLength)
{
    if (hashTableLength <= 0) hashTableLength = 10;
    list = new LinkedList[hashTableLength];
    hashLength = hashTableLength;
}

// De-constructor
HashTable::~HashTable()
{
    delete [] list;
}
