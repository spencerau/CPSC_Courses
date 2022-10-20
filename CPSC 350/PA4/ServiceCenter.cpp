#include <iostream>
#include "Office.h"
#include "ServiceCenter.h"
#include <fstream>

using namespace std;

ServiceCenter::ServiceCenter(string filename) {
    readFile(filename);

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


    // this block of bullshit is temporary because File I/O is some big brain shit
    this->registrar = new Office(2, 'r');
    this->cashier = new Office(3, 'c');
    this->finAid = new Office(1, 'f');

    ListQueue<char> *order1 = new ListQueue<char>;
    order1->add('r');
    order1->add('c');
    order1->add('f');
    Customer *student1 = new Customer(2, 5, 1, order1);
    registrar->lineUp(student1);

    ListQueue<char> *order2 = new ListQueue<char>;
    order2->add('f');
    order2->add('r');
    order2->add('c');
    Customer *student2 = new Customer(10, 5, 1, order2);
    finAid->lineUp(student2);

    int time = 3 - 1;
    for (int i = 0; i < time; i++) {
        passTime();
    }

    ListQueue<char> *order3 = new ListQueue<char>;
    order3->add('r');
    order3->add('c');
    order3->add('f');
    Customer *student3 = new Customer(6, 4, 2, order3);
    finAid->lineUp(student3);

    read.close();


}

Customer* readLine(string line) {
    int cash;
    int finAid;
    int regist;
    ListQueue<char> *order = new ListQueue<char>();


    Customer *student = new Customer(finAid, regist, cash, order);
    return student;
}

void ServiceCenter::passTime() {

}