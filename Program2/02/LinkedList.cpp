#include "LinkedList.h"

LinkedList::LinkedList()
{
    head = new Node;
    head -> next = NULL;
    length = 0;
}

void LinkedList::insert(Node * newNode)
{
    if (!head -> next)
    {
        head -> next = newNode;
        length++;
        return;
    }
    Node *p = head;
    Node *q = head;
    while (q)
    {
        p = q;
        q = p -> next;
    }
    p->next = newNode;
    newNode->next = NULL;
    length++;
}

bool LinkedList::remove(int NodeKey)
{
    if (!head->next) return false;
    Node*p = head;
    Node*q = head;
    while (q)
    {
        if (q->key == NodeKey)
        {
            p->next = q->next;
            delete q;
            length--;
            return true;
        }
        p = q;
        q = p->next;
    }
    return false;
}

Node * LinkedList::getNode(int NodeKey)
{
    Node *p = head;
    Node *q = head;
    while (q)
    {
        p = q;
        if ((p != head) && (p->key == NodeKey))
            return p;
        q = p->next;
    }
    return NULL;
}

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
            cout << p->key;
            if (p->next) cout << ", ";
            else cout << " ";
        }
        q = p->next;
    }
    cout << "}\n";
}

int LinkedList::getLength()
{
    return length;
}

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