
#include <iostream>
using std::cout;
using std::endl;

// TODO: Create a Node that will hold:
//			Student ID (int)
//			Student GPA (double)
//			Student Major (string)
//			Pointer to the next node
struct Node
{
    int 		key;	// key
    int         ID;     // Student ID (int)
    double      GPA;    // Student GPA (double)
    std::string Major;  // Student Major (string)

    Node *next;
};


class LinkedList
{
private:
    Node *head; 				// to keep track of the head
    
    int length; 				// number of values in the list
    
public:
	// Constructor
    LinkedList();
    
    void insert(Node *newNode); 	// insert new node
    
    bool remove(int NodeKey); 		// remove a node
    
    Node *getNode(int NodeKey); 	// return a node
    
    void printList(); 				// print the linked list
    
    int getLength(); 				// returns length of the list
    
	// De-constructor
    ~LinkedList();
};
