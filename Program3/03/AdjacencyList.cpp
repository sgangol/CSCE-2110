/********************************************************************
 
 *	Author:			Srizan Gangol
 *	Email:			SrizanGangol@my.unt.edu 
 *	Date:			12/02/2016
 *	Assignment:		CSCE 2110 Program 3
 
 *	DESCRIPTION:	AdjacencyList.cpp
		> Definning all the functions declared in AdjacencyList.h
					
 	*	Resources:	AdjacencyList.h
					->	LinkedList.h
 ********************************************************************/

#include "AdjacencyList.h"

//  Inserts a new node in the adjacency list avoiding inserting duplicates
void AdjacencyList::insert(Node *newNode)
{
    if(list->getNode(newNode->key)==NULL)
        list->insert(newNode);
}

// Deletes the given node from the list
bool AdjacencyList::remove(std::string key)
{   
    Node* p=list->getFirst();
    while(p) 
    {
        if(p->adj!=NULL)
        {
            p->adj->remove(key);
        }
        p=p->next;
    } 
    return list->remove(key);    
}

// Adds the EDGES & If the nodes do no exist, insert the nodes in the list then connected 
void AdjacencyList::addEdge(std::string keya, std::string keyb)
{
    Node *nodea,*nodeb;
    Node *na=list->getNode(keya);   	// Searches the key of first edge node 

    if(na==NULL)        				// Create the new node if doesn't exist
    {
        nodea=new Node;             
        nodea->key=keya;
        nodea->next=NULL;

        nodeb=new Node;
        nodeb->key=keyb;
        nodeb->next=NULL;
        nodeb->adj=NULL;

        nodea->adj=new LinkedList;  	// Create a new list

        nodea->adj->insert(nodeb);  	// Add node b to a 

        list->insert(nodea);        	// Add the new node
    }
    else        						// if the node was in the list, simply update the adjacency list
    {
        nodeb=new Node;
        nodeb->key=keyb;
        nodeb->next=NULL;
        nodeb->adj=NULL;
        if (na->adj==NULL)          	// if the node was disconnected
        {            
            na->adj=new LinkedList; 	// create a new adjacency list for it
        }
        na->adj->insert(nodeb);
    }   
    Node *nb=list->getNode(keyb);   	// searches in the list for key of second edge node
    if(nb==NULL)    					// the node was not on the list
    {
        nodea=new Node;
        nodea->key=keya;
        nodea->next=NULL;
        nodea->adj=NULL;

        nodeb=new Node;
        nodeb->key=keyb;
        nodeb->next=NULL;
        nodeb->adj=new LinkedList;  	// create a new adjacency list for the node
      
        nodeb->adj->insert(nodea);  	// add a to the list of nodes connected to b 

        list->insert(nodeb);    		// add the new node to the list
    }
    else        						// if the node was in the list, simply update the adjacency list
    {
        nodea=new Node;
        nodea->key=keya;
        nodea->next=NULL;
        nodea->adj=NULL;

        if (nb->adj==NULL)          	// if the node was disconnected
        {           
            nb->adj=new LinkedList;  	// create a new adjacency list for it
        }
        nb->adj->insert(nodea);
    }   
}
    
    
// Remove the Edge from the List
void AdjacencyList::removeEdge(std::string keya, std::string keyb)
{
    Node *nodea=list->getNode(keya);	// Check the legitamacy of the node a
    if(nodea!=NULL)
    {
        if(nodea->adj!=NULL)            // If the node had adjacent list
        {
            nodea->adj->remove(keyb);   // Remove b from the list
        }
    }        
    Node *nodeb=list->getNode(keyb);    // Check the legitamacy of the node b
    if(nodeb!=NULL) 
    {
        if(nodeb->adj!=NULL)        	// If the node had adjacent list
        {
            nodeb->adj->remove(keya);   // Remove a from the list
        }
    }        
}

// Returns the node provided the key
Node * AdjacencyList::lookUp(std::string hashKey)
{
    return list->getNode(hashKey);    
}

// Returns the length of the Adjacency list
int AdjacencyList::getNumberOfNodes()
{
    return list->getLength();
}

// Prints the Adjacency List
void AdjacencyList::print()
{
    cout << "\nPrinting Adjacency List:\n";
    cout << "Undirected Graph Contains "<< list->getLength() <<" nodes total\n";
    list->printList();						// Prints the List
}

// Prints the Adjacency Matrix
void AdjacencyList::printAdjacencyMatrix()
{
    cout << "\nPrinting Adjacency Matrix:\n";
	//-------------------------------------------------------------------------------
    Node *p=list->getFirst();   
    cout << "   ";
    while(p)                        						// Prints the columns
    {
        cout << p->key << " ";
        p=p->next;
    }
    cout << "\n";
	//-----------------------------------------------------------------------------//
	p=list->getFirst(); 									// Reset the pointer
	cout << "  ";									
	while (p)
    {
		cout << "--";
		p=p->next;
	}
	 cout << "- \n";										// Draws the ---------
	//-----------------------------------------------------------------------------//
	 
    p=list->getFirst();
    while(p)
    {
        cout << p->key << "| ";     						// Prints the Rows
        Node *q=list->getFirst();
        while(q)
        {
            if (p->adj!=NULL && p->adj->getNode(q->key))    // If the nodes are connected
                cout << "1 ";           					// Prints TRUE
            else                        					
                cout << "0 ";           					// Prints FALSE
            q=q->next;            
        }
        cout << "\n";
        p=p->next;
    }
	//-----------------------------------------------------------------------------//
}

// Constructor
AdjacencyList::AdjacencyList()
{
    list=new LinkedList;
}

// De-constructor
AdjacencyList::~AdjacencyList()
{
    delete list;
}
