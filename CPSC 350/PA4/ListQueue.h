#ifndef LIST_QUEUE_H
#define LIST_QUEUE_H

#include "DblList.h"
#include <cstdlib>
using namespace std;

template <typename T>
class ListQueue{
public:
  ListQueue();
  ~ListQueue();
  int size();
  bool isEmpty();
  void add(T c);
  T remove();
  T peek();

private:
  DblList<T>* theList;

};

template <typename T>
ListQueue<T>::ListQueue(){ //O(1)
  theList = new DblList<T>();
}


template <typename T>
ListQueue<T>::~ListQueue(){ //O(1)
  delete theList;
}

template <typename T>
int ListQueue<T>::size(){ //O(1)
  return theList->getSize();
}

template <typename T>
bool ListQueue<T>::isEmpty(){ //O(1)
  return theList->isEmpty();
}


template <typename T>
void ListQueue<T>::add(T c){ //O(1)
  theList->addBack(c);
}

template <typename T>
T ListQueue<T>::remove(){ //O(1) better tell user to check if empty first
  return theList->removeFront();
}

template <typename T>
T ListQueue<T>::peek(){ //O(1) what about if empty?
  return theList->get(0);
}

#endif
