#include <iostream>
//#include "Office.h"
#include "ServiceCenter.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

ServiceCenter::ServiceCenter(string filename) {
    studentLine = new ListQueue<Customer*>();
    finished = new ListQueue<Customer*>();
    students = 0;
    readFile(filename);
    waitOver10 = 0;
}

ServiceCenter::~ServiceCenter() {
    delete cashier;
    delete finAid;
    delete registrar;
    delete studentLine;
    delete finished;
}

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

    int current = 0;
    int target = 0;
    while (getline(read, line)) {
        //cout << "This should be the time " << line << endl;
        target = stoi(line);
        //cout << "target time is " << target << endl;
        while (current < target) {
            cout << "current time is " << current << endl;
            cout << "target time is " << target << endl;

            
            passTime();
            current++;
        }
        //current = target;
        cout << "Time: " << current << endl;

        getline(read, line);
        //cout << "This should be the number of students " << line << endl;
        int numStudents = stoi(line);
        cout << "The will be " << numStudents << " students joining the queue at this time." << endl;
    
        for (int i = 0; i < numStudents; i++) {
            getline(read, line);
            Customer *student = readLine(line);
            students++;
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
            printNewLine();
        }
    }
    // this block of bullshit is temporary because File I/O is some big brain shit

    read.close();

    for (int i = 0; i < 12; i++) {
        //cout << endl << "Current time is " << current << endl;
        //cout << "target time is " << target << endl;
        //current++;
        passTime();
        cout << "Size of Finished: " << finished->size() << endl;
        cout << "Students: " << students << endl;
    }
    /*
    while (finished->size() != students) {  
        passTime();
    }
    */
}

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

    cout << "Student " << ++students << " Destination Order: " << first << " - " << second << " - " << third << endl;
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

    Customer *student = new Customer(finAid, regist, cash, order);
    cout << "Student " << students << " needs: " << student->getFinAid() << " min at FinAid, " << student->getRegist() << " min at Regist, " 
    << student->getCash() << " min at Cashier." << endl;
    return student;
}

void ServiceCenter::passTime() {
    //for (int i = current; i < target; i++) {
    cashier->printWindows();
    finAid->printWindows();
    registrar->printWindows();
    cashier->passTime();
    //cout << "CASH passtime worked" << endl;
    finAid->passTime();
    //cout << "FinAid passtime worked" << endl;
    registrar->passTime();
    //cout << "Regist passTime worked" << endl;
    //cout << "all passTime() for Office.cpp worked" << endl;

    while (!cashier->getFinished()->isEmpty()) {
        //cout << "Cashier *finished is not empty" << endl;
        Customer* student = cashier->getFinished()->remove();
        if (student->getOrder()->isEmpty()) {
            finished->add(student);
        }
        else {
            char dest = student->getOrder()->peek();
            if (dest == 'F') finAid->lineUp(student);
            else if (dest == 'R') registrar->lineUp(student);
        }
        //delete student;
    }

    while (!finAid->getFinished()->isEmpty()) {
        Customer* student = finAid->getFinished()->remove();
        if (student->getOrder()->isEmpty()) finished->add(student);
        else {
            char dest = student->getOrder()->peek();
            if (dest == 'C') cashier->lineUp(student);
            else if (dest == 'R') registrar->lineUp(student);
        }
        //delete student;
    }

    while (!registrar->getFinished()->isEmpty()) {
        Customer* student = registrar->getFinished()->remove();
        if (student->getOrder()->isEmpty()) finished->add(student);
        else {
            char dest = student->getOrder()->peek();
            if (dest == 'F') finAid->lineUp(student);
            else if (dest == 'C') cashier->lineUp(student);
        }
        //delete student;

    }
}

void ServiceCenter::printResult() {
    printMeanWait();
    //printLongestWait();
    //printWaitOver10();
    //printMeanIdle();
    //printLongestIdle();
    //printIdleOver5();
}

// The mean student wait time for each office.
void ServiceCenter::printMeanWait() {
    cout << "Average Wait Time:" << endl;
    cout << "Cashier: " << cashier->getMeanWait() << endl;
    cout << "Financial Aid: " << finAid->getMeanWait() << endl;
    cout << "Registrar: " << registrar->getMeanWait() << endl;
    printNewLine();
}

// The longest student wait time for each office.
void ServiceCenter::printLongestWait() {
    cout << "Longest Wait: " << endl;
    cout << "Cashier: " << cashier->getLongestWait() << endl;
    cout << "Financial Aid: " << finAid->getLongestWait() << endl;
    cout << "Registrar: " << registrar->getLongestWait() << endl;
    printNewLine();
}
    
// The number of students waiting over 10 minutes total across all offices.
void ServiceCenter::printWaitOver10() {
    cout << "Number of Students Waiting over 10 Min: " << waitOver10 << endl;
    printNewLine();
}
// The mean window idle time for each office
void ServiceCenter::printMeanIdle() {
    cout << "Average Window Idle Time: " << endl;
    cout << "Cashier: " << cashier->getMeanIdle() << endl;
    cout << "Financial Aid: " << finAid->getMeanIdle() << endl;
    cout << "Registrar: " << registrar->getMeanIdle() << endl;
    printNewLine();
}

// The longest window idle time for each office
void ServiceCenter::printLongestIdle() {
    cout << "Longest Window Idle Time: " << endl;
    cout << "Cashier: " << cashier->getLongestIdle() << endl;
    cout << "Financial Aid: " << finAid->getLongestIdle() << endl;
    cout << "Registrar: " << registrar->getLongestIdle() << endl;
    printNewLine();
}

// Number of windows idle for over 5 minutes across all offices.
void ServiceCenter::printIdleOver5() {
    int amount = cashier->getIdleOver5();
    amount += registrar->getIdleOver5();
    amount += finAid->getIdleOver5();
    cout << "Number of Windows Idle over 5 Min: " << amount << endl;
}

void ServiceCenter::printNewLine() {
    cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
}