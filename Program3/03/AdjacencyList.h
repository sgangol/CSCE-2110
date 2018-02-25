/********************************************************************
 
 *	Author:			Srizan Gangol
 *	Email:			SrizanGangol@my.unt.edu 
 *	Date:			12/02/2016
 *	Assignment:		CSCE 2110 Program 3
 
 *	DESCRIPTION:	AdjacencyList.h
		>	Class 
			-LinkedList *list [Private]
			-Constructor
			---Function Declaration---
			-insert()
			-remove()
			-*lookUp
			-getNumberOfNodes()
			-print()
			-printAdjacencyMatrix()
			-addEdge()
			-removeEdge()
			---------------------------
			-De-constructor
		
	*	Resources:	LinkedList.h	
 
 ********************************************************************/

#include "LinkedList.h"

class AdjacencyList
{
private:
    
    LinkedList *list; 				// LinkedList for the adjacency List
         
public:
    
	//Constructor
    AdjacencyList();
    
	// FUNCTION Declaration----------------------------------------------------------------------
    void insert(Node *node); 		// Inserts a node
    
    bool remove(std::string key); 	// Deletes the node
    
    Node *lookUp(std::string key); 	// Looks up the Key for the Node
    
    int getNumberOfNodes(); 		// returns number of nodes in the hashtable	
   
    void print();   				// Prints the higher-level view
  
    void printAdjacencyMatrix();    // Prints the Adjacency matrix
    
    void addEdge(std::string keya, std::string keyb);   	// Adds the Nodes
    
    void removeEdge(std::string keya, std::string keyb);    // Removes the EDGE
    //-------------------------------------------------------------- FUNCTION Declaration END--/
	
	//De-constructor
    ~AdjacencyList();
};
