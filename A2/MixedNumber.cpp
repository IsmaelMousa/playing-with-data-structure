#include <iostream>
#include"MixedNumbe.h"
#include"Header.h"
using namespace std;

void MixedNum::read() {
	int h, n, d;
	cout << "Enter the intger number " << endl;
	cin >> h;
	cout << "Enter the numerator " << endl;
	cin >> n;
	cout << "Enter the dumenator " << endl;
	cin >> d;
	this->whole = h;
	this->num = n;
	this->dum = d;
}
MixedNum MixedNum::operator+(const MixedNum& m) const {
	MixedNum a;
	Rational b(this->num, this->dum);
	Rational c(m.num, m.dum);
	Rational d = b + c;
	a.whole = this->whole + m.whole;
	MixedNum f(d, a.whole);
	return f;
}
MixedNum MixedNum:: operator-(const MixedNum& m) const {
	MixedNum a;
	Rational b(this->num, this->dum);
	Rational c(m.num, m.dum);
	Rational d = b - c;

	a.whole = this->whole - m.whole;
	MixedNum f(d, a.whole);
	return f;

}
MixedNum MixedNum:: operator*(const MixedNum& m) const {

	Rational a1 = toRational(this->whole, this->num, this->dum);
	Rational a2 = toRational(m.whole, m.num, m.dum);
	Rational a3 = a1 * a2;
	MixedNum d(a3, 0);
	d.whole = d.num / d.dum;
	d.num = (d.num % d.dum);
	return d;

}
MixedNum MixedNum:: operator/(const MixedNum& m) const {

	Rational a1 = toRational(this->whole, this->num, this->dum);
	Rational a2 = toRational(m.whole, m.num, m.dum);
	Rational a3 = a1 / a2;
	MixedNum d(a3, 0);
	d.whole = d.num / d.dum;
	d.num = (d.num % d.dum);
	return d;

}
void MixedNum::display() const {

	if (num == 0)
		cout << whole;
	else

		cout << whole << " " << num << "/" << dum;
}
void MixedNum::simplify() {}

Rational MixedNum::toRational(int x, int y, int z) const
{
	Rational b;
	b.setNum(x * y + z);
	b.setDum(z);
	return b;
}
