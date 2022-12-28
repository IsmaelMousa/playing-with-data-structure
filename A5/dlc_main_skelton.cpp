#include <iostream>
#include <fstream> 
#include "StackT.h"
using namespace std;

struct listNodeType {
	ArrayStack<char>* stk;
	listNodeType* back;
	listNodeType* next;
};

class DLCList {
public:
	DLCList(int n = 6);
	~DLCList() {};


	bool	deleteCurrent();
	ArrayStack<char>* getCurrentStack() const;
	void    goBackward(int nNodes);
	void    goForward(int nNodes);
	bool    isEmpty();
private:
	listNodeType* cur;
};

DLCList::DLCList(int n) {
	listNodeType* head;
	// ADD YOUR CODE HERE
	head = new listNodeType;
	listNodeType* a;
	listNodeType* b;
	a = head;
	b = head;
	for (int i = 0; i < n; i++) {
		a = new listNodeType;
		a->back = b;
		b->next = a;
		b = b->next;
	}
	a->next = head;
	head->back = a;
	cur = head;
}

bool DLCList::deleteCurrent() {
	if (cur == nullptr) return false;
	listNodeType* temp;
	for (int i = 0; i < 6; i++) {
		temp = cur;
		//	delete[] cur->stk;
		cur = cur->next;
		delete[]temp;
	}
	// ADD YOUR CODE HERE 

	return true;
}

ArrayStack<char>* DLCList::getCurrentStack() const {
	// ADD YOUR CODE HERE 
	if (cur == nullptr) return 0;
	else return cur->stk;

}

void DLCList::goForward(int nNodes) {
	// ADD YOUR CODE
	for (int i = 0; i < nNodes; i++) {
		cur = cur->next;
	}
}

void DLCList::goBackward(int nNodes) {
	// ADD YOUR CODE
	for (int i = 0; i < nNodes; i++) {
		cur = cur->next;
	}
}

bool DLCList::isEmpty() {
	if (cur == nullptr) return 1;
	else return 0;
}

int main() {
	ifstream in;
	in.open("C:/Users/kioskUser0/Desktop/Assignment-DS-5/Assignment-DS-5/message2.txt");
	if (!in.is_open()) {
		cerr << "can't open file ... message.txt" << endl;
		exit(0);
	}

	int n;
	in >> n;

	DLCList DL(n);

	in >> n;
	char op = 0;
	char ch = 0;
	ArrayStack<char>* curStack = nullptr;

	while (!in.eof()) {
		if (n < 0) DL.goBackward(n);
		else if (n > 0) // ADD CODE HERE 
			DL.goForward(n);
		else {
			// ADD CODE HERE 
			in >> op;
			if (op == 'P') {
				in >> ch;
				curStack->push(ch);
			}
			if (op == 'D') {
				DL.deleteCurrent();
			}
		}
		in >> n;
	}
	while (!DL.isEmpty()) {}
	cout << endl;

	return 0;
}
