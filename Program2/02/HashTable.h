#include "LinkedList.h"

class HashTable
{
private:
    
    LinkedList * list; // linked list
    
    int hashLength; // size of the hash table
    
    int HashFunction(int hashKey); //returns the hash value
    
public:
    
	//Construct
    HashTable(int hashTableLength = 20); // Set to 20 by default
    
    void insert(Node *newNode); // hash insert
    
    bool remove(int hashKey); // hash delete
    
    Node *lookUp(int hashKey); // hash lookup
    
    void printBucketValues(); // detailed print of the hash table
    
    void printHistogram(); // higher-level view of the table
    
    int getLength(); // returns number of locations
    
    int getNumberOfNodes(); // returns number of nodes in the hash table
    
	//De-construct
    ~HashTable();
};