#include "ACStack.h"
#include <cstdlib>
#include <iostream>
using namespace std;

ACStack::ACStack(){ //O(1)
  top = -1;
  count = 0;
  max = 0;
  stackArr = NULL;
}

ACStack::ACStack(int iSize){ //O(1)
  top = -1;
  count = 0;
  max = iSize;
  stackArr = new char[max];
}

ACStack::~ACStack(){ //O(1)
  delete[] stackArr;
}

int ACStack::size(){ //O(1)
  return count;
}

bool ACStack::isEmpty(){ //O(1)
  return (count==0);
}

bool ACStack::isFull(){ //O(1)
  return (count==max);
}

void ACStack::push(char c){ //O(max) linear
  if(isFull()){
    char* temp = new char[2*max];
    for(int i = 0; i < max; ++i){

      temp[i] = stackArr[i];
    }
    max *= 2;
    delete[] stackArr;
    stackArr = temp;
  }
  stackArr[++top] = c;
  ++count;
}

char ACStack::pop(){ //O(1) better tell user to check if empty first
  --count;
  return stackArr[top--];
}

char ACStack::peek(){ //O(1) what about if empty?
  return stackArr[top];
}
