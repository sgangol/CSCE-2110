/********************************************************************
 **        NAME:  Srizan Gangol         USERID:sg0440	           	**
 **  ASSIGNMENT:  CSCE1040 HW02                                    	**
 ** DESCRIPTION:  Declaration of Structures						   	**
 **         														**
 ********************************************************************/
#include <iostream>
#include <string>
using namespace std;

 // Structure for Course
struct c_struct{
	string id;
	string name;
	string dept;
}courses[9];

// Structure for Grades
struct g_struct{
	int grade[5][4];
	string c_id[5];
//	string s_id;
}grades[24];

// Structure for Students
struct s_struct{
	string name;
	string major;
	int grade[5][4];
	int gradeCounter;
	string c_id[5];
	
	// Trying to get rid of id
	string id;
}students[24];

