/*
 * Name: Saina Baidar	EUID:SB0576  
 * File: graph.cpp              
 *           Contains the main function for the Adjacent list program.
 * 
 */
#include "Adjacent.h"
#include <fstream>

// Adjacent List Var
AdjacentList graph;

// Parse Graph.txt
void parseGraph();
// Parse Command.txt
void parseCommand();

int main() 
{ 
    parseGraph();
    graph.print();
    graph.printAdjacentMatrix();
    parseCommand();
    graph.print();
    graph.printAdjacentMatrix();
    return 0;
}



void parseGraph()
{
    std::string line;
    std::cout<< "\nOpening file: graph.txt"<<endl;
    std::ifstream file("graph.txt");
    while(std::getline(file,line))  				// Line by Line
    {
        std::string rem=line;
        while (rem[rem.length()-1]=='\r' || rem[rem.length()-1]=='\n')
            rem=rem.substr(0,rem.length()-1); 		// Removing unwanted char
        std::size_t pos;
        int nnode=0;
        std::string node0;  						// Initial Value
        do
        {
            std::string key;
            pos=rem.find(",");  
            if(pos!=std::string::npos)  			// Comma
            {
                key=rem.substr(0,pos);  			// Value before , 
                rem=rem.substr(pos+1);  			// Remaining value of the String
            }
            else
            {
                key=rem;                			// no comma = last node -> SAVE
            }
            if(nnode==0)
                node0=key;             				// if first cycle, save as the initial node
            else
                graph.addEdge(node0,key);   		// else, create an edge
            nnode++;
        }while(pos!=std::string::npos && rem.length()>0); // Until End
    }
}

void parseCommand()
{
    std::string line;
    std::cout<< "\nOpening file: commands.txt\n";
    std::cout<< "Ran the following commands:\n";
    std::ifstream file("commands.txt");
    int nnode=0;
    while(std::getline(file,line)) {    			// Line By Line
        while (line[line.length()-1]=='\r' || line[line.length()-1]=='\n')
            line=line.substr(0,line.length()-1); 	// Remove Rem

        if(line.substr(0,7)=="addnode")     		// Detect "addnode"
        {
            std::string nnode=line.substr(8);   	// Get the Node
            std::cout<<"\tAdd Node "<<nnode<<endl;
            Node *node=new Node;           
            node->key=nnode;
            node->next=NULL;
            graph.insert(node);                 	// Insert the Node
        }
        else if(line.substr(0,7)=="addedge")    	// Detect "addedge"
        {
            std::string rem=line.substr(8);
            std::size_t pos=rem.find(",");
            std::string node1=rem.substr(0,pos);    // Get 1st node
            std::string node2=rem.substr(pos+1);    // Get 2nd node
            std::cout<<"\tAdd Edge "<<node1<<" "<<node2<<endl;
            graph.addEdge(node1,node2);     		// Insert the Edge
        }
        else if(line.substr(0,10)=="removenode")    // Detect  "removenode"
        {
            std::string nnode=line.substr(11);  	// get the node
            std::cout<<"\tRemove Node "<<nnode<<endl;
            graph.remove(nnode);                	// remove the node
        }
        else if(line.substr(0,10)=="removeedge")    // Detect "removeedge"
        {
            std::string rem=line.substr(11);
            std::size_t pos=rem.find(",");
            std::string node1=rem.substr(0,pos);    // 1st node
            std::string node2=rem.substr(pos+1);    // 2nd node 
            std::cout<<"\tRemove Edge "<<node1<<" "<<node2<<endl;
            graph.removeEdge(node1,node2);      // remove the edge
        }            
    }
}