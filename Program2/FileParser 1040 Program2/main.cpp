/********************************************************************
 **        NAME:  Srizan Gangol         USERID:sg0440	           	**
 **  ASSIGNMENT:  CSCE1040 HW01                                    	**
 ** DESCRIPTION:  Main File	with Data Structure					   	**
 **         														**
 ********************************************************************/
#include <iostream>
#include <string>	// String
#include <sstream>	// Struct
#include <cstring> 
#include <fstream>	// File
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>   // setw
#include <cstddef>

// *** Including header files *** //

#include "dect_struct.h"	// structure
#include "func_proto.h"		// Prototypes of function


// Declaring all required variables
	int choice;
	int cx=0, sx=0, cy=0;	
	int gx=0;
	
	ifstream input;
	ofstream output;


using namespace std;

int main ()
{
	
	// *** For the SWITCH statement *** //
	bool gameOn = true;
	
	// *** Printing out the Menu *** //
	ProgramTitle01 ();	// Void Function
	Greetings_02 ();	// Void Function
	PrintMenu();		// Void Function
	
	
	
		
	// *** Switch Starts *** //
	do
	{
	std::cout << "\n Enter your choice and press return: ";
	// *** Reading the User's Input *** //
	std::cin >> choice;
	switch (choice)
	{
	
	
	case 1:
	{
		case01();
	}
	break;
	
	case 2:
	{
		// Function Call for Case 2
		case02();
	}
	break;
	
	case 3:
	{// Function Call for Case 3
	// eg:
	//		ENTER STUDENT NAME>Steven
	//		ENTER COURSE ID> EENG100-
	//		Added to EENG100- Steven
	// or:	*** ERROR *** Steven already enrolled in EENG100
	// z3 variable 
	
		case03();	
	}
	break;
	
	case 4:
	{// Function Call for Case 4
		case04();
		
	}
	break;
	case 5:
	{// Function Call for Case 5
	// *** Function Print all the course
	// *** CSCE 1040   Computer Science III   Computer Science & Engineering
	// *** printf having issue pritning string
	
		case05();
	}
	break;
	case 6:
	{// Function Call for Case 6
		// **** Print a list of all students
		// ** courseID needs to be reassigned
		case06();

	}
	break;
	
	case 7:
	{// Function Call for Case 7
	// *** Print a list of all students in a course
	// eg:  ENTER COURSE ID: CSCE1040
	//		ID001	Steven		CSCE
		
		case07();
	
	}
	break;
	case 8:
	{// Function Call for Case 8
	// *** Compute the average for a student in a course
	// eg: 	ENTER COURSE ID: CSCE1040
	// 		ENTER STUDENT ID: ID0001
	//		AVERAGE: 100 90 80 70 = 85.0 
	
		case08();
	
	}
	break;
	case 9:
	{
		case09(input);
	}
	break;
	
	case 10:
	{
		case10(output);
	}
	break;
	
	case 11:
	{
		// *** Exit the Program *** //
		cout << "\n Good-bye -- Thank you for flying with CSCE1040 \n \n End of Program.\n \n \n \n \n \n \n \n";
		gameOn = false;
	}
	break;
	
	default:
	{
	cout << " Not a Valid Choice. \n";
	cout << " Please choose again: ";
	cin >> choice;
	}
	break;
	} // Switch End Bracket
	}while(choice<11);


return 0;
}


//Function Copy to Function.cpp

// Definition of function
 
 
/*
void ProgramTitle01 ()
{
	cout << "\n \n";
    cout << "+---------------------------------------------------------+" << endl;
    cout << "|              Computer Science and Engineering           |" << endl;
    cout << "|              CSCE 1040 - Computer Science II            |" << endl;
    cout << "|   Srizan Gangol     ID: sg0440      srizan@gmail.com    |" << endl;
    cout << "+---------------------------------------------------------+" << endl;
}
 
 

 void Greetings_02 ()
{
    cout << "\n Welcome to the GradeBook Program. \n" ;
	cout << " Please select a menu option below \n \n" ;
	
}

void PrintMenu ()
{
	cout << "\n ******************************* \n";
	cout << " 1 - Add a new course \n";
	cout << " 2 - Add a new student \n";
	cout << " 3 - Add a student to a course \n";
	cout << " 4 - Add grades for a student in a course \n";
	cout << " 5 - Print a list of all courses \n";
	cout << " 6 - Print a list of all students \n";
	cout << " 7 - Print a list of all students in a course \n";
	cout << " 8 - Compute the average for a student in a course \n";
	cout << " 9 - Load Grade Book \n";
    cout << " 10- Store Grade Book \n";
    cout << " 11- Exit \n ";
	
	
	
}
*/

 void case01()
 {
		//int count;
	 	do
		{
		cout << " PLEASE ENTER COURSE ID: ";
		cin.ignore();
		getline(cin,courses[cx].id);
		if ((courses[cx].id).size()>9)
		{
			cout << "\n ERROR!!! Course ID cannot be more than 9 characters \n" ;
			cout << " Please Try Again! \n \n";
		}
		}while ((courses[cx].id).size()>9);
		
		do
		{
		cout << " PLEASE ENTER COURSE NAME: ";
		getline(cin,courses[cx].name);
		if ((courses[cx].name).size()>31)
		{
			cout << "\n ERROR!!! Course Name cannot be more than 31 characters \n" ;
			cout << " Please Try Again! \n \n";
		}
		}while ((courses[cx].name).size()>31);
		
		do
		{
		cout << " PLEASE ENTER DEPARTMENT NAME: ";
		getline(cin,courses[cx].dept);
		if ((courses[cx].dept).size()>31)
		{
			cout << "\n ERROR!!! Department Name cannot be more than 31 characters \n" ;
			cout << " Please Try Again! \n \n";
		}
		}while ((courses[cx].dept).size()>31);
		
		cout << " " << courses[cx].id << " has been ADDED in ";
		cout << courses[cx].name << endl ;
		cx++;
		
		
		
 };
 void case02()
 {
	string tempName2;
	do
	{
	cout << " PLEASE ENTER STUDENT NAME: ";
	cin >> tempName2;
	if ((tempName2).size()>11)
	{
			cout << "\n ERROR!!! Student Name cannot be more than 11 characters \n" ;
			cout << " Please Try Again! \n \n";
	}
	}while ((tempName2).size()>11);
	
	for (int x=0; x<24;x++)
	{
		if ((tempName2)==(students[x].name))
		{
			std::cout << "*** ERROR***: " << tempName2;
			std::cout << " already has" << (students[x].id) << endl;
		break;
		}
		
	}
	(students[sx].name)=tempName2;	
	
	// Student Major
	
	cout << " PLEASE ENTER STUDENT MAJOR: ";
	cin >> students[sx].major;
	//getline(cin,students[sx].major);
	
	students[sx].id = sx+1;
	
	sx++;
 }
 ;
 void case03()
 {
	 string tempName3, tempCourse3;
	
	int nameValidator;		// Validator for Name
	int courseValidator;	// Validator for Course
		
		cout << " PLEASE ENTER STUDENT NAME: ";
		cin >> tempName3;
		for (int x=0; x<24; x++)
		{
			if ((tempName3)==(students[x].name))
			{
				nameValidator=1;
				students[x].name = tempName3;
				
				cout << " PLEASE ENTER COURSE ID: ";
				cin.ignore();
				getline(cin,tempCourse3);
				
				for (int y=0; y<9; y++)
				{
					if (tempCourse3.compare(courses[y].name))
					{
					cout << " ADDED to " << courses[y].name;
					cout << " - " << students[x].name << endl;	
					
					// Actually Adding in our struct
					
					(students[x].c_id[gx]).assign(tempCourse3);
					/*
					cout << "X: " << x << endl;
					cout << (students[x].c_id[gx]) << endl;
					cout << " Length: " << (students[x].c_id[gx]).length() << endl;
					cout << " Size: "<< (students[x].c_id[gx]).size() << endl;
					*/
					courseValidator = 1;

					gx++;
					break;
					}
				}
				
				
				
			}
		}
		if (nameValidator != 1)
		{
			cout << "\n Student not in system. Try again \n ";
		}
		else
		{
			if (courseValidator != 1)
			{
				cout << "\n Course not in system. Try again \n ";
			}
		}
			
 }
 ;
 void case04()
 {
	 string tempName4, tempCourse4;
	int x4, y4, z4=0;
	int exit=0;
		
		cout << " PLEASE ENTER STUDENT NAME: " ;
		cin >> tempName4;
		
		for (int x=0; x<24; x++)
		{
			if ((tempName4)==(students[x].name))
			{
				x4=x;
				
				
				cout << " PLEASE ENTER COURSE ID: ";
				cin.ignore();
				getline(cin,tempCourse4);
				
				cout << "\n Please Enter Your Grade and Press <ENTER> \n \n Type -1 and Hit <ENTER> when you are done \n \n You can input up to 5 grades \n \n";
				for (int y=0; y<5; y++)
				{
					if ((tempCourse4)==(students[x4].c_id[y]))
					{
					// *** User Enters GRADE here
					y4=y;
					do
					{
					cout << " PLEASE ENTER GRADE: " ;
					cin >> students[x4].grade[y4][z4];
					exit = (students[x4].grade[y4][z4]);
					
					z4++;
					
					if (exit == -1 )
					{
						(students[x4].grade[y4][z4])=0;
					}
					else
					{
						students[x4].gradeCounter++;
					}
					//cout << "EXIT: " << exit << endl;
					//cout << " Z4: " << z4 << endl;
				
					}while(z4< 5 && (exit>0));
					}
				}
				
			}
		}
		
		
 };
 void case05()
 {
	cout << "\nCOURSES \n";
	cout <<   "------- \n";	
	for (int x=0; x<cx;x++)
	{
		std::cout.width(13); std::cout << std::left << courses[x].id;
		std::cout.width(34); std::cout << std::left << courses[x].name << courses[x].dept << "\n";
		
	}
	
 };
 void case06()
 {
	 int count;
	
	cout << "\nSTUDENTS \n";
	cout << "-------- \n";	
	
	for (int x=0; x<sx;x++)
	{
		
			
		
		if(x<9)
		{
			cout << "ID00" << (x+1) << "\t";
		}
		else
		{
			cout << "ID0" << (x+1) << "\t";
		}
		std::cout.width(13); std::cout << std::left << students[x].name;
		std::cout.width(26); std::cout << std::left << students[x].major << courses[x].dept << "\n";
		
	
		
	}
 }
 ;
 void case07()
 {
	 string input_7;
	cout << " ENTER COURSE ID>";
	cin.ignore();
	getline(cin,input_7);
	
	for ( int x=0; x<sx; x++)
	{
		for (int y=0; y<5; y++)
		{
			if ((input_7)==(students[x].c_id[y]))
			{
				if(x<9)
				{cout << " ID00" << (x+1);}
				else
				{cout << " ID0" << (x+1);}
				
				cout << "\t" << students[x].name << endl;
				
				//cout << " TEST: " << x << "\t" << y << endl;
				//cout << " Input: " << input_7 << endl;
				//cout << " Course: " << students[x].c_id[y]<< endl;
				//cout << " SX: " << sx << endl;
			}
		}
	}
	
 } ;
 void case08()
 {
	string inputCourse;
	int inputID;
	int identifier;
	
	double gradeSum=0;
	int counter=0;
	
	double average;
	
	cout << " ENTER COURSE ID: " ;
	cin.ignore();
	getline(cin,inputCourse);
	
	cout << " ENTER STUDENT ID: ID00";
	cin >> inputID;
	
	identifier = (inputID - 1);
	
	cout << " AVERAGE: ";
	for ( int x=0; x<5; x++)
	{
		if (inputCourse.compare(students[identifier].c_id[x]) == 0)
			for (int y=0; y<5;y++)
			{
			if ((students[identifier].grade[x][y])>0)
			{cout << " " << students[identifier].grade[x][y] << " ";
			gradeSum = gradeSum + students[identifier].grade[x][y];
			counter++;
			}
			}
	}
	
	average = gradeSum/students[identifier].gradeCounter;
	cout << " = " << average << "\n";
	
	
 }


void case09 (ifstream& input) 
 {
    char answer[99999];
    int x=0;
    char input_file [20];
    cout <<" PLEASE ENTER FILENAME ";
    cin >> input_file;
	//cin.getline(input_file, 20);
	// Opens Files
    input.open(input_file);
    
	if (input.fail ( ))                           // if the file doensn't exit
    {
        cout <<" ***ERROR**:File doesn't exit " << input_file << endl;
        exit (EXIT_FAILURE); 		//C standard Library
    }
   	
    
	while(!input.eof())		
	{
		input >> answer;		// Answer reads in all the Files
        
		
		//int countx;				// For LOOP #1 - Stores Student Number
		
		int countc_id;			// For Loop #2 - Stores Course Number
		int countc_id_x;		// Basically same functionality of countx
		int grade_count;
		
		//int y=0, z=0, placer=0;
		
		
		
		int student_no; // Stores Students Number
		
		
		for (int w=0; w<9999; w++)
		{
			
			// **************** STUDENT ARRAY ***************** //
			
			
			if ((answer[w]=='|')&&(answer[w+1]!='!'))
			{
			// IF #1: Will cover up to end of his Array
				char 	name_array[11];
				int 	n_counter=0;
				
				do
				{
					// * Assigns character by character
					name_array[n_counter] = answer[w+1];
					
					// ADDS UP COUNTERS
					n_counter++;
					w++;
									
				}while(answer[w+1]!='@'); // ENDS when @ is FOUND
				students[student_no].name = name_array;
				
				// **** CLEARING UP THE TEMP CHAR ARRAY 
				for (int i = 0; i < sizeof(name_array); i++){name_array[i] = '\0';}
						
				// ** TEST
				//cout << " Student ID00" << (student_no+1);
				//cout << " =    " << students[student_no].name << " 	";
			
				// *********** Course ID *********** //
				int course_no=0;	// DECLARING & RESETTING COURSE NO
				
				if (answer[w+1]=='@')
				{
				// IF #2: COURSE ID	
					char	course_array[9];
					int 	c_counter=0;
					
					w++;	// Makes w=@
					w++;	// Gets to Value of w
					do
					{
						// * Assigns character by character
						course_array[c_counter] = answer[w];
						
						// ADDS UP COUNTERS
						c_counter++;
						w++;	
					}while(answer[w]!='#');
					students[student_no].c_id[course_no] = course_array;	
					
					// **** CLEARING UP THE TEMP Course ARRAY 
					for (int i = 0; i < sizeof(course_array); i++){course_array[i] = '\0';}
					
					// ** TEST
					//cout << students[student_no].c_id[course_no] << "	";
					
					// ******** GRADE ******** //
					if (answer[w] == '#')
					{
					// IF #3: GRADE	
					// Condition w = #
				
						
						char	grade_array[2];
						int		g_counter=0;
						int		grade_atoi;
						int		grade_no=0;		// Counts Grade Number
						w++; // Makes w = Grade
						
						
						do
						{
							grade_array[g_counter]=answer[w];
						
							// ADDS UP COUNTERS
							g_counter++;
							w++;	
						}while (answer[w]!='$');
						
						// Converting Grades from Char Array to INT
						grade_atoi = atoi(grade_array);
						students[student_no].gradeCounter = 1;
						// ** TEST
						//cout << grade_array[0] << grade_array[1] << grade_array[2] <<"	";
						
						students[student_no].grade[course_no][grade_no]=grade_atoi;
						
						// **** CLEARING UP THE TEMP Course ARRAY 
						for (int i = 0; i < sizeof(grade_array); i++){grade_array[i] = '\0';}
						grade_no++;
						
						while(answer[w+1]!='|')
						{
						if (answer[w]=='$')
						{
							g_counter=0;
							do
							{
								
								grade_array[g_counter]=answer[w+1];
								
								// ADDS UP COUNTERS
								g_counter++;
								w++;	
								
							}while (answer[w]!='$');
							
							// Converting Grades from Char Array to INT
							if(grade_array[g_counter-1]=='$')
							{grade_array[g_counter-1]='\0';}
							grade_atoi = atoi(grade_array);
							
							// ** TEST
							//cout << grade_array[0] << grade_array[1] << grade_array[2] <<"	";
							// FOR AVERAGE
							if (grade_atoi>(-1))
							{students[student_no].gradeCounter++;}
							
							students[student_no].grade[course_no][grade_no]=grade_atoi;
						
						// **** CLEARING UP THE TEMP Course ARRAY 
						for (int i = 0; i < sizeof(grade_array); i++){grade_array[i] = '\0';}
						grade_no++;
						}	
							
						// ** TEST
						
						//cout << "CS: " << course_no  << " GN: " << grade_no << " |		";
						//cout << students[student_no].grade[course_no][grade_no] << "	" ;
						
						
						}//END of while
					}// END OF IF #3 GRADE 	
					
				// BEFORE END OF IF#2
				course_no++;
				
				}// END OF IF#2: COURSE ID	
			
			// BEFORE END OF IF#1
			
			student_no++;	// Opens up for next student
			sx=student_no;
			}// END OF IF #1: Student Name
		}	// END OF FOR LOOP MAIN #1	
		
			// ************************************************ //
			// ***** STUDENT WORKS- TESTED DONT MESS UP ******* //
			// ************************************************ //
		
		// MAIN COUNTER WILL FEED 'CX' TO MAIN PROGRAM	
		int courses_array_counter=0;	
		
		// ***************** COURSE ARRAY ***************** //
		for (int w=0; w<9999; w++)
		{	
			// COURSE ARRAY	
			
			if ((answer[w]=='!'))	
			{
				
				int cntr_cid=0;		// RESETTING array length for the char temp_name[11]
				char course_x[9];	// Declaring arrat char temp_name[11] where name will be stored temp
				
	
			// Stores Course ID to Course Array
			do
			{			
				course_x[cntr_cid] = answer[w+1];
				w++;
				cntr_cid++;
				
			}while (answer[w+1]!= '^') ;
			
			courses[courses_array_counter].id = course_x;
						
			// **** CLEARING UP THE TEMP Course ARRAY 
			for (int i = 0; i < sizeof(course_x); i++) {course_x[i] = '\0';}
				
			// Stores Course Name
			if ((answer[w+1]=='^'))
			{
				char course_name[31];
				int count1=0;
				w++;
			// Stores Course Name to Course Array
			do
			{
				course_name[count1]= answer[w+1];
				w++;
				count1++;
			}while (answer[w+1]!='*');
				
			courses[courses_array_counter].name = course_name;
			
			// **** CLEARING UP THE TEMP Course ARRAY 
			for (int i = 0; i < sizeof(course_name); i++) {course_name[i] = '\0';}
				
			
			}//END of IF -COURSE NAME
			
			// Stores Dept Name
			if ((answer[w+1]=='*'))
			{
				char dept_name[31];
				int count_dept=0;
				w++;// 	MAKES IT TO *
			
			// Stores Course Name to Course Array
			
			do
			{
				w++; // Takes it pass *
				dept_name[count_dept]= answer[w];
				
				count_dept++;
			}while ((answer[w+1]!='!'));
			
			//if(dept_name[count2-1]=='!')
			//{dept_name[count2-1]='\0';}		
			
			//** TEST
			//cout << dept_name << " 	";
			courses[courses_array_counter].dept = dept_name;
			
			// **** CLEARING UP THE TEMP Course ARRAY 
			for (int i = 0; i < sizeof(dept_name); i++) {dept_name[i] = '\0';}
			
			}//END of Dept Name
			
			
			// ADDS UP COURSES ARRAY
			courses_array_counter++;
			cx = courses_array_counter;
			}// END OF IF LOOP OF ARRAY	
			
		}// Main For Loop #2
				
	}// END OF WHILE LOOP [EOF]
	
	
	cout << "\n Successfully Imported!!! \n\n";
	
	
	//	CLOSING THE INPUT FILE
    input.close();
}// END OF VOID FUNCTION
 
 
 
 
 
 
 void case10 ( ofstream& output)  // function to store in the grade book
{
    char output_file [20];
    cout <<" PLEASE ENTER FILENAME ";
    cin >> output_file;
    output.open(output_file);
   
	if (output.fail ( ))                        // if the file fails to open
    {
        cout <<" ***ERROR**:File doesn't exit " << output_file << endl;
        exit (EXIT_FAILURE);
    }
	// BEGINS UP THE FILE
	output << "|";
    for (int x = 0; x < 24; x++) 
	{
		if (((students[x].name).size())>0)
		{
		output << students[x].name << "@";
      
		for (int y = 0; y < 4; y++)
		{
			if (((students[x].c_id[y]).size()>0)>0)
			{
			output << students[x].c_id[y] << "#";
			
			for (int z = 0; z < 5; z++) 
			{
				if (students[x].grade[y][z]!=0)
				{
					output << students[x].grade[y][z] << "$";
				}
			}
			};
			
		}
		// MARKING FOR THE END OF STUDENT ARRAY
		output << "|";
		}
	}
	
	// MARKING FOR THE BEGINNING OF COURSE ARRAY
	output << "!";
	
	for (int x=0; x<9 ; x++)
	{
		output << courses[x].id << "^" << courses[x].name << "*" << courses[x].dept << "!";
	}
    output << "(";
	
    

    output.close();
}
