// Assignment-3
#include <iostream>
using namespace std;

class UnorderedArrayList
{
public:

	UnorderedArrayList(int size = 100);
	UnorderedArrayList(UnorderedArrayList& otherList);	
	~UnorderedArrayList();
	//
	bool operator> (const UnorderedArrayList& obj);
	bool operator< (const UnorderedArrayList& obj);
	bool operator>=(const UnorderedArrayList& obj);
	bool operator<=(const UnorderedArrayList& obj);
	bool operator==(const UnorderedArrayList& obj);
	bool operator!=(const UnorderedArrayList& obj);
	void operator=(const UnorderedArrayList& obj);
	//
	bool isEmpty();
	bool isFull();
	int listSize();
	int maxListSize();
	void print();
	//
	bool isItemAtEqual(int loc, int item);
	void insertAt(int loc, int item);
	void insertEnd(int item);
	int seqSearch(int item);
	void insertNoDuplicate(int item);
	void clearList();
	void removeAll(int item);
	void removeItemAt(int loc);
	void remove(int item);
	UnorderedArrayList findAll(int item);
	//
	int min();
	int max();
	//
	void sort();
private:
	int* list; 	
	int length;		
	int maxSize;
};
//Constructor
UnorderedArrayList::UnorderedArrayList(int size)
{
	if (size <= 0)
	{
		cout << " Wrong Size " << endl;
		maxSize = 100;
	}
	else
	{
		maxSize = size;
	}
	length = 0;
	list = new int[maxSize];
}
//Copy constructor
UnorderedArrayList::UnorderedArrayList(UnorderedArrayList& otherList)
{
	maxSize = otherList.maxSize;
	length = otherList.length;
	list = new int[maxSize];

	for (int j = 0; j < length; j++)
	{
		list[j] = otherList.list[j];
	}
}
//Destructor
UnorderedArrayList::~UnorderedArrayList()
{
	delete[] list;
}
// Overloading Operators:
// (Comparsion Operators)
bool UnorderedArrayList::operator>(const UnorderedArrayList& obj)
{
	return (length > obj.length);
}
bool UnorderedArrayList::operator<(const UnorderedArrayList& obj)
{
	return (length < obj.length);
}
bool UnorderedArrayList::operator>=(const UnorderedArrayList& obj)
{
	return (length >= obj.length);
}
bool UnorderedArrayList::operator<=(const UnorderedArrayList& obj)
{
	return (length <= obj.length);
}
bool UnorderedArrayList::operator==(const UnorderedArrayList& obj)
{
	return (length == obj.length);
}
bool UnorderedArrayList::operator!=(const UnorderedArrayList& obj)
{
	return (length != obj.length);
}
// (Assignment Operator)
void UnorderedArrayList::operator=(const UnorderedArrayList& obj)
{
	list = obj.list;
	length = obj.length;
	maxSize = obj.maxSize;
}
// Check if the List is Empty
bool UnorderedArrayList::isEmpty()
{
	return (length == 0);
}
// Check if the List is Full
bool UnorderedArrayList::isFull()
{
	return (length == maxSize);
}
// The Length of the List
int UnorderedArrayList::listSize()
{
	return length;
}
// The Max Size of the List
int UnorderedArrayList::maxListSize()
{
	return maxSize;
}
// Print the Content of the List
void UnorderedArrayList::print()
{
	if (isEmpty())
	{
		cout << "The List is Empty";
	}
	for (int i = 0; i < length; i++)
	{
		cout << list[i] << " ";
	}
	cout << endl;
}
// Returns if this Value in this Location or not 
bool UnorderedArrayList::isItemAtEqual(int loc, int item)
{
	if (loc < 0 || loc >= length)
	{
		return false;
	}
	else
	{
		return (list[loc] == item);
	}
}
// Insert the Value in this Location
void UnorderedArrayList::insertAt(int loc, int item)
{
	if (isFull())
	{
		cout << " The List is Full " << endl;
	}
	else if (loc < 0 || loc > length)
	{
		cout << "Out of Range " << endl;
	}
	else
	{
		for (int i = length; i > loc; i--)
		{
			list[i] = list[i - 1];
		}
		list[loc] = item;
		length++;
	}
}
//Insert the Value in the end of the List
void UnorderedArrayList::insertEnd(int item)
{
	if (isFull())
	{
		cout << " The List is Full " << endl;
	}
	else
	{
		list[length++] = item;
	}
}
//Return the Location of this Value if it exist in the List, if the Value is not exist Return -1
int UnorderedArrayList::seqSearch(int item)
{
	for (int loc = 0; loc < length; loc++)
	{
		if (list[loc] == item)
		{
			return loc;
		}
	}
	return -1;
}
//Insert the Value in the List Without Duplication
void UnorderedArrayList::insertNoDuplicate(int item)
{
	if (isFull())
	{
		cout << " The List is Full " << endl;
	}
	else
	{
		int flag = seqSearch(item);
		if (flag == -1)
		{
			list[length++] = item;
		}
		else
		{
			cout << "No duplicates are allowed." << endl;
		}
	}
}
//Clear all the Elements of the List
void UnorderedArrayList::clearList()
{
	length = 0;
}
//Remove all the Elements that are Duplicated
void UnorderedArrayList::removeAll(int item)
{
	if (isEmpty())
	{
		cout << "the List is Empty" << endl;
	}
	int counter = 0;
	for (int loc = 0; loc < length; loc++)
	{
		if (list[loc] == item)
		{
			counter += 1;
		}
	}
	for (int i = 0; i < counter - 1; i++)
	{
		remove(item);
	}
}
//Remove the Value of this Location 
void UnorderedArrayList::removeItemAt(int loc)
{
	if (loc < 0 || loc >= length)
		cout << "The location of the item to be removed is out of range." << endl;
	else
	{
		for (int i = loc; i < length - 1; i++)
		{
			list[i] = list[i + 1];
		}
		length--;
	}
}
//Remove this Value
void UnorderedArrayList::remove(int item)
{
	int loc = seqSearch(item);
	if (loc == -1)
		cout << "The item to be deleted is not in the list" << endl;
	else
		removeItemAt(loc);
}
//Return a list of intgers that Containes the locations of Duplicated Values
UnorderedArrayList UnorderedArrayList::findAll(int item)
{
	if (isEmpty())
	{
		return NULL;
	}

	UnorderedArrayList temp;
	int j = 0;
	for (int i = 0; i < length; i++)
	{
		if (list[i] == item)
		{
			temp.list[j] = i;
			j++;
		}
	}
	temp.length = j;
	return temp;
}
//Return the Smallest Value in the List
int UnorderedArrayList::min()
{
	if (isEmpty())
	{
		return 0;
	}
	int min;
	min = list[0];
	for (int i = 0; i < length; i++)
	{
		if (list[i] < min)
		{
			min = list[i];
		}
	}
	return min;
}
//Return the Largest Value in the list
int UnorderedArrayList::max()
{
	if (isEmpty())
	{
		return 0;
	}
	int max;
	max = list[0];
	for (int i = 0; i < length; i++)
	{
		if (list[i] > max)
		{
			max = list[i];
		}
	}
	return max;
}
//Ascending Sorting
void UnorderedArrayList::sort()
{
	if (isEmpty())
	{
		cout << "The list is Empty" << endl;
	}
	for (int i=0;i<length-1;i++)
		for (int j = i+1; j <length; j++)
		{
			if (list[j] < list[i])
			{
				int temp = list[j];
				list[j] = list[i];
				list[i] = temp;
			}
		}
}
int main()
{ 
	int value, length, position;
	bool check;
	cout << "Enter the Length of List 1 please " << endl;cin >> length;
	UnorderedArrayList lst1(length);
	for (int i = 0; i < length; i++)
	{
		cout << "Value " << i+1 << " : " << endl;
		cin >> value;
		lst1.insertAt(i, value);
	}
	
	cout << endl<<"Enter the Length of List 2 please " << endl;cin >> length;
	UnorderedArrayList lst2(length);
	for (int i = 0; i < length; i++)
	{
		cout << "Value " << i + 1 << " : " << endl;
		cin >> value;
		lst2.insertAt(i, value);
	}

	cout <<endl<< "List 1 : " << endl;lst1.print();
	cout << endl <<"List 2 : " << endl;lst2.print();

/// 1)
	cout << endl << " Remove Item at Position : ";cin >> position;cout << endl;
	lst1.removeItemAt(position);
	lst1.print();
/// 2)
	UnorderedArrayList lst3 = lst1;
	cout << endl << " Find the Positions of this Value : ";cin >> value;cout << endl;
	lst3.findAll(value).print();
/// 3)
	cout << endl << " Is List1 is Greater Than List2 ? , if the Answer is '1' thats mean True, if '0' thats mean False : " << endl;
	check = lst1 > lst2;
	cout << check << endl;
/// 4)
	cout <<endl <<" The Minimum Value of List1 : " << lst1.min() << endl;
/// 5)
	cout << endl <<" Remove The Duplication Values of this Value : ";cin >> value;cout << endl;
	lst1.removeAll(value);lst1.print();
}