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

    read.close();
}

void ServiceCenter::passTime() {

}