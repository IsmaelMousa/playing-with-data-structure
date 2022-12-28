#include<iostream>
using namespace std;
template<typename T>
struct nodeType {
	T info;
	nodeType* link;
};
template<typename T>
class linkedList {
private:
	nodeType<T>* first;
	nodeType<T>* last;
	int count;
	void copyList(const linkedList& obj);
	T& smallestInfo();
public:
	linkedList() {
		first = NULL;
		last = NULL;
		count = 0;
	}
	bool isEmpty()const {
		return first == NULL;
	}
	int length()
	{
		return count;
	}
	void insertFirst(const T& item) {
		nodeType<T>* myNode = new nodeType<T>;
		myNode->info = item;
		myNode->link = NULL;
		if (isEmpty())
			last = myNode;
		myNode->link = first;
		first = myNode;
		count++;
	}
	void insertLast(const T& item) {
		if (isEmpty()) {
			insertFirst(item);
			return;
		}
		nodeType<T>* myNode = new nodeType<T>;
		myNode->info = item;
		myNode->link = NULL;
		last->link = myNode;
		last = myNode;
		count++;
	}
	void displayList() {
		nodeType<T>* p = first;
		cout << "first-> ";
		while (p) {
			cout << p->info << " -> ";
			p = p->link;
		}
		cout << "Last\n";
	}
	void removeFront() {
		if (isEmpty())
			return;
		nodeType<T>* p = first;
		first = first->link;
		p->link = NULL;
		delete p;
		count--;
	}
	void removeLast() {
		if (isEmpty())
			return;
		if (first == last) {
			removeFront();
			return;
		}
		nodeType<T>* p = first;
		while (p->link != last)
			p = p->link;
		p->link = NULL;
		delete last;
		last = p;
		count--;
	}
	void destroyList() {
		while (first)
		{
			removeFront();
		}
		last = NULL;
	}
	void initilazationList()
	{
		destroyList();
	}
	linkedList(const linkedList& obj)
	{
		first = last = NULL;
		copyList(obj);
	}
	~linkedList() {
		destroyList();
		delete first;
		delete last;
	}
	T& Front() {
		if (!isEmpty())
			return first->info;
		else
		{
			nodeType<T>* myNode = new nodeType<T>;
			return myNode->info;
		}
	}
	T& Last() {
		if (!isEmpty())
			return last->info;
		else
		{
			nodeType<T>* myNode = new nodeType<T>;
			return myNode->info;
		}
	}
	bool search(const T& item) {
		nodeType<T>* p = first;
		if (isEmpty())
			return false;
		while (p and p->link and p->info != item) {
			p = p->link;
		}
		if (p->info == item)
			return true;
		else
			return false;
	}
	void deleteNode(const T& item) {
		if (isEmpty())
			return;
		if (first->link == NULL)
		{
			if (first->info == item)
				removeFront();
			return;
		}
		if (search(item)) {
			nodeType<T>* p = first;
			nodeType<T>* q = first;
			while (p and p->link and p->info != item) {
				q = p;
				p = p->link;
			}
			q->link = p->link;
			p->link = NULL;
			delete p;
			count--;
		}
		return;
	}
	//
	void removeSmall() {
		nodeType<T>* curent = first;
		nodeType<T>* berCurent = first;
		nodeType<T>* x = first;
		if (isEmpty())
		{
			return;
		}
		while (curent and curent->link)
		{
			if (curent->info < x->info)
				x = curent;
			curent = curent->link;
		}
		if (curent->info < x->info)
			x = curent;
	
			while (berCurent and berCurent->link != x)
				berCurent = berCurent->link;
			berCurent->link = x->link;
		delete x;
	}
	
	//
	void divideMid(linkedList<T>& item)
	{
		nodeType<T>* curent = first;
		item.last = last;
		int num = (count / 2) + 1;
		for (int i = 0; i <= num; i++) {
			curent = curent->link;
		}
		last = curent;
		item.first = last->link;
		last->link = NULL;
	}
	//
	void divideAt(linkedList<T>& obj, const T& item) {
		nodeType<T>* curent = first;
		nodeType<T>* brecurent = first;
		obj.last = last;
		while (curent && curent->link && curent->info != item)
		{
				curent = curent->link;
		}
		if (curent->info == item)
		{
			while (brecurent->link != curent)
			{
				brecurent = brecurent->link;
			}
			last = brecurent;
			obj.first = curent;
			last->link = NULL;
		}
		
		
	}
};
template<typename T>
void linkedList<T>::copyList(const linkedList& obj) {
	if (!isEmpty())
		destroyList();
	nodeType<T>* p = obj.first;
	while (p)
	{
		insertLast(p->info);
		p = p->link;
	}
	count = obj.count;
	return;
}
template<typename T>
T& linkedList<T>::smallestInfo() {
	nodeType<T>* p = first;
	nodeType<T>* smallest = first;
	while (p)
	{
		if (p->info < smallest->info)
			smallest = p;
		p = p->link;
	}
	return smallest->info;
}
int main() {
	linkedList<int>x;
	linkedList<int>y;
	x.insertLast(8);
	x.insertLast(2);
	x.insertLast(3);
	x.insertLast(7);
	x.insertLast(7);
	x.insertLast(15);
	x.insertLast(1);
	x.displayList();
	x.divideAt(y, 7);
	x.displayList();
	cout << endl;
	y.displayList();
}