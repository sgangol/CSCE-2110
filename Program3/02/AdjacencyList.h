/********************************************************************
 
 *	Author:			Srizan Gangol
 *	Email:			SrizanGangol@my.unt.edu 
 *	Date:			12/02/2016
 *	Assignment:		CSCE 2110 Program 3
 
 *	DESCRIPTION:	AdjacencyList.h              
		>	Adjacency list header file 
				
		
		
 
 ********************************************************************/

#include "LinkedList.h"

class AdjacencyList
{
private:
    
    LinkedList *list; // linked list for saving the adjacency list
         
public:
    
	//Constructor
    AdjacencyList();
    
    void insert(Node *node); // insert node
    
    bool remove(std::string key); // delete node
    
    Node *lookUp(std::string key); // lookup the node key
    
    int getNumberOfNodes(); // returns number of nodes in the hash table	
   
    void print();   // higher-level view of the adjacency list
  
    void printAdjacencyMatrix();    // print the adjacency matrix for the current list
    
    void addEdge(std::string keya, std::string keyb);   // add an edge between two nodes
    
    void removeEdge(std::string keya, std::string keyb);    // removes an edge between two nodes
    
	//De-constructor
    ~AdjacencyList();
};
