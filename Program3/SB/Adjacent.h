/*
 * Name: Saina Baidar	EUID:SB0576
 *   File: Adjacent.h              
 *           Adjacent list header file 
 * 
 */
#include "ListData.h"

class AdjacentList
{
private:
    
    ListData *list; 				// linked list for saving the Adjacent list
         
public:
    
	//Constructor
    AdjacentList();
    
    void insert(Node *node); 		// insert node
    
    bool remove(std::string key); 	// delete node
    
    Node *lookUp(std::string key); 	// lookup the node key
    
    int getNumberOfNodes(); 		// returns number of nodes in the hash table	
   
    void print();   				// higher-level view of the Adjacent list
  
    void printAdjacentMatrix();    	// print the Adjacent matrix for the current list
    
    void addEdge(std::string keyX, std::string keyY);   	// add an edge between two nodes
    
    void removeEdge(std::string keyX, std::string keyY);    // removes an edge between two nodes
    
	//De-constructor
    ~AdjacentList();
};
