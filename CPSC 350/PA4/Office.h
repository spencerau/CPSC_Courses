// Office - models an individual office in the service center

#ifndef OFFICE_H
#define OFFICE_H

#include <cstdlib>
#include <iostream>
#include "Window.h"

using namespace std;

class Office {
public:
    Office(int size, char type);
    ~Office();
    void passTime();
private:
    ListQueue<Window> *office;
    char type;
    int maxWindows;
    int occupWindows;
};

#endif