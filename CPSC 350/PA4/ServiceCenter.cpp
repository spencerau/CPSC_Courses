#include <iostream>
#include "Office.h"
#include "ServiceCenter.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

ServiceCenter::ServiceCenter(string filename) {
    readFile(filename);
    students = 0;
}

ServiceCenter::~ServiceCenter() {

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

    int windows;
    read >> windows;
    this->registrar = new Office(windows, 'r');
    cout << "The Registrar's Office has " << windows << "windows." << endl;
    read >> windows;
    this->cashier = new Office(windows, 'c');
    cout << "The Cashier's Office has " << windows << "windows." << endl;
    read >> windows;
    this->finAid = new Office(windows, 'f');    
    cout << "The Financial Aid Office has " << windows << "windows." << endl;

    string line;
    int i = 0;
    while (getline(read, line)) {
        int time = stoi(line);
        passTime(time);
        cout << "Time: " << time << endl;

        getline(read, line);
        int numStudents = stoi(line);
        cout << "The will be " << numStudents << " students joining the Queue at this time." << endl;

        for (int i = 0; i < numStudents; i++) {
            getline(read, line);
            Customer *student = readLine(line);
            //cout << "Student " << students << " "
            switch (student->getDest()) {
                case 'f':
                    finAid->lineUp(student);
                    break;
                case 'r':
                    registrar->lineUp(student);
                    break;
                case 'c':
                    cashier->lineUp(student);
                    break;
            }

            registrar->lineUp(readLine(line));
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
        case 'f':
            finAid = line[0];
            break;
        case 'r':
            regist = line[0];
            break;
        case 'c':
            cash = line[0];
            break;
    }

    switch (second) {
        case 'f':
            finAid = line[2];
            break;
        case 'r':
            regist = line[2];
            break;
        case 'c':
            cash = line[2];
            break;
    }

    switch (third) {
        case 'f':
            finAid = line[4];
            break;
        case 'r':
            regist = line[4];
            break;
        case 'c':
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
        //if (cashier.)
    }
}