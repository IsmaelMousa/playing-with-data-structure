#include "Header.h"
int main()
{
	int n = 0;
	Rational Obj1, Obj2, Obj3;
	char oper, key=' ';
	do {
		cout << endl << "Numerator : " << endl;
		cin >> n;
		Obj1.setNum(n);
		cout << endl << "Denominator : " << endl;
		cin >> n;
		while (n == 0)
		{
			cout << "Enter Denominator again :" << endl;
			cin >> n;
		}
		Obj1.setDum(n);
		cout << endl << "Operator (*,+,-,/) : " << endl;
		cin >> oper;
		cout << endl << "Numerator : " << endl;
		cin >> n;
		Obj2.setNum(n);
		cout << endl << "Denominator : " << endl;
		cin >> n;
		while (n == 0)
		{
			cout << "Enter Denominator again :" << endl;
			cin >> n;
		}
		Obj2.setDum(n);
		cout << endl;
		switch (oper)
		{
		case '+': Obj3 = Obj1 + Obj2;
			Obj1.write();
			cout << " + ";
			Obj2.write();
			cout << " = ";
			Obj3.write();
			break;
		case '*': Obj3 = Obj1 * Obj2;
			Obj1.write();
			cout << " * ";
			Obj2.write();
			cout << " = ";
			Obj3.write();
			break;
		case '/': Obj3 = Obj1 / Obj2;
			Obj1.write();
			cout << " / ";
			Obj2.write();
			cout << " = ";
			Obj3.write();
			break;
		case '-': Obj3 = Obj1 - Obj2;
			Obj1.write();
			cout << " - ";
			Obj2.write();
			cout << " = ";
			Obj3.write();
			break;
		default: cout << " this Choice not valid " << endl;
		}
		cout << endl << "continue ? " << endl;
		cin >> key;
	}while (key == 'y'||key=='Y');

}