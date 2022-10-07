#ifndef ACSTACK_H
#define ACSTACK_H



class ACStack{
public:
  ACStack();
  ACStack(int iSize);
  ~ACStack();
  int size();
  bool isEmpty();
  void push(char c);
  char pop();
  char peek();

private:
  char* stackArr;
  int count; //number of things in stack
  int max; //most things we can hold
  int top;
  bool isFull();

};

#endif
