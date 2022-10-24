#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <cstdlib>
#include <iostream>
#include "ListQueue.h"

using namespace std;

class Customer {
public:
    Customer(int finAid, int regist, int cash, ListQueue<char> *order);
    ~Customer();
    void passTime();
    int getWait();
    int getFinAid();
    int getRegist();
    int getCash();
    Customer* getPrev();
    Customer* getNext();
    char pop();
    char peek();
    void popOrder();
    char getDest();
private:
    int wait;
    int finAid;
    int regist;
    int cash;

    ListQueue<char> *order;
    Customer *prev;
    Customer *next;
};

#endif