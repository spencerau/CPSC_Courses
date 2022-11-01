/*
Spencer Au
ID: 002385256
spau@chapman.edu
CPSC 350 - Section 2
PA4

Header File for Customer

Functions:
    Customer(int finAid, int regist, int cash, ListQueue<char> *order, int num) - Constructor that takes an intial int for the time needed at the
    Financial Aid, Registrar, and Cashier office, a ListQueue of the order of offices to visit, and a int num that represents which student it is
    ~Customer() - deconstructor

    int getCurWait() - accessor for current wait
    int getTotalWait() - accessor for total time waiting
    int getFinAid() - acessor for time needed at Fin Aid
    int getRegist() - acessor for time needed at registrar
    int getCash() - accessor for time needed at cashier
    char getDest() - acessor for destination
    int getAttendTime() - accessor for current time spent at office
    ListQueue<char>*& getOrder() - acessor for the order of offices

    bool isWaiting() - check if the student is currently waiting
    void attend() - simulates the student being attended by an office; sets waiting to false
    void finish() - simulates a student finishing at an office; adds the current wait to total wait, sets current wait to 0, pops the front value
    off order, sets attendTime to 0, and sets waiting to true
    void passTime() - simulates one min passed; if the student is waiting then it iterates currWait; if the student is being attended it iterates 
    attendTime

Variables:
    int num - numerical identifier for student

    int finAid - time needed at finAid office
    int regist - time needed at registrar office
    int cash - time needed at cashier
    char office - current office

    int attendTime - time spend at current window being helped
    int curWait - time spend waiting at current office
    int totalWait - total time spent waiting
    bool waiting - if student is waiting or not

    ListQueue<char> *order - order of offices to visit
*/

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <cstdlib>
#include <iostream>
#include "ListQueue.h"

using namespace std;

class Customer {
public:
    Customer(int finAid, int regist, int cash, ListQueue<char> *order, int num);
    ~Customer();

    int getCurWait();
    int getTotalWait();
    int getFinAid();
    int getRegist();
    int getCash();
    char getDest();
    int getAttendTime();
    ListQueue<char>*& getOrder();

    bool isWaiting();
    void attend();
    void finish();
    void passTime();
    
    int num;
private:
    int finAid;
    int regist;
    int cash;
    char office;

    int attendTime;
    int curWait;
    int totalWait;
    bool waiting;

    ListQueue<char> *order;
};

#endif