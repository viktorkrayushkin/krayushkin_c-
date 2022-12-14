#pragma once
#include <iostream>
#include <fstream>
using namespace std;
int NOD(int c, int d);

class Fraction {
private:
    int _numerator_;
    unsigned int _denominator_;
    void Reduction(void);

public:
    Fraction(int numerator, int denominator);
    Fraction(int n = 1);
    explicit operator double() const;

    int GetNumerator(void)
    {
        return _numerator_ ;
    }
    unsigned int GetDenominator(void)
    {
        return _denominator_ ;
    }

    friend istream& operator >> (istream &in,  Fraction& obj);
    friend ostream& operator << (ostream &out, const Fraction& obj);

    void Set(int numerator, int denominator);

    Fraction Reciprocal(void);

    Fraction& operator =(const Fraction& right);

    Fraction& operator ++(void);
    Fraction& operator ++(int);
    Fraction& operator --(void);
    Fraction& operator --(int);

    friend const Fraction operator +(const Fraction& left, const Fraction& right);

    friend const Fraction operator -(const Fraction& left, const Fraction& right);

    friend const Fraction operator *(const Fraction& left, const Fraction& right);

    friend const Fraction operator /(const Fraction& left, const Fraction& right);

    Fraction& operator +=(const Fraction& right);

    Fraction& operator -=(const Fraction& right);

    Fraction& operator *=(const Fraction& right);

    Fraction& operator /=(const Fraction& right);

    friend bool operator <=(const Fraction& left, const Fraction& right);

    friend bool operator <(const Fraction& left, const Fraction& right);

};
