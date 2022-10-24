#include <cstdlib>
#include <iostream>
#include "Customer.h"

using namespace std;

Customer::Customer(int finAid, int regist, int cash, ListQueue<char> *order) {
    this->wait = 0;
    this->finAid = finAid;
    this->regist = regist;
    this->cash = cash;
    this->prev = NULL;
    this->next = NULL;
    this->order = order;
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

Customer* Customer::getPrev() {
    return prev;
}

Customer* Customer::getNext() {
    return next;
}

char Customer::pop() {
    return order->remove();
}

char Customer::peek() {
    return order->peek();
}

void Customer::popOrder() {
    order->remove();
}   

char Customer::getDest() {
    return order->peek();
}