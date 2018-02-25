/*
 * Name: Saina Baidar	EUID:SB0576
 *   File: Adjacent.cpp              
 *           Functions for Adjacent list management
 * 
 */
#include "Adjacent.h"

// gets the node given by the key
Node * AdjacentList::lookUp(std::string hashKey)
{
    return list->getNode(hashKey);    
}

//get the number of nodes in the Adjacent list
int AdjacentList::getNumberOfNodes()
{
    return list->getLength();
}

//  Inserts a new node in the Adjacent list
void AdjacentList::insert(Node *newNode)
{
    if(list->getNode(newNode->key)==NULL)
        list->insert(newNode);
}

// Deletes a node from the Adjacent list
bool AdjacentList::remove(std::string key)
{   
    Node* p=list->getFirst();
    while(p) 
    {
        if(p->Adjacent!=NULL)
        {
            p->Adjacent->remove(key);
        }
        p=p->next;
    } 
    return list->remove(key);    
}


void AdjacentList::addEdge(std::string keyX, std::string keyY)
{
    Node *nodea,*nodeb;
    Node *na=list->getNode(keyX);   // searches in the list for key of first edge node 

    if(na==NULL)        // the node was not on the list, create the new node and add it to the list
    {
        nodea=new Node;             //
        nodea->key=keyX;
        nodea->next=NULL;

        nodeb=new Node;
        nodeb->key=keyY;
        nodeb->next=NULL;
        nodeb->Adjacent=NULL;

        nodea->Adjacent=new ListData;  // create a new Adjacent list for the node

        nodea->Adjacent->insert(nodeb);  // add b to the list of nodes connected to a 

        list->insert(nodea);        // add the new node to the list
    }
    else        // if the node was in the list, simply update the Adjacent list
    {
        nodeb=new Node;
        nodeb->key=keyY;
        nodeb->next=NULL;
        nodeb->Adjacent=NULL;
        if (na->Adjacent==NULL)          // if the node was disconnected
        {            
            na->Adjacent=new ListData; // create a new Adjacent list for it
        }
        na->Adjacent->insert(nodeb);
    }   
    Node *nb=list->getNode(keyY);   // searches in the list for key of second edge node
    if(nb==NULL)    // the node was not on the list
    {
        nodea=new Node;
        nodea->key=keyX;
        nodea->next=NULL;
        nodea->Adjacent=NULL;

        nodeb=new Node;
        nodeb->key=keyY;
        nodeb->next=NULL;
        nodeb->Adjacent=new ListData;  // create a new Adjacent list for the node
      
        nodeb->Adjacent->insert(nodea);  // add a to the list of nodes connected to b 

        list->insert(nodeb);    // add the new node to the list
    }
    else        // if the node was in the list, simply update the Adjacent list
    {
        nodea=new Node;
        nodea->key=keyX;
        nodea->next=NULL;
        nodea->Adjacent=NULL;

        if (nb->Adjacent==NULL)          // if the node was disconnected
        {           
            nb->Adjacent=new ListData;  // create a new Adjacent list for it
        }
        nb->Adjacent->insert(nodea);
    }   
}
    
    
// Remove an edge
void AdjacentList::removeEdge(std::string keyX, std::string keyY)
{
    Node *nodea=list->getNode(keyX);        // verify that the node a is on the list
    if(nodea!=NULL)
    {
        if(nodea->Adjacent!=NULL)            // if the node had an Adjacent list
        {
            nodea->Adjacent->remove(keyY);   // remove b from the Adjacent list
        }
    }        
    Node *nodeb=list->getNode(keyY);    // verify that the node b is on the list
    if(nodeb!=NULL) 
    {
        if(nodeb->Adjacent!=NULL)        // if the node has an Adjacent list
        {
            nodeb->Adjacent->remove(keyX);   // remove a from the Adjacent list
        }
    }        
}

// makes a pretty print of the Adjacent list
void AdjacentList::print()
{
    cout << "\nPrinting Adjaceny List:\n";
    cout << "Undirected Graph Contains "<< list->getLength() <<" nodes total\n";
    list->printList();
}

// prints the Adjacent list as a matrix nxn, that has ones if the nodes
// are connected and 0 if they are not
void AdjacentList::printAdjacentMatrix()
{
    cout << "\nPrinting Adjaceny Matrix:\n";

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
            if (p->Adjacent!=NULL && p->Adjacent->getNode(q->key))    // if the node p is connected to q via the Adjacent list
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
AdjacentList::AdjacentList()
{
    list=new ListData;
}

// De-constructor
AdjacentList::~AdjacentList()
{
    delete list;
}
