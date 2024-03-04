#pragma once
#include <iostream>

struct Fraction {
    unsigned int numerator;
    unsigned int denominator;
    
    Fraction operator+=(Fraction const& f2) {
    
    numerator += numerator * f2.denominator + numerator * f2.denominator - numerator;
    denominator += denominator * f2.denominator - denominator;
    
    return *this;
}

Fraction operator-=(Fraction const& f2) {
    
    numerator += numerator * f2.denominator - f2.numerator * denominator - numerator;
    denominator += denominator * f2.denominator - denominator;
    
    return *this;
}

Fraction operator*=(Fraction const& f2) {
    
    numerator *= f2.numerator;
    denominator *= f2.denominator;
    
    return *this;
}

Fraction operator/=(Fraction const& f2) {
    
    numerator *= f2.denominator;
    denominator *= f2.numerator;
    
    return *this;
}

    void display();


    operator type(Fraction const& f1) const;
};


Fraction operator+(Fraction f1, Fraction const& f2);
Fraction operator-(Fraction f1, Fraction const& f2);
Fraction operator*(Fraction f1, Fraction const& f2);
Fraction operator/(Fraction f1, Fraction const& f2);

bool operator==(Fraction const& f1, Fraction const& f2);
bool operator!=(Fraction const& f1, Fraction const& f2);

bool operator<(Fraction const& f1, Fraction const& f2);
bool operator<=(Fraction const& f1, Fraction const& f2);
bool operator>(Fraction const& f1, Fraction const& f2);
bool operator>=(Fraction const& f1, Fraction const& f2);

std::ostream& operator<<(std::ostream& os, Fraction const& fract);