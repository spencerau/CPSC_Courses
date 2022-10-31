#include <cstdlib>
#include <iostream>
#include "Customer.h"
/*
#include "ListNode.h"
#include "DblList.h"
#include "ListQueue.h"
*/

using namespace std;

Customer::Customer(int finAid, int regist, int cash, ListQueue<char> *order, int num) {
    this->finAid = finAid;
    this->regist = regist;
    this->cash = cash;
    this->order = order;
    
    this->attendTime = 0;
    this->curWait = 0;
    this->totalWait = 0;
    this->waiting = true;

    this->num = num;
}

Customer::~Customer() {
    delete order;
}

int Customer::getCurWait() {
    return curWait;
}

int Customer::getTotalWait() {
    return totalWait;
}

int Customer::getFinAid() {
    return finAid;
}

int Customer::getRegist() {
    return regist;
}

int Customer::getCash() {
    return cash;
}

char Customer::getDest() {
    return order->peek();
}

int Customer::getAttendTime() {
    return attendTime;
}

ListQueue<char>*& Customer::getOrder() {
    return order;
}

void Customer::attend() {
    waiting = false;
    /*
    cout << "current office is " << order->peek() << endl;
    cout << "Student needs " << cash << " min at Cashier" << endl;
    cout << "Student needs " << finAid << " min at Fin Aid" << endl;
    cout << "Student needs " << regist << " min at Registrar" << endl;
    */
}

void Customer::finish() {
    totalWait += curWait;
    curWait = 0;
    order->remove();
    if (order->isEmpty()) {
        cout << "STUDENT " << num << " IS DONE, ORDER IS EMPTY, AND THIS IS CALLED IN THE CUSTOMER.CPP CLASS" << endl;
    }
    attendTime = 0;
    waiting = true;
}

void Customer::passTime() {
    if (waiting) {
        curWait++;
        cout << "Student " << num << " is Waiting" << endl;
    }
    else {
        attendTime++;
        cout << "Student " << num << " is being Attended To at Window " << order->peek() << endl;
    }
}