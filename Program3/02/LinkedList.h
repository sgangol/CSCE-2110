/********************************************************************
 
 *	Author:			Srizan Gangol
 *	Email:			SrizanGangol@my.unt.edu 
 *	Date:			12/02/2016
 *	Assignment:		CSCE 2110 Program 3
 
 *	DESCRIPTION:	LinkedList.h               
		>	Linked list header file 
				
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
    Node *head;		// to keep track of the head
    
    int length; 	// number of values in the list
    
public:
	// Constructor
    LinkedList();
    
    void insert(Node *newNode); 		// insert new node
    
    bool remove(std::string NodeKey); 	// remove a node
    
    Node *getNode(std::string NodeKey); // return a node
    
    void printList(int sub); // print the linked list
    void printList()         // print the linked list
    {
        printList(0);
    }
    
    int getLength(); 		// returns length of the list
    
    Node* getFirst()        // returns a pointer to the first element in the list
    {
        return head->next;
    }
    
	// De-constructor
    ~LinkedList();
};
