/***************************************************************************************************************/
//Name: Benjamin Cayton
//Course: CIT163 ONLINE
//Date: 12.10.2019
/***************************************************************************************************************/
//File: final.cpp
//Purpose: Program acts as a grade storage repository for student records. Prompts user for input and offers 
//         myriad options for results.
//Assistance: N/A
/***************************************************************************************************************/

#include <iostream>
#include <cmath>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <string>
#include <cstring>
#include <limits>

using namespace std;



/*******************************************DECLARE STRUCTS***************************************/
struct student //student struct
{
    char studentName[30]; //Student name declaration
};

struct courses //Course struct
{
    char courseName[3];
    string courseTitle;
    char courseNum[2];//VERY STRANGE... IF I LISTED courseNum UNDER courseName, then these were concat during printing
    int courseHours;
    char courseGrade[1];
    
};

/*******************************************GLOBAL VARIABLES**************************************/
int nameLength = 30;
const int courseArrayLength = 20;



/************************************************* FUNCTION PROTOTYPES ******************************************/
void menu(int& userChoice); //Prints menu to user and gets user choice
void enterName(student& entry); //Prompts user to enter name. Accepts user input
void addCourse(courses course[]); //Add course prompts user to enter course information
void searchCourse(courses course[]); //Search by course Alpha-Designator member
void searchGrade(courses course[]); //Search by course grade member
void searchAll(courses course[]); //Print all course history for user
void showGPA(courses course[]); //Calculate GPA - Quality Points(QP) / Qualit Hours(QH)
void saveTo(student entry, courses[]); //Save entered information into file
void loadFrom(student& entry, courses[]); //Load from file

/****************************************************************************************************************/
/************************************************* MAIN FUNCTION ************************************************/
/****************************************************************************************************************/
int main ()
{
    //Declare structs in main
    student student1;
    //Array of course structs
    courses courseList[courseArrayLength];//Initialize all course structs to 0
    //Declaration of variables
    int choiceNum;


    cout << "Welcome to the SUPER senior database." << endl << "Not everyone is cut out to get two undergrad" 
            " science degrees, so I've made this application " << endl << "for us to keep track of our collective "
            "punishment." << endl << endl;



//BEGIN MENU WHILE LOOP	
    while (choiceNum != 9) //While loop keeps user in menu selection after each switch case scenario is called
    {
        (menu(choiceNum)); //Call menu for user choice of operation

            switch(choiceNum)//Switch statement calls appropriate function based on 'choiceNum' value.
        {
            case 1:
            {
                enterName(student1);
            }
            break; //Keeps from procedurally accessing functions 
            case 2:
            {
                addCourse(courseList);
            }
            break;//Keeps from procedurally accessing functions 
            case 3:
            {
                searchCourse(courseList);
            }
            break;
            case 4:
            {
                searchGrade(courseList);
            }
            break;
            case 5:
            {
                searchAll(courseList);
            }
            break;
            case 6:
            {
                showGPA(courseList);
            }
            break;
            case 7:
            {
                saveTo(student1, courseList);
            }
            break;
            case 8:
            {
                loadFrom(student1, courseList);
            }
            break;
        };
    }

    return 0;
}

/********************************************* BEGIN USER DEFINED FUNCTIONS ***************************************/

/************************************************* PRINT MENU FUNCTION ********************************************/
void menu(int& userChoice)
{
    

    //User prompt and menu layout
        cout << endl;//Menu reuse formatting
        cout << "Enter number for desired operation below." << endl << endl;
        cout << "[1]: Enter student name." << endl;
		cout << "[2]: Add course to Database." << endl;
		cout << "[3]: Search Course(s) by Alpha-Designator. Ex: GLY, CIT, BIO" << endl;
		cout << "[4]: Search Course(s) by Grade Earned." << endl;
        cout << "[5]: Show all Courses." << endl;
        cout << "[6]: Display GPA." << endl;
        cout << "[7]: Save info to file." << endl;
        cout << "[8]: Load info from file." << endl;
        cout << "[9]: Exit." << endl;


    //User input and input validation do..(if)..while loop.
        do
        {
            //Read user input
            cin >> userChoice;
            cin.ignore(); //Clear input buffer
                //IF statement qualifies user input
                if (userChoice < 1 || userChoice > 9)
                {
                    cout << "Following instruction is integral to your academic success." << endl << "Try again." << endl;
                }
        //While loops reads user input and selects appropriate option in main
        } while (userChoice < 1 || userChoice > 9);
        
        
}

/*************************************************** ENTER NAME ***************************************************/
//Prompts user to enter full name. Is SUPPOSED to read in entire line of characters. Don't know why this partially
//works.
void enterName(student& entry)
{
    cout << "Enter student full name." << endl; //User prompt
    cin.getline(entry.studentName, nameLength); //Read up to 30 characters of user imput(Include white space)
    cout << endl;
}

/*************************************************** ADD COURSE(S) ***************************************************/
//Prompts user to enter couse information in a particular order for storage. Once one course is completely populated
//function prompts user to continue or exit.
void addCourse(courses course[])
{
    int num = 1; //Used for continue prompt
    //for loop to populate course array struct
    for (int i = 0; i < courseArrayLength; i++)//Classic array populating for loop
    {
        if (course[i].courseHours == 0) //If char array is empty, prompt to enter course info 
        {
            cout << "Enter course alpha designator (Ex: CIT): ";//Enter course designator
            cin >> course[i].courseName;//User input 
            cin.ignore();//Clear istream buffer

            cout << endl << "Enter course number: ";//Enter course number
            cin >> course[i].courseNum;//User Input


            cout << endl << "Enter course title: ";
            cin.ignore();//Clear istream buffer  
            getline(cin,course[i].courseTitle);//Read full line

            cout << endl << "Enter course hours: ";
            cin >> course[i].courseHours;

            cout << endl << "Enter course grade: ";
            cin >> course[i].courseGrade;

            break;
        }
        
    }

}

/****************************************** SEARCH COURSE BY ALPHA-DESIGNATOR *************************************/
//Prompts user to enter course alpha designator for comparison purposes. 
void searchCourse(courses course[])
{
    string desig;//User inputs course alpha designator to compare within loop
    //Assigned array value of 4 since strcmp requires 'desig' to have a size for comparison to course[i]
    bool found = false;

    cout << endl << "Enter course Alpha-Designator (Ex: CIT, DFIA, etc.): " << endl;//User prompt
    cin >> desig;
    cout << endl;//Terminal formatting
    cout << left << setw(10) << "Course" << left << setw(25) << "Title" << setw(7) << "Hours" << "Grade" << endl << endl;
    //Format info header
    //begin for loop
    for (int i = 0; i < courseArrayLength; i++)//For loop to process array
    {
        while (i < courseArrayLength)//While array processes...
        {
            if(strcmp(course[i].courseName, desig.c_str()) == 0) //If the value in course.courseName is equal to user 'desig'
                {
                    found = true;//Boolean 'found' is set to true
                    cout << left << setw(4) << course[i].courseName << left << setw(6) << course[i].courseNum;//Print info formatting
                    cout << left << setw(25) << course[i].courseTitle << left << setw(7); 
                    cout << course[i].courseHours << course[i].courseGrade << endl;
                    break;//Required since nested in while loop
                }   

            else if(i < courseArrayLength)//Continue array process.
                {
                    i++;                   
                }
        }
        if(found == false)//If no courses found by user defined designator...
        {
            cout << "No courses by that designator." << endl;//Message to display if input 'desig' finds no matches.
            break;
        }  
    }
    
}
/******************************************************* SEARCH BY GRADE *********************************************/
//Prints course to user based on grade earned specified by user prompt
void searchGrade(courses course[])
{
    string grade;//Variable stores user defined grade input
    bool found = false;//Use boolean operator for logic 

    cout << endl << "Enter grade of course you wish to search (Ex: A through F):" << endl
                 << "Please use capital letter grades." << endl;
    cin >> grade;//Read in user input
    cout << endl;//Terminal formatting
    cout << left << setw(10) << "Course" << left << setw(25) << "Title" << setw(7) << "Hours" << "Grade" << endl << endl;
    //Info header formatting
    for(int i = 0; i < courseArrayLength; i++)
    {
        while(i < courseArrayLength)
        {
            if(strcmp(course[i].courseGrade, grade.c_str()) == 0)
            {
                found = true;
                cout << left << setw(4) << course[i].courseName << left << setw(6) << course[i].courseNum;//Print info formatting
                cout << left << setw(25) << course[i].courseTitle << left << setw(7); 
                cout << course[i].courseHours << course[i].courseGrade << endl;
                break;//Required since nested in while loop

            }
            else if(i < courseArrayLength)//Continue array process.
            {
                i++;                   
            }
        }
        if(found == false)
        {
            cout << "No courses with specified grade. Check records or user input." << endl;
            break;
        }
    }


}

/******************************************************* SHOW ALL GRADES *********************************************/
//Prints entire course history to user
void searchAll(courses course[])
{
    int i;

    cout << endl;//Grade output table formatting
    cout << left << setw(10) << "Course" << left << setw(25) << "Title" << setw(7) << "Hours" << "Grade" << endl << endl; 
    
    for (i = 0; i < courseArrayLength; i++) //For loop to iterate through course array of structs
    {

        if (course[i].courseHours == 0)//If function to terminate loop if courseHours is empty. 
        {                             //I'm sure there's a better way to do this, but I'm just using what I know.....
            break;                    //Plus I haven't slept in two days.
        }
        cout << left << setw(4) << course[i].courseName << left << setw(6) << course[i].courseNum;//Print info formatting
        cout << left << setw(25) << course[i].courseTitle << left << setw(7) << course[i].courseHours << course[i].courseGrade << endl; 
    }
    
}

/************************************************ DISPLAY GPA INFORMATION *********************************************/
void showGPA(courses course[])
{
    //Declaration of variables
    int creditHours = 0; //Used to store sum of hours taken by student
    int qualityPoints = 0; //Used to store sum of quality points
    double gpa;

    //For loop to calculate sum of quality (total) hours taken by student
    for (int i = 0; i < courseArrayLength; i++)
    {
        if (course[i].courseHours == 0)//Terminate process if courseHours has not been populated. Allowing complete 
        {                              //Loop through courseHours produces erroneous results.
            break;
        }
        else                           //Else proceed with function as intended
        {
            creditHours = creditHours + course[i].courseHours; //Sum qualityHours. Add to qualityHours on each iteration of loop
        }  
    };


    //For loop to calculate qualityPoints
     for (int i = 0; i < courseArrayLength; i++)
     {
         if (course[i].courseHours == 0)//Terminate process if courseHours has not been populated. 
         {
             break;
         }
         
         else if (strcmp (course[i].courseGrade, "A") == 0|| strcmp(course[i].courseGrade, "a") == 0) 
         {                                      //Use strcmp to check if "a" or "A" is present in courseGrade                           
            qualityPoints = qualityPoints + (course[i].courseHours * 4);  //Assign appropriate quality points value.
         }
         else if (strcmp (course[i].courseGrade, "B") == 0 || strcmp(course[i].courseGrade, "b") == 0) 
         {
            qualityPoints = qualityPoints + (course[i].courseHours * 3);
         }
         else if (strcmp (course[i].courseGrade, "C") == 0 || strcmp(course[i].courseGrade, "c") == 0) 
         {
            qualityPoints = qualityPoints + (course[i].courseHours * 2);
         }
         else if (strcmp (course[i].courseGrade, "D") == 0 || strcmp(course[i].courseGrade, "d") == 0) 
         {
            qualityPoints = qualityPoints + (course[i].courseHours * 1);
         }
         else
         {
            qualityPoints = qualityPoints + 0;
         }  
     }
    //Set output formatting
    cout << fixed << setprecision(2);
     //Perform math operation for gpa
     gpa = qualityPoints / static_cast<double>(creditHours);

    cout << "Calculated GPA: " << gpa << endl;
    
}

/************************************************ SAVE DATA TO FILE ***************************************************/
void saveTo(student entry, courses course[])
{
    ofstream outData; // Declare output filestream variable
    string userFile; //User defined filename variable
    //User prompts and instructions
    cout << "Enter name of file you wish to save with extension (.txt) Ex: myGrades.txt" << endl;
    cout << "Do not use spaces or special characters. Underscores (_) are permitted." << endl;
    cout << "Enter file name: ";

    //User input
    getline(cin, userFile);//Read whole line from user

    //Open output file
    outData.open(userFile.c_str());
    //Message to user if file does not open
    if (!userFile.c_str())
    {
        cout << "Error opening file. Output failed." << endl;
    }
    //Output student name to file
    //outData << entry.studentName << endl;

    //Begin for loop to read array of course structs into file
        for (int i = 0; i < courseArrayLength; i++)
        {
            if (course[i].courseHours == 0)//If function to terminate loop if courseHours is empty. 
            {                             
                break;                    
            }
            outData << course[i].courseName << endl << course[i].courseNum << endl;//Print info formatting
            outData << course[i].courseTitle << endl << course[i].courseHours << endl << course[i].courseGrade << endl;
        }
    outData.close();//Close output file
}

/************************************************ LOAD DATA FROM FILE *************************************************/
void loadFrom(student& entry, courses course[])
{
    ifstream inData; //Declare input filestream variable
    string userFile; //User defined filename variable
    //User prompts and instructions
    cout << "Enter name of file you wish to load including extension (.txt) Ex: myGrades.txt"; 
    cout << endl << "Enter file name: " << endl;

    getline(cin, userFile);//Read whole line from user input above
    //Open input file
    inData.open(userFile.c_str());
    //Message to user if file does not open
    if (!inData)
    {
        cout << "Unable to open file. Check spelling or ensure valid file location." << endl;
    }




    for (int i = 0; i < courseArrayLength; i++)//For loop to iterate through and populate course struct array
    {
        inData >> course[i].courseName;
        inData >> course[i].courseNum; 
        inData.ignore();//Skips blank space after courseNum
        getline(inData, course[i].courseTitle);//Get full line from course title
        inData >> course[i].courseHours;
        inData >> course[i].courseGrade;
    }

    inData.close();//Close file after reading into course array

}