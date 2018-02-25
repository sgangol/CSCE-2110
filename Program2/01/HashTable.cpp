/********************************************************************
 **        NAME:         Srizan Gangol         USERID:sg0440      	**
 **        ASSIGNMENT:   CSCE2110		  				            **
 **        DESCRIPTION:  HashTable CPP File                         **
 **        Project:      HashTable Program {Program 1}              **
 **        Email:        SrizanGangol@my.unt.edu                    **
 **         														**
 ********************************************************************/


#include "HashTable.h"

void HashTable::insert(Node *newNode)
{
    int position=(unsigned)HashFunction(newNode->key) % 500;    

    list[position].insert(newNode);    
}

// HashFunction reinstated to Original
int HashTable::HashFunction(int hashKey)
{
    return (hashKey) % hashLength;
}

bool HashTable::remove(int hashKey)
{
    int position=(unsigned)HashFunction(hashKey) % 500;    
    return list[position].remove(hashKey);    
}

Node * HashTable::lookUp(int hashKey)
{
    int position=(unsigned)HashFunction(hashKey) % 500;    
    return list[position].getNode(hashKey);    
}

// ********** YOU DO NOT NEED TO CHANGE THE BELOW CODE! **********

// ********** YOU DO NOT NEED TO CHANGE THE BELOW CODE! **********

// insert function is given


// Below are functions I used to print my values to the screen
int HashTable::getNumberOfNodes()
{
    int NodeCount = 0;
    for ( int i = 0; i < hashLength; i++ )
    {
        NodeCount += list[i].getLength();
    }
    return NodeCount;
}

void HashTable::printBucketValues()
{
    cout << "\n\nHash Table Bucket Values:\n";
    for ( int i = 0; i < hashLength; i++ )
    {
        cout << "Bucket " << i + 1 << ": ";
        list[i].printList();
    }
}

void HashTable::printHistogram()
{
    cout << "\n\nHash Table Contains ";
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
    if (hashTableLength <= 0) hashTableLength = 500;
    list = new LinkedList[hashTableLength];
    hashLength = hashTableLength;
}

// De-constructor
HashTable::~HashTable()
{
    delete [] list;
}
