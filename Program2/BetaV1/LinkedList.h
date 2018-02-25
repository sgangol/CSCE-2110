/********************************************************************
 
 *	Author:			Srizan Gangol
 *	Email:			SrizanGangol@my.unt.edu 
 *	Date:			11/11/2016
 *	Assignment:		CSCE 2110 Program 2
 
 *	DESCRIPTION:	LinkedList Header file File
		> Datastructure: Node
				- key		>int
				- ID		>int
				- GPA		>double
				- Major		>string
				
				next 		->Node
		> Class: LinkedList
				- Private
					> head  ->
					> lenght > int
				- Public
					> Constructor
					> De-constructor
 *	Libraries:
		<iostream>
 
 ********************************************************************/
#include <iostream>
using std::cout;
using std::endl;

// Creating a Node that will hold:
//			Student ID  	(int)
//			Student GPA 	(double)
//			Student Major 	(string)
//			Pointer 		-> NEXT node

// Defining Datastructure for Node
struct Node
{
    int 		key;
    int         ID;     // Student ID (int)
    double      GPA;    // Student GPA (double)
    std::string Major;  // Student Major (string)

    Node *next;			// Pointer to point next node
};


class LinkedList
{
private:
    Node *head; 		// to keep track of the head
    
    int length; 		// number of values in the list
    
public:
	// Constructor
    LinkedList();
    
    void insert(Node *newNode); 	// insert new node
    
    bool remove(int NodeKey); 		// remove a node
    
    Node *getNode(int NodeKey); 	// return a node
    
    void printList(); 				// print the linked list
    
    int getLength(); 				// returns length of the list
    
	// De-constructor
    ~LinkedList();
};
