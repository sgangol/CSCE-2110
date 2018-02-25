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
    int position=(unsigned)HashFunction(newNode->key) % 10;    

    list[position].insert(newNode);    
}

int HashTable::HashFunction(int hashKey)
{
// Resource of hash function used:
// Integer Hash Function, Thomas Wang, Jan 1997 
// https://gist.github.com/badboy/6267743
//    
  int c2=0x27d4eb2d; // a prime or an odd constant
  hashKey = (hashKey ^ 61) ^ (hashKey >> 16);
  hashKey = hashKey + (hashKey << 3);
  hashKey = hashKey ^ (hashKey >> 4);
  hashKey = hashKey * c2;
  hashKey = hashKey ^ (hashKey >> 15);
  return hashKey;
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
    if (hashTableLength <= 0) hashTableLength = 10;
    list = new LinkedList[hashTableLength];
    hashLength = hashTableLength;
}

// De-constructor
HashTable::~HashTable()
{
    delete [] list;
}
