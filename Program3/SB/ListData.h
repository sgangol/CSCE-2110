/*
 * Name: Saina Baidar	EUID:SB0576
 *   File: ListData.h              
 *           Linked list header file 
 * 
 */

#include <iostream>
#include <cstring>
using std::cout;
using std::endl;

class ListData;

struct Node
{
    std::string key;
    ListData *Adjacent;
    Node *next;
};

class ListData
{
private:
    Node *head; 			// to keep track of the head
    
    int length; 			// number of values in the list
    
public:
	// Constructor
    ListData();
    
    void insert(Node *newNode); 		// insert new node
    
    bool remove(std::string NodeKey); 	// remove a node
    
    Node *getNode(std::string NodeKey); // return a node
    
    void printList(int sub);			// print the linked list
    void printList()        			// print the linked list
    {
        printList(0);
    }
    
    int getLength(); 					// returns length of the list
    
    Node* getFirst()       				// returns a pointer to the first element in the list
    {
        return head->next;
    }
    
	// De-constructor
    ~ListData();
};
