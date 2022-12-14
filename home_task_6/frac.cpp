#include "frac.h"
#include <iostream>
#define SIGN(c) ((c) >= 0 ? 1 : -1);

using namespace std;

int NOD(int c, int d) {
    c *= SIGN(c); d *= SIGN(d);
    if (c % d == 0)
        return d;
    if (d % c == 0)
        return c;

    if (c > d)
        return NOD(c % d, d);
    return NOD(c,d % c);
}

void Fraction::Reduction(void) {
    int nod = NOD(_numerator_, _denominator_);
    if (!nod) return;

    _numerator_ /= nod;
    _denominator_ /= nod;
}

Fraction::Fraction(int numerator, int denominator)
{
    Set(numerator, denominator);
}


Fraction::Fraction(int n)
{
    _numerator_ = n;
    _denominator_ = 1;
}

Fraction::operator double() const
{
    return (double(_numerator_) / double(_denominator_));
}

void Fraction::Set(int numerator, int denominator)
{
    if (!denominator) {
        cout << "Введите другой знаменатель, отличный от нуля " << endl;
        exit(1);
    }
    _numerator_ = numerator * SIGN(denominator);
    _denominator_ = denominator * SIGN(denominator);
    Reduction();

}

istream &operator >> (istream& in, Fraction & fraction)
{   cout<<"Введите числитель дроби: ";
    in >> fraction._numerator_;
    cout<<" Введите знаменатель дроби: ";
    in >> fraction._denominator_;
    return in;
}
ostream &operator <<(ostream& out, const Fraction & fraction)
{
    out << fraction._numerator_ <<"/"<< fraction._denominator_;
    return out;
}

Fraction Fraction::Reciprocal(void) {
    return Fraction(_denominator_, _numerator_);
}

Fraction& Fraction::operator =(const Fraction& right){
    if (this == &right)
        return *this;

    _numerator_ = right._numerator_;
    _denominator_ = right._denominator_;
    return *this;
}

Fraction& Fraction::operator ++(void)
{
    _numerator_ += _denominator_;
    return *this;
}

Fraction& Fraction::operator ++(int)
{
    Fraction tmp = *this;
    _numerator_ += _denominator_;
    return tmp;
}

Fraction& Fraction::operator --(void)
{
    _numerator_ -= _denominator_;
    return *this;
}

Fraction& Fraction::operator --(int)
{
    Fraction tmp = *this;
    _numerator_ -= _denominator_;
    return tmp;
}

const Fraction operator +(const Fraction& left, const Fraction& right)
{
    int numerator = (left._numerator_ * right._denominator_) + (right._numerator_ * left._denominator_);
    int denominator = left._denominator_ * right._denominator_;
    return Fraction(numerator, denominator);
}

const Fraction operator -(const Fraction& left, const Fraction& right)
{
    int numerator = (left._numerator_ * right._denominator_) - (right._numerator_ * left._denominator_);
    int denominator = left._denominator_ * right._denominator_;
    return Fraction(numerator, denominator);
}

const Fraction operator *(const Fraction& left, const Fraction& right)
{
    int numerator = left._numerator_ * right._numerator_;
    int denominator = left._denominator_ * right._denominator_;
    return Fraction(numerator, denominator);
}

const Fraction operator /(const Fraction& left, const Fraction& right)
{
    int numerator= left._numerator_ * right._denominator_;
    int denominator = left._denominator_ * right._numerator_;
    return Fraction(numerator, denominator);
}

Fraction& Fraction::operator +=(const Fraction& right)
        {
            _numerator_ = (_numerator_ * right._denominator_) + (right._numerator_ * _denominator_);
            _denominator_ *= right._denominator_;
    Reduction();
    return *this;
}

Fraction& Fraction::operator -=(const Fraction& right) {
    _numerator_ = (_numerator_ * right._denominator_) - (right._numerator_ * _denominator_);
    _denominator_ *= right._denominator_;
    Reduction();
    return *this;
}

Fraction& Fraction::operator *=(const Fraction& right) {
    _numerator_ *= right._numerator_;
    _denominator_ *= right._denominator_;
    Reduction();
    return *this;
}

Fraction& Fraction::operator /=(const Fraction& right) {
    _numerator_ *= right._denominator_;
    _denominator_ *= right._numerator_;
    Reduction();
    return *this;
}

bool operator <(const Fraction& left, const Fraction& right) {
    return ((left._numerator_ * right._denominator_) < (right._numerator_ * left._denominator_));
}

bool operator <=(const Fraction& left, const Fraction& right) {
    return ((left._numerator_ * right._denominator_) <= (right._numerator_ * left._denominator_));
}
