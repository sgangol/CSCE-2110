#include "HashTable.h"

void HashTable::insert(Node *newNode)
{        

    int index = HashFunction(newNode->id);

    if (!list[index].getNode(newNode->id))
        list[index].insert(newNode);    
}

// DONE: Research and input a better hash function!
int HashTable::HashFunction(int hashKey)
{
    unsigned int x = hashKey;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;

    return (int)(x % hashLength); // Resource of hash function used: 
    // http://stackoverflow.com/questions/664014/what-integer-hash-function-are-good-that-accepts-an-integer-hash-key
}

bool HashTable::remove(int hashKey)
{    
    int index = HashFunction(hashKey);
    return list[index].remove(hashKey);
}

Node * HashTable::lookUp(int hashKey)
{    
    int index = HashFunction(hashKey);
    return list[index].getNode(hashKey);
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