#pragma once
#include "StackADTT.h"
#include <iostream>
#include <assert.h>

using namespace std;

template <class Type>
class ArrayStack : public stackADT<Type> {
public:
	const ArrayStack<Type>& operator=(const ArrayStack<Type>&);
	void initializeStack();
	bool isEmpty() const;
	bool isFullStack() const;
	void push(const Type& newItem);
	Type top() const;
	void pop();
	ArrayStack(int stackSize = 100);
	ArrayStack(const ArrayStack<Type>& otherStack);
	~ArrayStack();
private:
	int maxStackSize;
	int stackTop;
	Type* list;
	void copyStack(const ArrayStack<Type>& otherStack);
};

template <class Type>
void ArrayStack<Type>::initializeStack() {
	stackTop = 0;
}

template <class Type>
bool ArrayStack<Type>::isEmpty() const {
	return(stackTop == 0);
}

template <class Type>
bool ArrayStack<Type>::isFullStack() const {
	return(stackTop == maxStackSize);
}

template <class Type>
void ArrayStack<Type>::push(const Type& newItem) {
	if (!isFullStack()) {
		list[stackTop] = newItem;
		stackTop++;
	}
	else
		cout << "Cannot add to a full stack." << endl;
}

template <class Type>
Type ArrayStack<Type>::top() const {
	assert(stackTop != 0);
	return list[stackTop - 1];
}

template <class Type>
void ArrayStack<Type>::pop() {
	if (!isEmpty())
		stackTop--; //decrement stackTop
	else
		cout << "Cannot remove from an empty stack." << endl;
}

template <class Type>
void ArrayStack<Type>::copyStack(const ArrayStack<Type>& otherStack) {
	delete[] list;
	maxStackSize = otherStack.maxStackSize;
	stackTop = otherStack.stackTop;
	list = new Type[maxStackSize];
	for (int j = 0; j < stackTop; j++)
		list[j] = otherStack.list[j];
}

template <class Type>
ArrayStack<Type>::ArrayStack(int stackSize) {
	if (stackSize <= 0) {
		cout << "Size of the array to hold the stack must "
			<< "be positive." << endl;
		cout << "Creating an array of size 100." << endl;
		maxStackSize = 100;
	}
	else
		maxStackSize = stackSize;

	stackTop = 0; //set stackTop to 0
	list = new Type[maxStackSize];
}

template <class Type>
ArrayStack<Type>::~ArrayStack() {
	delete[] list;
}

template <class Type>
ArrayStack<Type>::ArrayStack(const ArrayStack<Type>& otherStack) {
	list = NULL;
	copyStack(otherStack);
}

template <class Type>
const ArrayStack<Type>& ArrayStack<Type>::operator= (const ArrayStack<Type>& otherStack) {
	if (this != &otherStack) //avoid self-copy
		copyStack(otherStack);
	return *this;
}

