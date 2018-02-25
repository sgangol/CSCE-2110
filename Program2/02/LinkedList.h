#include <iostream>
using std::cout;
using std::endl;

struct Node
{
    int key;
    Node *next;
};

class LinkedList
{
private:
    Node *head;
    
    int length;
    
public:
    LinkedList();
    
    void insert(Node *newNode);
    
    bool remove(int NodeKey);
    
    Node *getNode(int NodeKey);
    
    void printList();
    
    int getLength();
    
    ~LinkedList();
};