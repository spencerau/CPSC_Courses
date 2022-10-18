#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <cstdlib>
#include <iostream>
using namespace std;

class Customer {
public:
    Customer(int finAid, int regist, int cash);
    ~Customer();
    void passTime();
    int getWait();
    int getFinAid();
    int getRegist();
    int getCash();
    Customer getPrev();
    Customer getNext();
private:
    int wait;
    int finAid;
    int regist;
    int cash;

    Customer *prev;
    Customer *next;
};

Customer::Customer(int finAid, int regist, int cash) {
    this->wait = 0;
    this->finAid = finAid;
    this->regist = regist;
    this->cash = cash;
    this->prev = NULL;
    this->next = NULL;
}

Customer::~Customer() {
    prev = NULL;
    next = NULL;
}

void Customer::passTime() {
    wait++;
}

int Customer::getWait() {
    return wait;
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

Customer Customer::getPrev() {
    //return (Customer)prev;
}

#endif