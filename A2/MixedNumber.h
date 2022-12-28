#pragma once
#include"Header.h"
class MixedNum : public Rational {
public:
	MixedNum(int h = 0, int n = 0, int d = 1) : Rational(n, d), whole(h) {};
	MixedNum(const Rational& r, int h = 0) : Rational(r), whole(h) {};
	MixedNum operator+(const MixedNum& m) const;
	MixedNum operator-(const MixedNum& m) const;
	MixedNum operator*(const MixedNum& m) const;
	MixedNum operator/(const MixedNum& m) const;
	Rational toRational(int, int, int)const;
	void read();
	void simplify();
	void display() const;
protected:
	int whole;
};