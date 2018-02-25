/********************************************************************
 **        NAME:         Srizan Gangol         USERID:sg0440      	**
 **        ASSIGNMENT:   CSCE2110		  				            **
 **        DESCRIPTION:  Main File                                  **
 **        Project:      HashTable Program {Program 2}              **
 **        Email:        SrizanGangol@my.unt.edu                    **
 **         														**
 ********************************************************************/

#include <string>
#include <cstdio>
#include <cstdlib>
#include "HashTable.h"

int main()
{		
	//Create new (empty) hash table
    HashTable table(500);
    
    FILE* file =  fopen("input.txt", "r");
    if (file)
    {
        char comma;
        while(!feof(file))
        {
            Node* node = new Node();
            char major[128];
                       
            if (fscanf(file, "%d", &node->id)>0)
            {
                fscanf(file, "%c", &comma);
                fscanf(file, "%lf", &node->GPA);
                fscanf(file, "%c", &comma);
                fscanf(file, "%s", major);
                node->major = major;
                node->next = NULL;

                table.insert(node);
            }
            else
                delete node;
        }

        fclose(file);
    }
	
	//NOTE: The given hash function is not a good hash function
	//		You are required to research and submit your own
	//		Don't forget to properly cite your resource(s)
	
	//Show Update
    table.printBucketValues();
    table.printHistogram();

    getchar();
    	
    return 0;
}