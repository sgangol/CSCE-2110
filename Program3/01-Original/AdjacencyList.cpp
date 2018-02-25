/*
 *   File: AdjacencyList.cpp              
 *           Functions for adjacency list management
 * 
 */
#include "AdjacencyList.h"

//  Inserts a new node in the adjacency list
// avoids inserting duplicates
void AdjacencyList::insert(Node *newNode)
{
    if(list->getNode(newNode->key)==NULL)
        list->insert(newNode);
}

// Deletes a node from the adjacency list
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

// adds an edge between two nodes referenced by their keys,
// if they are not in the adjacency list, the nodes are inserted
// and the corresponding adjacency lists for the nodes are created
// accordingly
void AdjacencyList::addEdge(std::string keya, std::string keyb)
{
    Node *nodea,*nodeb;
    Node *na=list->getNode(keya);   // searches in the list for key of first edge node 

    if(na==NULL)        // the node was not on the list, create the new node and add it to the list
    {
        nodea=new Node;             //
        nodea->key=keya;
        nodea->next=NULL;

        nodeb=new Node;
        nodeb->key=keyb;
        nodeb->next=NULL;
        nodeb->adj=NULL;

        nodea->adj=new LinkedList;  // create a new adjacency list for the node

        nodea->adj->insert(nodeb);  // add b to the list of nodes connected to a 

        list->insert(nodea);        // add the new node to the list
    }
    else        // if the node was in the list, simply update the adjacency list
    {
        nodeb=new Node;
        nodeb->key=keyb;
        nodeb->next=NULL;
        nodeb->adj=NULL;
        if (na->adj==NULL)          // if the node was disconnected
        {            
            na->adj=new LinkedList; // create a new adjacency list for it
        }
        na->adj->insert(nodeb);
    }   
    Node *nb=list->getNode(keyb);   // searches in the list for key of second edge node
    if(nb==NULL)    // the node was not on the list
    {
        nodea=new Node;
        nodea->key=keya;
        nodea->next=NULL;
        nodea->adj=NULL;

        nodeb=new Node;
        nodeb->key=keyb;
        nodeb->next=NULL;
        nodeb->adj=new LinkedList;  // create a new adjacency list for the node
      
        nodeb->adj->insert(nodea);  // add a to the list of nodes connected to b 

        list->insert(nodeb);    // add the new node to the list
    }
    else        // if the node was in the list, simply update the adjacency list
    {
        nodea=new Node;
        nodea->key=keya;
        nodea->next=NULL;
        nodea->adj=NULL;

        if (nb->adj==NULL)          // if the node was disconnected
        {           
            nb->adj=new LinkedList;  // create a new adjacency list for it
        }
        nb->adj->insert(nodea);
    }   
}
    
    
// Remove an edge between a pair of nodes given by their keys
// since the graph is undirected, it also removes the edge that goes
// from b to a
void AdjacencyList::removeEdge(std::string keya, std::string keyb)
{
    Node *nodea=list->getNode(keya);        // verify that the node a is on the list
    if(nodea!=NULL)
    {
        if(nodea->adj!=NULL)            // if the node had an adjacency list
        {
            nodea->adj->remove(keyb);   // remove b from the adjacency list
        }
    }        
    Node *nodeb=list->getNode(keyb);    // verify that the node b is on the list
    if(nodeb!=NULL) 
    {
        if(nodeb->adj!=NULL)        // if the node has an adjacency list
        {
            nodeb->adj->remove(keya);   // remove a from the adjacency list
        }
    }        
}

// gets the node given by the key
Node * AdjacencyList::lookUp(std::string hashKey)
{
    return list->getNode(hashKey);    
}

//get the number of nodes in the adjacency list
int AdjacencyList::getNumberOfNodes()
{
    return list->getLength();
}

// makes a pretty print of the adjacency list
void AdjacencyList::print()
{
    cout << "\nPrinting Adjacency List:\n";
    cout << "Undirected Graph Contains "<< list->getLength() <<" nodes total\n";
    list->printList();
}

// prints the adjacency list as a matrix nxn, that has ones if the nodes
// are connected and 0 if they are not
void AdjacencyList::printAdjacencyMatrix()
{
    cout << "\nPrinting Adjacency Matrix:\n";

    Node *p=list->getFirst();   
    cout << "   ";
    while(p)                        // print the table header with the names of the nodes for the columns
    {
        cout << p->key << " ";
        p=p->next;
    }
    cout << "\n";
    
    p=list->getFirst();
    while(p)
    {
        cout << p->key << "  ";     // print the table header with the name of the node for this row
        Node *q=list->getFirst();
        while(q)
        {
            if (p->adj!=NULL && p->adj->getNode(q->key))    // if the node p is connected to q via the adjacency list
                cout << "1 ";           // print a 1
            else                        // if they are not connected
                cout << "0 ";           // print a 0
            q=q->next;            
        }
        cout << "\n";
        p=p->next;
    }
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
