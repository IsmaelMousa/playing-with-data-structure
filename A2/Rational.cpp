#include "Header.h"


//Constructor
Rational::Rational():num(0),dum(0)
{}
//Constructor with parameters
Rational::Rational(int num, int dum):num(num),dum(dum)
{}
//Copy Constructor
Rational::Rational(const Rational& obj):num(obj.num),dum(obj.dum)
{}
//Overloading Operators
Rational Rational::operator* (Rational& obj)
{
	Rational LHS = this->multiply(obj);
	return LHS;
}
Rational Rational::operator/ (Rational& obj)
{
	Rational LHS = this->divide(obj);
	return LHS;
}
Rational Rational::operator+ (Rational& obj)
{
	Rational LHS = this->add(obj);
	return LHS;
}
Rational Rational::operator- (Rational& obj)
{
	Rational LHS = this->subtract(obj);
	return LHS;
}
// Arithmatic Methods
Rational Rational::add(const Rational& rhs) const
{
	Rational lhs2((num * rhs.dum) + (dum * rhs.num), dum * rhs.dum);
	return lhs2;
}
Rational Rational::subtract(const Rational& rhs) const
{
	Rational lhs2((num * rhs.dum) - (dum * rhs.num), dum * rhs.dum);
	return lhs2;
}
Rational Rational::multiply(const Rational& rhs) const
{
	Rational lhs2((num * rhs.num), (dum * rhs.dum));
	return lhs2;
}
Rational Rational::divide(const Rational& rhs) const
{
	Rational rhs2(num * rhs.dum, dum * rhs.num);
	return rhs2;
}
//Access Methods (set the values
void Rational::setNum(int num)
{
	this->num = num;
}
void Rational::setDum(int num)
{
	dum = num;
}
void Rational::setNumbers(int num1, int num2)
{
	this->num = num1;
	this->dum = num2;
}
//Access Methods (get the values)
int Rational::getNum()
{
	return num;
}
int Rational::getDum()
{
	return dum;
}
Rational Rational::getNumbers()
{
	return *this;
}
//
bool Rational::read() { return true; }
//
void Rational::write() {
	cout << this->getNum() << "/" << this->getDum();
}
