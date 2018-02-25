#include "HashTable.h"

// Constructor
HashTable::HashTable(int hashTableLength)
{
    if (hashTableLength <= 0) hashTableLength = 500;
    list = new LinkedList[hashTableLength];
    hashLength = hashTableLength;
}

int HashTable::HashFunction(int hashKey)
{
    return (hashKey) % hashLength;
}

void HashTable::insert(Node *newNode)
{
    int i = HashFunction(newNode->key);
    list[i].insert(newNode);
}

bool HashTable::remove(int hashKey)
{
    int i = HashFunction(hashKey);
    return list[i].remove(hashKey);
}

Node * HashTable::lookUp(int hashKey)
{
    int i = HashFunction(hashKey);
    return list[i].getNode(hashKey);
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

int HashTable::getLength()
{
    return hashLength;
}

int HashTable::getNumberOfNodes()
{
    int NodeCount = 0;
    for ( int i = 0; i < hashLength; i++ )
    {
        NodeCount += list[i].getLength();
    }
    return NodeCount;
}

// De-constructor
HashTable::~HashTable()
{
    delete [] list;
}