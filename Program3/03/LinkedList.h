/********************************************************************
 
 *	Author:			Srizan Gangol
 *	Email:			SrizanGangol@my.unt.edu 
 *	Date:			12/02/2016
 *	Assignment:		CSCE 2110 Program 3
 
 *	DESCRIPTION:	LinkedList.h               
		>	The main header file
		#	iostream
		#	cstring
		using std::cout
		using std::endl
		
		> Struct
			- Key ->String
			-*adj
			-*next
		> Class: LinkedList
		
 ********************************************************************/


#include <iostream>
#include <cstring>
using std::cout;
using std::endl;

class LinkedList;

struct Node
{
    std::string key;
    LinkedList *adj;
    Node *next;
};

class LinkedList
{
private:
    Node *head;		// Tracks Head
    
    int length; 	// Length of the LIST
    
public:
	// Constructor
    LinkedList();
    
    void insert(Node *newNode); 		// Inserts the new node
    
    bool remove(std::string NodeKey); 	// Removes a node
    
    Node *getNode(std::string NodeKey); // Returns the node
    
    void printList(int sub); 			// Prints the linked list
    void printList()         			// Prints the linked list
    {
        printList(0);
    }
    
    int getLength(); 					// Returns the length
    
    Node* getFirst()        			// Resets the pointer to the first 
    {
        return head->next;
    }
    
	// De-constructor
    ~LinkedList();
};
