#ifndef MONOSTACK_H
#define MONOSTACK_H

#include "MonoStack.h"
#include <cstdlib>
#include <iostream>
using namespace std;

template <typename T>
class MonoStack {
public:
	MonoStack();
	MonoStack(int iSize, char o);
	~MonoStack();
	int size();
	bool isEmpty();
	void push(T c);
	T pop();
	T peek();
	void printStack();

private:
	T* stack;
	int count; // number of things in stack
	int max; // most things we can hold
	int top;
	bool isFull();
	char mono;
};

template <typename T>
MonoStack<T>::MonoStack(){ //O(1)
	top = -1;
	count = 0;
	max = 0;
	stack = NULL;
}

//#endif

/*
our constructor for the stack should take the initial size, as well as a character, o, as parameters. If o==’i’, the stack should be monotonically increasing. 
If o==’d’, the stack should be monotonically decreasing.
*/
template <typename T>
MonoStack<T>::MonoStack(int iSize, char o){ //O(1)
	top = -1;
	count = 0;
	max = iSize;
	stack = new T[max];
	this->mono = o;
}

template <typename T>
MonoStack<T>::~MonoStack(){ //O(1)
	delete[] stack;
}

template <typename T>
int MonoStack<T>::size(){ //O(1)
  	return count;
}

template <typename T>
bool MonoStack<T>::isEmpty(){ //O(1)
  	return (count==0);
}

template <typename T>
bool MonoStack<T>::isFull(){ //O(1)
  	return (count==max);
}

/*
A monotonic stack is a stack whose elements appear in either monotonically increasing or decreasing order from the bottom of the stack to the top of the stack. 
Duplicate values are not allowed in the stack. As with a traditional stack, a monotonic stack is a LIFO data structure. 
The only difference is the push function, which must ensure that the values remain in monotonically increasing or decreasing order. 
This means that for a monotonically increasing stack, to push a value of X on the stack, we must first pop and discard all values in the stack that are 
larger than X. Similarly, for a monotonically decreasing stack, to push a value of X on the stack, we must first pop and discard all values in the stack 
that are smaller than X. All other operations stay the same.
*/
template <typename T>
void MonoStack<T>::push(T c){ //O(max) linear
	if (isFull()) { // resize the array
		T* temp = new T[2*max];
		for(int i = 0; i < max; ++i){
			temp[i] = stack[i];
		}
		max *= 2;
		stack = temp;
	}
	//max *= 2;
	int i = count-1;
	if (mono == 'i') {
		while (stack[i] > c) {
			pop();
			i--;
			count--;
			top--;
		}
	} else if (mono == 'd') {
		while (stack[i] < c) {
			pop();
			i--;
			count--;
			top--;
		}
	}

	stack[++top] = c;
	++count;
}

template <typename T>
T MonoStack<T>::pop() { //O(1) better tell user to check if empty first
	if (isEmpty()) return NULL;
	--count;
	return stack[top--];
}

template <typename T>
T MonoStack<T>::peek() { //O(1) what about if empty?
	if (isEmpty()) return NULL;
  	return stack[top];
}


template <typename T>
void MonoStack<T>::printStack() {
	for (int i = top; i > -1; i--) {
		cout << stack[i] << endl; 
	}
} 


#endif
