#include "LinkedList.h"

//Constructor
LinkedList::LinkedList()
{
    head = new Node;
    head -> next = NULL;
    length = 0;
}

void LinkedList::insert(Node * newNode)
{
    // TODO
}

bool LinkedList::remove(int NodeKey)
{
    // TODO
	
    return false;
}

Node * LinkedList::getNode(int NodeKey)
{
    // TODO
}

// Prints the linked list
void LinkedList::printList()
{
    if (length == 0)
    {
        cout << "\n{ }\n";
        return;
    }
    Node *p = head;
    Node *q = head;
    cout << "\n{ ";
    while (q)
    {
        p = q;
        if (p != head)
        {
            cout << p->key; // May require more data here... (ID, GPA)
            if (p->next) cout << ", ";
            else cout << " ";
        }
        q = p->next;
    }
    cout << "}\n";
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