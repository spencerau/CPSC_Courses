#ifndef SERVICECENTER_H
#define SERVICECENTER_h

#include <iostream>
#include "Office.h"
#include <fstream>

using namespace std;

class ServiceCenter {
public:
    ServiceCenter(string filename);
    ~ServiceCenter();
    void readFile(string filename);
    void passTime();
    void readLine(string line);
private:
    Office *cashier;
    Office *finAid;
    Office *registrar;
};

#endif