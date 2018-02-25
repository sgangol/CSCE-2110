#include <string>
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
    // DONE
    newNode->next = head->next;
    head->next = newNode;                    
    length++;
}

bool LinkedList::remove(int NodeKey)
{
    Node* node = head->next;
    Node* prevNode = head;
    while(node) 
    {
        if (node->id==NodeKey)
        {
            if (prevNode)
            {
                prevNode->next = node->next;
                delete node;
            }            
            length--;
            return true;
        }

        prevNode = node;
        node = node->next;
    }
	
    return false;
}

Node * LinkedList::getNode(int NodeKey)
{    
    if (length>0)
    {
        Node* node = head->next;    
        while(node) 
        {
            if (node->id==NodeKey)
                return node;


            node = node->next;
        }
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
            cout << "ID: " << p->id;
            cout << ",GPA: " << p->GPA;
            cout << ",Major: " << p->major;

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