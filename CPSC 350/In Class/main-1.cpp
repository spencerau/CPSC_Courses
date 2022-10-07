#include "ACStack.h"
#include "ATStack.h"
#include <iostream>
using namespace std;

int main(){

  ACStack myCStack(5);
  myCStack.push('a');
  myCStack.push('e');
  myCStack.push('i');
  myCStack.push('o');
  myCStack.push('u');
  myCStack.push('z');
  cout << "Current size is: " << myCStack.size() << endl;
  cout << "The top of the stack is: " << myCStack.peek() << endl;
  while(!myCStack.isEmpty()){
    cout << myCStack.pop() << endl;
  }
  cout << myCStack.isEmpty() << endl;


  ATStack<char> myStack(5);
  myStack.push('a');
  myStack.push('e');
  myStack.push('i');
  myStack.push('o');
  myStack.push('u');
  cout << "Current size is: " << myStack.size() << endl;
  cout << "The top of the stack is: " << myStack.peek() << endl;
  while(!myStack.isEmpty()){
    cout << myStack.pop() << endl;
  }
  cout << myStack.isEmpty() << endl;

  ATStack<double> myStack2(5);
  myStack2.push(2.0);
  myStack2.push(4.0);
  myStack2.push(6.0);
  myStack2.push(8.0);
  myStack2.push(10.0);
  cout << "Current size is: " << myStack2.size() << endl;
  cout << "The top of the stack is: " << myStack2.peek() << endl;
  while(!myStack2.isEmpty()){
    cout << myStack2.pop() << endl;
  }
  cout << myStack2.isEmpty() << endl;

  ATStack<long> myStack3(5);
  myStack3.push(2000);
  myStack3.push(4000);
  myStack3.push(6000);
  myStack3.push(8000);
  myStack3.push(10000);
  cout << "Current size is: " << myStack3.size() << endl;
  cout << "The top of the stack is: " << myStack3.peek() << endl;
  while(!myStack3.isEmpty()){
    cout << myStack3.pop() << endl;
  }
  cout << myStack3.isEmpty() << endl;
  return 0;
}
