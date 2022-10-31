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

    int getCurWait();
    int getTotalWait();
    int getFinAid();
    int getRegist();
    int getCash();
    char getDest();
    int getAttending();
    ListQueue<char>*& getOrder();

    bool isWaiting();
    void attend();
    void finish();
    void passTime();

private:
    int finAid;
    int regist;
    int cash;
    char office;

    int attending;
    int curWait;
    int totalWait;
    bool waiting;

    ListQueue<char> *order;
};

#endif