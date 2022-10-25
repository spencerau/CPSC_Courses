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
    read >> windows;
    this->registrar = new Office(windows, 'r');
    cout << "The Registrar's Office has " << windows << " windows." << endl;
    read >> windows;
    this->cashier = new Office(windows, 'c');
    cout << "The Cashier's Office has " << windows << " windows." << endl;
    read >> windows;
    this->finAid = new Office(windows, 'f');    
    cout << "The Financial Aid Office has " << windows << " windows." << endl;
    printNewLine();

    string line;
    int i = 0;
    while (getline(read, line)) {
        getline(read, line);
        //cout << line << endl;
        int time = stoi(line);
        passTime(time);
        cout << "Time: " << time << endl;

        getline(read, line);
        int numStudents = stoi(line);
        cout << "The will be " << numStudents << " students joining the Queue at this time." << endl;

        bool first = true;

        for (int i = 0; i < numStudents; i++) {
            if (!first) {
                getline(read, line);
                time = stoi(line);
                passTime(time);
            }
            getline(read, line);
            cout << line << endl;
            first = false;
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
        }
    }
    // this block of bullshit is temporary because File I/O is some big brain shit

    read.close();


}

Customer* ServiceCenter::readLine(string line) {
    char first = line[6];
    char second = line[8];
    char third = line[10];

    int finAid;
    int regist;
    int cash;

    cout << "Student " << ++students << ": Destination Order -> " << first << " - " << second << " - " << third << endl;
    ListQueue<char> *order = new ListQueue<char>();
    order->add(first);
    order->add(second);
    order->add(third);

    switch (first) {
        case 'F':
            finAid = line[0];
            break;
        case 'R':
            regist = line[0];
            break;
        case 'C':
            cash = line[0];
            break;
    }

    switch (second) {
        case 'F':
            finAid = line[2];
            break;
        case 'R':
            regist = line[2];
            break;
        case 'C':
            cash = line[2];
            break;
    }

    switch (third) {
        case 'F':
            finAid = line[4];
            break;
        case 'R':
            regist = line[4];
            break;
        case 'C':
            cash = line[4];
            break;
    }

    Customer *student = new Customer(finAid, regist, cash, order);
    cout << "Student " << students << " needs: " << finAid << " min at FinAid, " << regist << " min at Regist, " << cash << " min at Cash." << endl;
    return student;
}

void ServiceCenter::passTime(int time) {
    for (int i = 1; i < time; i++) {
        cashier->passTime();
        finAid->passTime();
        registrar->passTime();

        if (!cashier->getFinished()->isEmpty()) {
            Customer* student = cashier->getFinished()->remove();
            if (student->isFinished()) finished->add(student);
            else {
                char dest = student->getOrder()->peek();
                if (dest == 'F') finAid->lineUp(student);
                else if (dest == 'R') registrar->lineUp(student);
            }
        }

        if (!finAid->getFinished()->isEmpty()) {
            Customer* student = finAid->getFinished()->remove();
            if (student->isFinished()) finished->add(student);
            else {
                char dest = student->getOrder()->peek();
                if (dest == 'C') cashier->lineUp(student);
                else if (dest == 'R') registrar->lineUp(student);
            }
        }

        if (!registrar->getFinished()->isEmpty()) {
            Customer* student = registrar->getFinished()->remove();
            if (student->isFinished()) finished->add(student);
            else {
                char dest = student->getOrder()->peek();
                if (dest == 'F') finAid->lineUp(student);
                else if (dest == 'C') cashier->lineUp(student);
            }
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