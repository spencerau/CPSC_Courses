#ifndef DBL_LIST_H
#define DBL_LIST_H

#include "ListNode.h"

#include <iostream>
using namespace std;

template <typename T>
class DblList{
public:
  DblList();
  virtual ~DblList();
  void print();
  //vanilla stuff
  int getSize();
  bool isEmpty();

  //additions
  void addBack(T data); //append to back
  void addFront(T data); //append to front
  void add(int pos, T data); //add at specified position

  //removes
  T removeBack();
  T removeFront();
  T remove(int pos);

  //Accessor
  T get(int pos);
  bool contains(T data);

protected:
  ListNode<T>* m_front;
  ListNode<T>* m_back;
  int m_size;
};

template <typename T>
DblList<T>::DblList(){
  m_size = 0;
  m_front = NULL;
  m_back = NULL;
}

template <typename T>
DblList<T>::~DblList(){
  //todo - free memory
  m_size = 0;
  m_front = NULL;
  m_back = NULL;
}

template <typename T>
int DblList<T>::getSize(){
  return m_size;
}

template <typename T>
bool DblList<T>::isEmpty(){
  return (m_size==0);
}

template <typename T>
T DblList<T>::get(int pos){
  //first check position is valid, check if empty
  int cPos = 0;
  ListNode<T>* current = m_front;
  while(cPos != pos){
    current = current->m_next;
    ++cPos;
  }
  return current->m_data;
}

template <typename T>
bool DblList<T>::contains(T data){
  bool found = false;
  ListNode<T>* current = m_front;
  while(current != NULL){
    if(data == current->m_data){
      found = true;
      break;
    }
    current = current->m_next;
  }
  return found;
}

template <typename T>
void DblList<T>::addFront(T data){
  ListNode<T>* newNode = new ListNode<T>(data);
  if(!isEmpty()){
    m_front->m_prev = newNode;
    newNode->m_next = m_front;
  } else{ //it's empty
    m_back = newNode;
  }
  m_front = newNode;
  ++m_size;
}


template <typename T>
void DblList<T>::addBack(T data){
  ListNode<T>* newNode = new ListNode<T>(data);
  if(!isEmpty()){
    m_back->m_next = newNode;
    newNode->m_prev = m_back;
  } else{
    m_front = newNode;
  }
  m_back = newNode;
  ++m_size;
}

template <typename T>
void DblList<T>::add(int pos, T data){
  if(isEmpty()){ //empty
    addFront(data); //it's empty so ignore position
  } else if(pos==0){ //first pos
    addFront(data);
  } else if(pos>=m_size-1){ //last pos
    addBack(data);
  } else{ //somewhere in middle
    ListNode<T>* current = m_front;
    int cPos = 0;
    while(cPos!=pos){
      current = current->m_next;
      ++cPos;
    }
    ListNode<T>* newNode = new ListNode<T>(data);
    current->m_prev->m_next = newNode;
    newNode->m_prev = current->m_prev;
    current->m_prev = newNode;
    newNode->m_next = current;
    ++m_size;
  }
}

template <typename T>
T DblList<T>::removeFront(){
  //handling for empty list
  T data;
  data = m_front->m_data;
  if(m_size == 1){
    delete m_front; //free up memory
    m_front = NULL;
    m_back = NULL;
  } else{ //multiple things in list
    ListNode<T>* currFront = m_front;
    m_front = m_front->m_next;
    m_front->m_prev = NULL;
    currFront->m_next = NULL;
    delete currFront;
  }
  --m_size;
  return data;
}

template <typename T>
T DblList<T>::removeBack(){
  //handling for empty list
  T data;
  data = m_back->m_data;
  if(m_size == 1){
    delete m_front; //free up memory
    m_front = NULL;
    m_back = NULL;
  } else{ //multiple things in list
    ListNode<T>* currBack = m_back;
    m_back = m_back->m_prev;
    m_back->m_next = NULL;
    currBack->m_prev = NULL;
    delete currBack;
  }
  --m_size;
  return data;
}

template <typename T>
T DblList<T>::remove(int pos){
  //check if empty
  T data;
  if(pos<=0){
    data = removeFront();
  } else if(pos >= m_size-1){
    data = removeBack();
  } else{
    //Find position and remove
    ListNode<T>* current = m_front;
    int cPos = 0;
    while(cPos != pos){
      current = current->m_next;
      ++cPos;
    }
    data = current->m_data;
    current->m_prev->m_next = current->m_next;
    current->m_next->m_prev = current->m_prev;
    current->m_next = NULL;
    current->m_prev = NULL;
    delete current;
    --m_size;
  }
  return data;
}

template <typename T>
void DblList<T>::print(){
  ListNode<T>* current = m_front;
  while(current!=NULL){
    cout << current->m_data << endl;
    current = current->m_next;
  }
}

#endif
