/*
Spencer Au
ID: 002385256
spau@chapman.edu
CPSC 350 - Section 2
PA3

Header Function for MonoStack Class. Implements a Monotonic Stack

Functions:
MonoStack() - Default constructor that initializes top = -1, count = 0, max = 0, stack = NULL
MonoStack(int iSize, char o) - Constructor that takes an initial size and a char o flag that intitializes an
intial array of size iSize and then sets char mono = o, where i is an increasing mono stack and d is a 
decreasing mono stack
~MonoStack() - Destructor that deletes memory allocated to stack

size() - returns the current size of stack
isEmpty() - returns a bool of whether stack is empty 
push(T c) - takes a Template c, and depending on if mono is i or d (increasing or decreasing respectively),
calls pop() to remove all elements within stack that are greater or less than c, and then pushes it to stack.
If the array is full it initialies a new array with max*2 size, and copies over the elements 
pop() - removes the top element at stack[top] and returns that element; decrements top and count
peek() - returns the top element at stack[top]
printStack() - prints out the elements of the stack, from the "bottom" to the top, where index 0 is the
bottom and index top is the top
isFull() - private function that returns a bool of whether the stack is full

Variables:
T* stack - private template pointer for an array that represents the stack; index 0 is the bottom and index
size-1 or index top is the top
int count - current length of the stack
int max - max potential size of the stack
int top - index that represents the top of the stack
char mono - flag that represents whether it is a increasing or decreasing monotonic stack
*/

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

// Default constructor that initializes top = -1, count = 0, max = 0, stack = NULL
template <typename T>
MonoStack<T>::MonoStack(){ //O(1)
	top = -1;
	count = 0;
	max = 0;
	stack = NULL;
}

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

// Destructor that deletes memory allocated to stack
template <typename T>
MonoStack<T>::~MonoStack(){ //O(1)
	delete[] stack;
}

// returns the current size of stack
template <typename T>
int MonoStack<T>::size(){ //O(1)
  	return count;
}

// returns a bool of whether stack is empty 
template <typename T>
bool MonoStack<T>::isEmpty(){ //O(1)
  	return (count==0);
}

// private function that returns a bool of whether the stack is full
template <typename T>
bool MonoStack<T>::isFull(){ //O(1)
  	return (count==max);
}

/*

Takes a Template c, and depending on if mono is i or d (increasing or decreasing respectively),
calls pop() to remove all elements within stack that are greater or less than c, and then pushes it to stack.
If the array is full it initialies a new array with max*2 size, and copies over the elements 

A monotonic stack is a stack whose elements appear in either monotonically increasing or decreasing order from the bottom of the stack to the top of the stack. 
Duplicate values are not allowed in the stack. As with a traditional stack, a monotonic stack is a LIFO data structure. 
The only difference is the push function, which must ensure that the values remain in monotonically increasing or decreasing order. 
This means that for a monotonically increasing stack, to push a value of X on the stack, we must first pop and discard all values in the stack that are 
larger than X. 
Similarly, for a monotonically decreasing stack, to push a value of X on the stack, we must first pop and discard all values in the stack 
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
	//for (int i = 0; i < size(); i++) {
		if (mono == 'i') {
			//cout << stack[top] << " > " << c << endl;
			if (stack[top] > c) {
				//pop();
				stack[++top] = c;
				++count;
			}
			//else pop();
		} else if (mono == 'd') {
			//cout << stack[top] << " < " << c << endl;
			if (stack[top] < c) {
				//pop();
				stack[++top] = c;
				++count;
			}
			//else pop();
		}
	if (size() == 0) {
		stack[++top] = c;
		++count;
	}
}

// Removes the top element at stack[top] and returns that element; decrements top and count
template <typename T>
T MonoStack<T>::pop() { //O(1) better tell user to check if empty first
	if (isEmpty()) return '\0';
	--count;
	return stack[top--];
}

// returns the top element at stack[top]
template <typename T>
T MonoStack<T>::peek() { //O(1) what about if empty?
	if (isEmpty()) return '\0';
  	return stack[top];
}

/* 
Prints out the elements of the stack, from the "bottom" to the top, where index 0 is the
bottom and index top is the top
*/
template <typename T>
void MonoStack<T>::printStack() {
	if (isEmpty()) {
		cout << "Stack is Empty" << endl;
		return;
	}
	cout << "Stack: [";
	for (int i = 0; i < size(); i++) {
		cout << stack[i];
		if (i != top) cout << ", "; 
	}
	cout << "]" << endl;
} 


#endif
