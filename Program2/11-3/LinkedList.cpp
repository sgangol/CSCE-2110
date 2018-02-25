
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
    Node *p = head;
    while (p->next)
    {
        p = p->next;
    }
    p->next=newNode;
    p->next->next=NULL;
    length++;
}

bool LinkedList::remove(int NodeKey)
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

Node * LinkedList::getNode(int NodeKey)
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
            cout << "(" << p->ID << ","; 
            cout << p->GPA << ","; 
            cout << p->Major << ")";

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
