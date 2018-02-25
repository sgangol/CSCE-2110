/********************************************************************
 
 *	Author:			Srizan Gangol
 *	Email:			SrizanGangol@my.unt.edu 
 *	Date:			12/02/2016
 *	Assignment:		CSCE 2110 Program 3
 
 *	DESCRIPTION:	LinkedList.cpp           
		>	Linked list function definitions
				

 
 ********************************************************************/

#include "LinkedList.h"

//Constructor
LinkedList::LinkedList()
{
    head = new Node;
    head -> next = NULL;
    head -> adj = NULL;
    length = 0;
}

void LinkedList::insert(Node * newNode)
{
    if (getNode(newNode->key)!=NULL)
        return;
    Node *p = head;
    while (p->next)
    {
        p = p->next;
    }
    p->next=newNode;
    p->next->next=NULL;
    length++;
}

bool LinkedList::remove(std::string NodeKey)
{
    if (length == 0)
    {
        return false;
    }
    Node *p = head;
    Node *q = head;
    while (q)
    {
        if (q != head)
        {
            if(q->key==NodeKey)
            {
                p->next=q->next;
                delete q;
                length--;
                return true;
            }
        }
        p = q;
        q = p->next;
    }

    return false;
}

Node * LinkedList::getNode(std::string NodeKey)
{
    if (length == 0)
    {
        return NULL;
    }
    Node *p = head;
    Node *q = head;
    while (q)
    {
        p = q;
        if (p != head)
        {
            if(p->key==NodeKey)
                return p;
        }
        q = p->next;
    }
    return NULL;
}

// Prints the linked list
void LinkedList::printList(int sub)
{
    if (length == 0 && !sub)
    {
        //cout << "\n{ }\n";
        return;
    }
    Node *p = head;
    Node *q = head;
    while (q)
    {
        if (q != head)
        {
            cout << q->key ;
            if(!sub)
            {
                cout << ":\t";
                if(q->adj) q->adj->printList(1);
                std::cout << endl;
            }
            else 
                cout<< " ";
        }
        q = q->next;
    }
}

// Get and Return length of the list
int LinkedList::getLength()
{
    return length;
}

// De-Constructor
LinkedList::~LinkedList()
{
    Node *p = head;
    Node *q = head;
    while (q)
    {
        p = q;
        q = p->next;
        if (q) delete p;
    }
}
