/*
 * Name: Saina Baidar	EUID:SB0576
 *   File: ListData.cpp              
 *           Linked list function definitions
 * 
 */
#include "ListData.h"

//Constructor
ListData::ListData()
{
    head = new Node;
    head -> next = NULL;
    head -> Adjacent = NULL;
    length = 0;
}

void ListData::insert(Node * newNode)
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

bool ListData::remove(std::string NodeKey)
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

Node * ListData::getNode(std::string NodeKey)
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
void ListData::printList(int sub)
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
                if(q->Adjacent) q->Adjacent->printList(1);
                std::cout << endl;
            }
            else 
                cout<< " ";
        }
        q = q->next;
    }
}

// Get and Return length of the list
int ListData::getLength()
{
    return length;
}

// De-Constructor
ListData::~ListData()
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
