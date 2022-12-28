#pragma once
#include <iostream>
using namespace std;
class Rational
{
public:
	//Arithmetic Methods
	Rational add(const Rational& rhs) const;
	Rational subtract(const Rational& rhs) const;
	Rational multiply(const Rational& rhs) const;
	Rational divide(const Rational& rhs) const;
	//Overloading operators
	Rational operator* (Rational& obj);
	Rational operator+ (Rational& obj);
	Rational operator- (Rational& obj);
	Rational operator/ (Rational& obj);
	//File Methods
	bool read();
	void write();
	//Constructor
	Rational();
	//Consructor with parameters
	Rational(int num1, int num2);
	//Copy Constructor
	Rational(const Rational& obj);
	//Access Methods (set the values)
	void setNum(int num);
	void setDum(int num);
	void setNumbers(int num1, int num2);
	//Access Methods (get the values)
	int getNum();
	int getDum();
	Rational getNumbers();
private:
	int num;
	int dum;
};
