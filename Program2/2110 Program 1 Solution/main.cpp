#include "HashTable.h"

int main()
{
	// Create new nodes
	//*****************START*****************
	Node *A = new Node;
	A -> key = 1;
	A -> next = NULL;
	
    Node * B = new Node; 
	B -> key = 2;
	B -> next = NULL;
	
    Node * C = new Node; 
	C -> key = 3; 
	C -> next = NULL;
	
    Node * D = new Node; 
	D -> key = 4; 
	D -> next = NULL;
	
    Node * E = new Node; 
	E -> key = 5; 
	E -> next = NULL;

    Node * F = new Node; 
	F -> key = 6; 
	F -> next = NULL;

    Node * G = new Node; 
	G -> key = 7; 
	G -> next = NULL;

    Node * H = new Node; 
	H -> key = 8;
	H -> next = NULL;

    Node * I = new Node; 
	I -> key = 9;
	I -> next = NULL;

    Node * J = new Node; 
	J -> key = 10; 
	J -> next = NULL;

    Node * K = new Node; 
	K -> key = 11; 
	K -> next = NULL;

    Node * L = new Node; 
	L -> key = 12; 
	L -> next = NULL;

    Node * M = new Node; 
	M -> key = 13; 
	M -> next = NULL;

    Node * N = new Node; 
	N -> key = 14; 
	N -> next = NULL;

    Node * O = new Node; 
	O -> key = 15; 
	O -> next = NULL;

    Node * P = new Node; 
	P -> key = 16; 
	P -> next = NULL;

    Node * Q = new Node; 
	Q -> key = 17; 
	Q -> next = NULL;

    Node * R = new Node; 
	R -> key = 18; 
	R -> next = NULL;

    Node * S = new Node; 
	S -> key = 19; 
	S -> next = NULL;

    Node * T = new Node; 
	T -> key = 20; 
	T -> next = NULL;

    Node * U = new Node; 
	U -> key = 21; 
	U -> next = NULL;

    Node * V = new Node; 
	V -> key = 22; 
	V -> next = NULL;

    Node * W = new Node; 
	W -> key = 23; 
	W -> next = NULL;

    Node * X = new Node; 
	X -> key = 24; 
	X -> next = NULL;

    Node * Y = new Node; 
	Y -> key = 25; 
	Y -> next = NULL;

    Node * Z = new Node; 
	Z -> key = 26;
	Z -> next = NULL;
	//*****************DONE*****************
	
	//Create new (empty) hash table
    HashTable table;
    
	//Insert some data
    table.insert(A);
    table.insert(B);
    table.insert(C);
	
	//NOTE: The given hash function is not a good hash function
	
	//Show Update
    table.printBucketValues();
    table.printHistogram();
    
	//Remove a Node
    table.remove(1);
	
	//Show Update
    table.printBucketValues();
    table.printHistogram();
    
	//Insert the rest of our data
    table.insert(D);
    table.insert(E);
    table.insert(F);
    table.insert(G);
    table.insert(H);
    table.insert(I);
    table.insert(J);
    table.insert(K);
    table.insert(L);
    table.insert(M);
    table.insert(N);
    table.insert(O);
    table.insert(P);
    table.insert(Q);
    table.insert(R);
    table.insert(S);
    table.insert(T);
    table.insert(U);
    table.insert(V);
    table.insert(W);
    table.insert(X);
    table.insert(Y);
    table.insert(Z);
	
	//Show update
    table.printBucketValues();
    table.printHistogram();
    
	//Perform a LookUp
    Node *result = table.lookUp(19);
    cout << result -> key << endl;
	
    return 0;
}