#include<iostream>
#include"Header.h"
#include"MixedNumbe.h"
using namespace std;
int main()
{
	MixedNum a1,a2,a3;
	char operattor,key;
	do {
		cout << "left side : " << endl;
		a1.read();
		cout << endl << "Right side : " << endl;
		a2.read();
		cout << "Enter the operation : " << endl;
		cin >> operattor;
		a1.display();
		cout << operattor << " ";
		a2.display();
		cout << " = ";
		switch (operattor)
		{
		case '+':
			a3 = a1 + a2;
			break;
		case '-':
			a3 = a1 - a2;
			break;
		case '*':
			a3 = a1 * a2;
			break;
		case '/':
			a3 = a1 / a2;
			break;
		default: cout << " Wrong choice " << endl;

		};
		a3.display();
		cout << endl << "continue ? " << endl;
		cin >> key;
	} while (key == 'y' || key == 'Y');
};