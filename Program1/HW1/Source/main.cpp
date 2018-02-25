#include "HashTable.h"

int main()
{
	// Create new nodes
	//*****************START*****************
	Node *A = new Node;
	A -> key = 1;
	A -> next = NULL;
	
    Node * B = new Node; 
	B -> key = 2;
	B -> next = NULL;
	
    Node * C = new Node; 
	C -> key = 3; 
	C -> next = NULL;
	//*****************DONE*****************
	
	//Create new (empty) hash table
    HashTable table;
    
	//Insert some data

	
	//NOTE: The given hash function is not a good hash function
	//		You are required to research and submit your own
	//		Don't forget to properly cite your resource(s)
	
	//Show Update
    table.printBucketValues();
    table.printHistogram();
    
	//Remove a Node
    //TODO: Given a value, remove it from the hash table (if it exists)
	
	//Show Update
    table.printBucketValues();
    table.printHistogram();
	
	//TODO: Insert the rest of our data
	
	//Show update
    table.printBucketValues();
    table.printHistogram();
	
	//Perform a LookUp and Print the node to the screen
	
    return 0;
}