/********************************************************************
 
 *	Author:			Srizan Gangol
 *	Email:			SrizanGangol@my.unt.edu 
 *	Date:			12/02/2016
 *	Assignment:		CSCE 2110 Program 3
 
 *	DESCRIPTION:	           
		>	The heart of the Program
		> 	Load and imports graph from Graph.txt
		>	Load and executes the commands from the Commands.txt
 	*	Resources:	AdjacencyList.h
					->	LinkedList.h		
		
 
 ********************************************************************/
#include "AdjacencyList.h"
#include <fstream>


// Main variable used for holding the adjacency list
AdjacencyList graph;

// Reads the graph.txt and imports and builds the adjacencylist from the file
void loadGraph()
{
    std::string line;
    std::cout<< "\nOpening file: graph.txt"<<endl;
    std::ifstream file("graph.txt");
    while(std::getline(file,line))  			// EOL
    {
        std::string rem=line;
        while (rem[rem.length()-1]=='\r' || rem[rem.length()-1]=='\n')
            rem=rem.substr(0,rem.length()-1); 	// Removes trailing characters
        std::size_t pos;
        int nnode=0;
        std::string node0;  					// Initial Node
        do
        {
            std::string key;
            pos=rem.find(",");  
            if(pos!=std::string::npos)  		// If the string has a comma
            {
                key=rem.substr(0,pos);  		// Saves the key which is the value before the comma 
                rem=rem.substr(pos+1); 			// Saves the remaining part of the string
            }
            else
            {
                key=rem;                		// If there was not a comma we are at the last node, save it
            }
            if(nnode==0)
                node0=key;              		// if this is the first cycle, save the node as the initial
            else
                graph.addEdge(node0,key);   	// otherwise, create an edge from the initial to the current node
            nnode++;
        }while(pos!=std::string::npos && rem.length()>0); // repeat while there are commas on the string and the remainder is not empty
    }
}

// Reads Commands.txt file and executes the command sequentially
void runCommands()
{
    std::string line;
    std::cout<< "\nOpening file: commands.txt\n";
    std::cout<< "Ran the following commands:\n";
    std::ifstream file("commands.txt");
    int nnode=0;
    while(std::getline(file,line)) {    			// EOL
        while (line[line.length()-1]=='\r' || line[line.length()-1]=='\n')
            line=line.substr(0,line.length()-1); 	// Removes the trailing character

        if(line.substr(0,7)=="addnode")     		// Looks for the addnode command
        {
            std::string nnode=line.substr(8);   	// Gets the node name
            std::cout<<"\tAdd Node "<<nnode<<endl;
            Node *node=new Node;           
            node->key=nnode;
            node->next=NULL;
            node->adj=NULL;
            graph.insert(node);                 	// Inserts the new node on the adjacency list
        }
        else if(line.substr(0,7)=="addedge")    	// Looks for the add edge command
        {
            std::string rem=line.substr(8);
            std::size_t pos=rem.find(",");
            std::string node1=rem.substr(0,pos);    // Gets the first node name
            std::string node2=rem.substr(pos+1);    // Gets the second node name
            std::cout<<"\tAdd Edge "<<node1<<" "<<node2<<endl;
            graph.addEdge(node1,node2);     		// Inserts the new edge on the adjacency list
        }
        else if(line.substr(0,10)=="removenode")    // Looks for the remove node command
        {
            std::string nnode=line.substr(11);  	// Gets the node name
            std::cout<<"\tRemove Node "<<nnode<<endl;
            graph.remove(nnode);                	// Removes the node from the adjacency list
        }
        else if(line.substr(0,10)=="removeedge")    // Looks for the remove edge command
        {
            std::string rem=line.substr(11);
            std::size_t pos=rem.find(",");
            std::string node1=rem.substr(0,pos);    // Gets the first node's name
            std::string node2=rem.substr(pos+1);    // Gets the second node's name
            std::cout<<"\tRemove Edge "<<node1<<" "<<node2<<endl;
            graph.removeEdge(node1,node2);      	// Removes the edge from the adjacency list
        }            
    }
}

// Main Function
int main() 
{ 
    loadGraph();
    graph.print();
    graph.printAdjacencyMatrix();
    runCommands();
    graph.print();
    graph.printAdjacencyMatrix();
    return 0;
}
