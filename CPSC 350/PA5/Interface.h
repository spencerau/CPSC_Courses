/*
Spencer Au
ID: 002385256
spau@chapman.edu

Partner:
Ben Fellows
bfellows@chapman.edu

CPSC 350 - Section 2
PA5

Your program will keep references to both the faculty and student tables in memory. These references are simply ScapegoatST instances.
Once the tables have been created, a menu should be presented to the user to allow them to manipulate the database. The choices should include:
1. Print all students and their information (sorted by ascending id #)
2. Print all faculty and their information (sorted by ascending id #)
3. Find and display student information given the students id
4. Find and display faculty information given the faculty id
5. Add a new student
6. Delete a student given the id
7. Add a new faculty member
8. Delete a faculty member given the id.
9. Change a student’s advisor given the student id and the new faculty id.
10. Remove an advisee from a faculty member given the ids
11. Exit
When a command is selected, you should prompt the user for the required data, and execute the command. If there are any errors, you should inform 
the user describing what the error is and abort the command.

All of the above commands should enforce referential integrity. That is to say, a student can not have an advisor that is not in the faculty table. 
A faculty member can’t have an advisee not in the student table. If a faculty member is deleted, then their advisees must have their advisors 
changed, etc. Your commands will be responsible for maintaining referential integrity. If a user issues a command that would break referential 
integrity, you should warn them and abort the command, or execute the command and fix any violations as appropriate.
 
After each command is executed, the menu should be displayed again, and the user allowed to continue.
If the user selects the Exit option, prior to quitting your program should create a file, named runLog.txt, which contains the information of both 
tables at the time the program was terminated. (This is the information from option 1 and option 2, 
just printed to the file instead of the terminal).

Interface() - constructor that initalizes the student and faculty trees

~Interface() - deletes the student and faculty trees

void run() - simulates the menu, and uses a switch statement to choose options 1 to 11, and exits upon option 11

void printOptions() - prints out the menu options at the top

void printAllStudents() - Print all students and their information (sorted by ascending id #)
void printAllFaculty() - Print all faculty and their information (sorted by ascending id #)
void printStudent(int id) - takes an int id and prints out that student
void printFaculty(int id) - takes an int id and prints out that faculty

void addStudent() - adds a new student
void deleteStudent(int id) - takes an int id and deletes that student and also removes them from their advisor's advisees list

void addFaculty() - adds a new faculty member
void deleteFaculty(int id) - takes an int id and deletes that faculty member and then prompts the user for an id to switch over advisees

void changeAdvisor(int studentid, int facultyid) - takes an int studentid and int facultyid and switches the student to that faculty member

void removeAdvisee(int studentid, int facultyid) - takes an int studentid and int faculty id and removes that student from the faculty advisees

int promptForStudent(int flag) - takes an int flag, and if 0, keeps prompting for an id that exists, and if 1, keeps prompting for a new id
int promptForFaculty(int flag) - takes an int flag, and if 0, keeps prompting for an id that exists, and if 1, keeps prompting for a new id

void writeToFile() - intializes an ofstream writer, and calls students/faculty->writeToFile()

bool isEmpty(int flag) - takes an int flag, and if 0, checks if the students tree is empty, and if 1, checks if faculty tree is empty
*/

#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>
#include "Student.h"
#include "Faculty.h"
#include "ScapegoatST.h"

using namespace std;

class Interface {
public:
    Interface();
    ~Interface();
    void run();
    /*
    void test8();
    void test9();
    void test11();
    */
    
private:
    ScapegoatST<Student*> *students;
    ScapegoatST<Faculty*> *faculty;

    void printOptions();
    void printAllStudents();
    void printAllFaculty();
    void printStudent(int id);
    void printFaculty(int id);
    void addStudent();
    void deleteStudent(int id);
    void addFaculty();
    void deleteFaculty(int id);
    void changeAdvisor(int studentid, int facultyid);
    void removeAdvisee(int studentid, int facultyid);
    int promptForStudent(int flag);
    int promptForFaculty(int flag);
    void writeToFile();
    bool isEmpty(int flag);

    //int promptByID(int flag);
    //void testPeople();
};


#endif