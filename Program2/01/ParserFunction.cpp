
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
 
 
 
