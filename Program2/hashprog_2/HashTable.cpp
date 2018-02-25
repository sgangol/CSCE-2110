#include "HashTable.h"

void HashTable::insert(Node *newNode)
{
    // TODO
    int hash = this->HashFunction(newNode->id);
    list[hash].insert(newNode);

}


// HashFunction to calculate the hashKey for a given hash value
unsigned int HashTable::HashFunction(unsigned int hashKey) {

    return (hashKey) % hashLength;
}


// Removes a Node from the HashTable having the specified hashKey (for us, hashKey is the Student ID)
// Returns true if the removal was successfuly, otherwise false.
bool HashTable::remove(int hashKey)
{
    int hash = this->HashFunction(hashKey);
    list[hash].remove(hashKey);
}


// Searches the HashTable for hashKey and returns the node containing hashKey
Node * HashTable::lookUp(int hashKey)
{
    int hash = HashFunction(hashKey);
    Node *mNode = list[hash].getNode(hashKey);
    return mNode;
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
        cout << "\nBucket " << i + 1 << ": ";
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