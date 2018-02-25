#include <string>
#include "HashTable.h"

int main()
{
	// Create new nodes
	//*****************START*****************
	Node *A = new Node;
	A -> id = 12;
    A -> GPA = 3.4;
    A -> major = "CS";
	A -> next = NULL;
	
    Node * B = new Node; 
	B -> id = 18;
    B -> GPA = 3.9;
    B -> major = "CS";
	B -> next = NULL;
	
    Node * C = new Node; 
	C-> id = 29;
    C -> GPA = 3.2;
    C -> major = "CS";
	C -> next = NULL;
	//*****************DONE*****************
	
	//Create new (empty) hash table
    HashTable table(20);
    
	//Insert some data
    table.insert(A);
    table.insert(B);
    table.insert(C);

	
	//NOTE: The given hash function is not a good hash function
	//		You are required to research and submit your own
	//		Don't forget to properly cite your resource(s)
	
	//Show Update
    table.printBucketValues();
    table.printHistogram();
    
	//Remove a Node
    //DONE: Given a value, remove it from the hash table (if it exists)
    table.remove(18);
	
	//Show Update
    table.printBucketValues();
    table.printHistogram();
	
    Node *A1 = new Node;
	A1 -> id = 33;
    A1 -> GPA = 3.7;
    A1 -> major = "CS";
	A1 -> next = NULL;
	table.insert(A1);

    Node *A2 = new Node;
	A2 -> id = 65;
    A2 -> GPA = 3.9;
    A2 -> major = "CS";
	A2 -> next = NULL;
	table.insert(A2);

    Node *A3 = new Node;
	A3 -> id = 96;
    A3 -> GPA = 3.7;
    A3 -> major = "CS";
	A3 -> next = NULL;
	table.insert(A3);

    Node *A4 = new Node;
	A4 -> id = 58;
    A4 -> GPA = 3.9;
    A4 -> major = "CS";
	A4 -> next = NULL;
	table.insert(A4);

    Node *A5 = new Node;
	A5 -> id = 62;
    A5 -> GPA = 2.7;
    A5 -> major = "CS";
	A5 -> next = NULL;
	table.insert(A5);

    Node *A6 = new Node;
	A6 -> id = 77;
    A6 -> GPA = 2.95;
    A6 -> major = "CS";
	A6 -> next = NULL;
	table.insert(A6);

    Node *A7 = new Node;
	A7 -> id = 83;
    A7 -> GPA = 3.3;
    A7 -> major = "CS";
	A7 -> next = NULL;
	table.insert(A7);

    Node *A8 = new Node;
	A8 -> id = 42;
    A8 -> GPA = 3.25;
    A8 -> major = "CS";
	A8 -> next = NULL;
	table.insert(A8);

    Node *A9 = new Node;
	A9 -> id = 9;
    A9 -> GPA = 2.88;
    A9 -> major = "CS";
	A9 -> next = NULL;
	table.insert(A9);

    Node *B1 = new Node;
	B1 -> id = 34;
    B1 -> GPA = 3.8;
    B1 -> major = "AM";
	B1 -> next = NULL;
	table.insert(B1);

    Node *B2 = new Node;
	B2 -> id = 75;
    B2 -> GPA = 3.2;
    B2 -> major = "AM";
	B2 -> next = NULL;
	table.insert(B2);

    Node *B3 = new Node;
	B3 -> id = 97;
    B3 -> GPA = 2.7;
    B3 -> major = "AM";
	B3 -> next = NULL;
	table.insert(B3);

    Node *B4 = new Node;
	B4 -> id = 59;
    B4 -> GPA = 3.65;
    B4 -> major = "AM";
	B4 -> next = NULL;
	table.insert(B4);

    Node *B5 = new Node;
	B5 -> id = 64;
    B5 -> GPA = 2.7;
    B5 -> major = "AM";
	B5 -> next = NULL;
	table.insert(B5);

    Node *B6 = new Node;
	B6 -> id = 78;
    B6 -> GPA = 3.2;
    B6 -> major = "AM";
	B6 -> next = NULL;
	table.insert(B6);

    Node *B7 = new Node;
	B7 -> id = 84;
    B7 -> GPA = 3.3;
    B7 -> major = "AM";
	B7 -> next = NULL;
	table.insert(B7);

    Node *B8 = new Node;
	B8 -> id = 43;
    B8 -> GPA = 3.75;
    B8 -> major = "AM";
	B8 -> next = NULL;
	table.insert(B8);

    Node *B9 = new Node;
	B9 -> id = 8;
    B9 -> GPA = 3.58;
    B9 -> major = "AM";
	B9 -> next = NULL;
	table.insert(B9);


    Node *C1 = new Node;
	C1 -> id = 39;
    C1 -> GPA = 3.6;
    C1 -> major = "CS";
	C1 -> next = NULL;
	table.insert(C1);

    Node *C2 = new Node;
	C2 -> id = 79;
    C2 -> GPA = 3.21;
    C2 -> major = "CS";
	C2 -> next = NULL;
	table.insert(C2);

    Node *C3 = new Node;
	C3 -> id = 98;
    C3 -> GPA = 2.95;
    C3 -> major = "AM";
	C3 -> next = NULL;
	table.insert(C3);

    Node *C4 = new Node;
	C4 -> id = 60;
    C4 -> GPA = 3.25;
    C4 -> major = "CS";
	C4 -> next = NULL;
	table.insert(C4);



    Node *D1 = new Node;
	D1 -> id = 11;
    D1 -> GPA = 3.11;
    D1 -> major = "CS";
	D1 -> next = NULL;
	table.insert(D1);
	
	//Show update
    table.printBucketValues();
    table.printHistogram();
	
	//Perform a LookUp and Print the node to the screen
    Node* node = table.lookUp(29);
    if (node) 
    {
        cout << "ID: " << node->id << endl;
        cout << "GPA: " << node->GPA << endl;
        cout << "Major: " << node->major << endl;
    }
    else
    {
         cout << "NOT FOUND!" << endl;
    }
	
    return 0;
}