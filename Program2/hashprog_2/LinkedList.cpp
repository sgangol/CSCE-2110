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
    if(newNode)
    {
        // insert newNode if it is not null
        Node *lastNode = head;
        // Find the last node in this LinkedList
        while(lastNode->next != NULL)
            lastNode = lastNode->next;

        lastNode->next = newNode;
        this->length++;
    }
}

bool LinkedList::remove(int NodeKey)
{
    // TODO
    if(length == 0)
        return false;
    Node *prev = head;
    Node *curr = head->next;
    while(curr != NULL) 
    {
        if(curr->id == NodeKey)
        {
            prev->next = curr->next;
            delete curr;
            length--;
            return true;

        }
        prev = curr;
        curr = curr->next;
    }
	
    return false;
}

Node * LinkedList::getNode(int NodeKey)
{
    Node *curr = head->next;
    while(curr != NULL) {
        if(curr->id == NodeKey)
            return curr;
        curr = curr->next;
    }
    return NULL;
}

// Prints the linked list
void LinkedList::printList() {
    if (length == 0) {
        cout << "\n{ }\n";
        return;
    }

    Node *curr = head->next;
    cout << "\n{\n";

    while (curr != NULL) {
    
       // cout << "[ ID = " << curr->id << " | GPA = " << curr->gpa << " | Major = " << curr->major << " ]";
        cout <<"\t"<< curr->id << ", " << curr->gpa << ", " << curr->major;
        if (curr->next) cout << "\n";
            else cout << " ";
        curr = curr->next;
    }

    cout << "\n}\n";
}

// Get and Return length of the list
int LinkedList::getLength() {
    return length;
}

// De-Constructor
LinkedList::~LinkedList() {
    Node *p = head;
    Node *q = head;
    while (q) {
        p = q;
        q = p->next;
        if (q) delete p;
    }
}