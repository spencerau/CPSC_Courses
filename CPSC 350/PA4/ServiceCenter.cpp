/*
Spencer Au
ID: 002385256
spau@chapman.edu
CPSC 350 - Section 2
PA4

CPP File for ServiceCenter that represents a Service Center with 3 Offices


ServiceCenter(string filename) - Constructor that takes an input filename and initializes variables, calls readFile(filename)
~ServiceCenter() - Destructor

void readFile(string filename) - Function that handles File I/O for reading from the txt file. It creates 3 Offices with respective amount of 
Windows from the first 3 lines, and then calls passTime() for the target time, stores the amount of students that are going to be arriving, and 
calls readLine(line) based on number of students that creates a new Customer, and calls Office.lineUp(student) for the respective office. It will call
passTime() until all students have finished.

void passTime() - Simulates a single minute passing in the Service Center. Calls passTime() on each of the 3 offices, and if any of the offices have
finished students, it pops the student, and if the student has offices left to go to, it calls Office.lineUp() at the respective office, else if the 
student is fully finished, then it adds the studet to finished

Customer* readLine(string line) - Takes a string line and returns a Customer created from that line; Format: time1 time2 time3 office1 office2 office3

void printMeanWait()- Prints the mean student wait time for each office by calling Office.getMeanWait()
void printLongestWait() -Prints the longest student wait time for each office by calling Office.getLongestWait()
void printWaitOver10() - Prints the number of students waiting over 10 minutes total across all offices by iterating through finished
void printMeanIdle() - Prints the mean window idle time for each office by calling Office.getMeanIdle()
void printLongestIdle() - Prints the longest window idle time for each office by calling Office.getLongestIdle()
void printIdleOver5() - Prints the number of windows idle for over 5 minutes across all offices by calling Office.getIdleOver5()

void printResult() - Function that prints out the 6 above functions to display

void printFinished() - Print Function that prints out the finished ListQ of students 
void printNewLine() - Prints out a Line to separate output
*/

#include <iostream>
#include "ServiceCenter.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

/*
ServiceCenter(string filename) - Constructor that takes an input filename and initializes variables, calls readFile(filename)
*/
ServiceCenter::ServiceCenter(string filename) {
    studentLine = new ListQueue<Customer*>();
    finished = new DblList<Customer*>();
    numStudents = 0;
    readFile(filename);
    time = 0;
}

ServiceCenter::~ServiceCenter() {
    delete cashier;
    delete finAid;
    delete registrar;
    delete studentLine;
    delete finished;
}

/*
void readFile(string filename) - Function that handles File I/O for reading from the txt file. It creates 3 Offices with respective amount of 
Windows from the first 3 lines, and then calls passTime() for the target time, stores the amount of students that are going to be arriving, and 
calls readLine(line) based on number of students that creates a new Customer, and calls Office.lineUp(student) for the respective office. It will call
passTime() until all students have finished.
*/
void ServiceCenter::readFile(string filename) {
    ifstream read(filename);
    // this is the File I/O bullshit
    // create 3 Offices with the respective amount of windows 
    // enqueue each student with the first office they need with times etc

    // 2 windows at registrar
    // 3 at cashier
    // 1 at fin aid
    // at time 1, 2 students arrive
    // first student needs 5 at regist, 1 at cash, 2 at fin aid
    // second student needs 10 at fin aid, 5 at regist, 1 at cash
    // at time 3, 1 student arrives
    // student 3 needs 4 at regist, 2 at cash, 6 at fin aid

    printNewLine();
    int windows;
    string line;
    getline(read, line);
    windows = stoi(line);
    this->registrar = new Office(windows, 'R');
    cout << "The Registrar's Office has " << windows << " windows." << endl;
    getline(read, line);
    windows = stoi(line);
    this->cashier = new Office(windows, 'C');
    cout << "The Cashier's Office has " << windows << " windows." << endl;
    getline(read, line);
    windows = stoi(line);
    this->finAid = new Office(windows, 'F');    
    cout << "The Financial Aid Office has " << windows << " windows." << endl;
    printNewLine();

    //int current = 0;
    int target = 0;
    while (getline(read, line)) {
        //cout << "This should be the time " << line << endl;
        target = stoi(line);
        //cout << "target time is " << target << endl;
        while (time < target) {
            passTime();
            //cout << "Target time is " << target << endl;
        }
        getline(read, line);
        //cout << "This should be the number of students " << line << endl;
        int addStudents = stoi(line);
        cout << "The will be " << addStudents << " students joining the queue at this time." << endl;
        cout << endl;
    
        for (int i = 0; i < addStudents; i++) {
            getline(read, line);
            Customer *student = readLine(line);
            switch (student->getDest()) {
                case 'F':
                    finAid->lineUp(student);
                    break;
                case 'R':
                    registrar->lineUp(student);
                    break;
                case 'C':
                    cashier->lineUp(student);
                    break;
            }
            numStudents++;
            cout << endl;
        }
        printNewLine();
    }
    read.close();
    while (finished->getSize() != numStudents) { 
        passTime();
        //cout << "Size of Finished: " << finished->getSize() << endl;
        //cout << "Num Students: " << numStudents << endl; 
    }
   //printFinished();
   printNewLine();
}

/*
Customer* readLine(string line) - Takes a string line and returns a Customer created from that line; Format: time1 time2 time3 office1 office2 office3
*/
Customer* ServiceCenter::readLine(string line) {
    stringstream fullLine(line);
    int a;
    fullLine >> a;
    int b;
    fullLine >> b;
    int c;
    fullLine >> c;

    int finAid;
    int regist;
    int cash;

    char first;
    fullLine >> first;
    char second;
    fullLine >> second;
    char third;
    fullLine >> third;

    cout << "Student " << numStudents << " Destination Order: " << first << " - " << second << " - " << third << endl;
    ListQueue<char> *order = new ListQueue<char>();
    order->add(first);
    order->add(second);
    order->add(third);

    // this is a dogshit way to parse the line but it works so meh
    switch (first) {
        case 'F':
            finAid = a;
            break;
        case 'R':
            regist = a;
            break;
        case 'C':
            cash = a;
            break;
    }

    switch (second) {
        case 'F':
            finAid = b;
            break;
        case 'R':
            regist = b;
            break;
        case 'C':
            cash = b;
            break;
    }

    switch (third) {
        case 'F':
            finAid = c;
            break;
        case 'R':
            regist = c;
            break;
        case 'C':
            cash = c;
            break;
    }

    Customer *student = new Customer(finAid, regist, cash, order, numStudents);
    cout << "Student " << numStudents << " needs: " << student->getFinAid() << " min at FinAid, " << student->getRegist() << " min at Regist, " 
    << student->getCash() << " min at Cashier." << endl;
    return student;
}

void ServiceCenter::printFinished() {
    cout << "Finished List in ServiceCenter" << endl;
    for (int i = 0; i < finished->getSize(); i++) {
        cout << "Index " << i << ": Student " << finished->get(i)->num << endl;
    }
}

/*
void passTime() - Simulates a single minute passing in the Service Center. Calls passTime() on each of the 3 offices, and if any of the offices have
finished students, it pops the student, and if the student has offices left to go to, it calls Office.lineUp() at the respective office, else if the 
student is fully finished, then it adds the studet to finished
*/
void ServiceCenter::passTime() {
    //for (int i = current; i < target; i++) {
    cout << "CURRENT TIME: " << time << endl;
    time++;
    cashier->printWindows();
    finAid->printWindows();
    registrar->printWindows();
    cashier->passTime();
    finAid->passTime();
    registrar->passTime();

    while (!cashier->getFinished()->isEmpty()) {
        Customer* student = cashier->getFinished()->remove();
        if (student->getOrder()->isEmpty()) {
            finished->addBack(student);
        }
        else {
            char dest = student->getOrder()->peek();
            if (dest == 'F') finAid->lineUp(student);
            else if (dest == 'R') registrar->lineUp(student);
            else if (dest == 'C') finished->addBack(student);
        }
        //delete student;
    }

    while (!finAid->getFinished()->isEmpty()) {
        Customer* student = finAid->getFinished()->remove();
        //cout << "THIS SHOULD BE EMPTY: " << student->getOrder()->peek() << endl;
        if (student->getOrder()->isEmpty()) {
            finished->addBack(student);
        }
        else {
            char dest = student->getOrder()->peek();
            if (dest == 'C') cashier->lineUp(student);
            else if (dest == 'R') registrar->lineUp(student);
            else if (dest == 'F') finished->addBack(student);
        }
        //delete student;
    }

    while (!registrar->getFinished()->isEmpty()) {
        Customer* student = registrar->getFinished()->remove();
        if (student->getOrder()->isEmpty()) {
            finished->addBack(student);
            //cout << "THE SIZE OF FINISHED IN SERVICECENTER IS " << finished << endl;
        }
        else {
            char dest = student->getOrder()->peek();
            if (dest == 'F') finAid->lineUp(student);
            else if (dest == 'C') cashier->lineUp(student);
            else if (dest == 'R') finished->addBack(student);
        }
    }
}

void ServiceCenter::printResult() {
    printMeanWait();
    printLongestWait();
    printWaitOver10();
    printMeanIdle();
    printLongestIdle();
    printIdleOver5();
}

/*
void printMeanWait()- Prints the mean student wait time for each office by calling Office.getMeanWait()
*/
void ServiceCenter::printMeanWait() {
    cout << "Average Wait Time:" << endl;
    cout << "Cashier: " << cashier->getMeanWait() << endl;
    cout << "Financial Aid: " << finAid->getMeanWait() << endl;
    cout << "Registrar: " << registrar->getMeanWait() << endl;
    printNewLine();
}

/*
void printLongestWait() -Prints the longest student wait time for each office by calling Office.getLongestWait()
*/
void ServiceCenter::printLongestWait() {
    cout << "Longest Wait: " << endl;
    cout << "Cashier: " << cashier->getLongestWait() << endl;
    cout << "Financial Aid: " << finAid->getLongestWait() << endl;
    cout << "Registrar: " << registrar->getLongestWait() << endl;
    printNewLine();
}
    
/*
void printWaitOver10() - Prints the number of students waiting over 10 minutes total across all offices by iterating through finished
*/
void ServiceCenter::printWaitOver10() {
    int waitOver10 = 0;
    for (int i = 0; i < finished->getSize(); i++) {
        if (finished->get(i)->getTotalWait() >= 10) {
            waitOver10 += finished->get(i)->getTotalWait();
        }
    }
    cout << "Number of Students Waiting over 10 Min: " << waitOver10 << endl;
    printNewLine();
}

/*
void printMeanIdle() - Prints the mean window idle time for each office by calling Office.getMeanIdle()
*/
void ServiceCenter::printMeanIdle() {
    cout << "Average Window Idle Time: " << endl;
    cout << "Cashier: " << cashier->getMeanIdle() << endl;
    cout << "Financial Aid: " << finAid->getMeanIdle() << endl;
    cout << "Registrar: " << registrar->getMeanIdle() << endl;
    printNewLine();
}

/*
void printLongestIdle() - Prints the longest window idle time for each office by calling Office.getLongestIdle()
*/
void ServiceCenter::printLongestIdle() {
    cout << "Longest Window Idle Time: " << endl;
    cout << "Cashier: " << cashier->getLongestIdle() << endl;
    cout << "Financial Aid: " << finAid->getLongestIdle() << endl;
    cout << "Registrar: " << registrar->getLongestIdle() << endl;
    printNewLine();
}

/*
void printIdleOver5() - Prints the number of windows idle for over 5 minutes across all offices by calling Office.getIdleOver5()
*/
void ServiceCenter::printIdleOver5() {
    int amount = cashier->getIdleOver5();
    amount += registrar->getIdleOver5();
    amount += finAid->getIdleOver5();
    cout << "Number of Windows Idle over 5 Min: " << amount << endl;
}

void ServiceCenter::printNewLine() {
    cout << "-------------------------------------------------------------------" << endl;
}