#pragma once
template <class Type>
class stackADT {
public:
	virtual void initializeStack() = 0;
	virtual bool isEmpty() const = 0;
	virtual bool isFullStack() const = 0;
	virtual void push(const Type& newItem) = 0;
	virtual Type top() const = 0;
	virtual void pop() = 0;
};

