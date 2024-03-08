#pragma once
#include <iostream>

struct Fraction {
    unsigned int numerator;
    unsigned int denominator;
    
    Fraction operator+=(Fraction const& f2);
    Fraction operator-=(Fraction const& f2);
    Fraction operator*=(Fraction const& f2);
    Fraction operator/=(Fraction const& f2);

    void display();

    float to_float() const;

    operator float() const;
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

