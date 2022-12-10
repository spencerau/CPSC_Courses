#ifndef LIST_STACK_H
#define LIST_STACK_H

#include "DblList.h"
#include <cstdlib>
using namespace std;

template <typename T>
class ListStack{
public:
  ListStack();
  ~ListStack();
  int size();
  bool isEmpty();
  void push(T c);
  T pop();
  T peek();
  bool contains(T c);

private:
  DblList<T>* theList;

};

template <typename T>
ListStack<T>::ListStack(){ //O(1)
  theList = new DblList<T>();
}


template <typename T>
ListStack<T>::~ListStack(){ //O(1)
  delete theList;
}

template <typename T>
int ListStack<T>::size(){ //O(1)
  return theList->getSize();
}

template <typename T>
bool ListStack<T>::isEmpty(){ //O(1)
  return theList->isEmpty();
}


template <typename T>
void ListStack<T>::push(T c){ //O(1)
  theList->addBack(c);
}

template <typename T>
T ListStack<T>::pop(){ //O(1) better tell user to check if empty first
  return theList->removeBack();
}

template <typename T>
T ListStack<T>::peek(){ //O(1) what about if empty?
  return theList->get(0);
}

template <typename T>
bool ListStack<T>::contains(T c) {
  return theList->contains(c);
}

#endif
