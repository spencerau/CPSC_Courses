#include <cstdlib>
#include <iostream>
#include "Customer.h"
/*
#include "ListNode.h"
#include "DblList.h"
#include "ListQueue.h"
*/

using namespace std;

Customer::Customer(int finAid, int regist, int cash, ListQueue<char> *order) {
    this->finAid = finAid;
    this->regist = regist;
    this->cash = cash;
    this->order = order;
    
    this->attending = 0;
    this->curWait = 0;
    this->totalWait = 0;
    this->waiting = true;
    this->timeNeeded = 0;
    this->done = false;
    this->fullyDone = false;
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

int Customer::getTimeNeeded() {
    return timeNeeded;
}

int Customer::getAttending() {
    return attending;
}

bool Customer::isDone() {
    return done;
}

bool Customer::isFinished() {
    return fullyDone;
}

ListQueue<char>* Customer::getOrder() {
    return order;
}

void Customer::lineUp() {
    done = false;
}

void Customer::attend() {
    waiting = false;
    switch (order->peek()) {
        case 'C':
            timeNeeded = cash;
            break;
        case 'F':
            timeNeeded = finAid;
            break;
        case 'R':
            timeNeeded = regist;
            break;
    }
}

void Customer::finish() {
    totalWait += curWait;
    curWait = 0;
    order->remove();
    attending = 0;
    waiting = true;
    done = true;
    if (order->isEmpty()) fullyDone = true;
}

void Customer::passTime() {
    if (waiting) curWait++;
    else attending++;
}