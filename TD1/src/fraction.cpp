#include "fraction.hpp"
#include "utils.hpp"

#include <iostream>

void Fraction::display() {
    std::cout << numerator << "/" << denominator;
}

std::ostream& operator<<(std::ostream& os, Fraction const& fract) {
        return os << fract.numerator << "/" << fract.denominator;
}

/*

************
*Exercice 1*
************


Fraction operator+(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator + f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    });
}


Fraction operator-(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator - f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    });
}

Fraction operator*(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.numerator,
        f1.denominator * f2.denominator
    });
}

Fraction operator/(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator,
        f1.denominator * f2.numerator
    });
}
*/


// Exercice 5 

Fraction operator+(Fraction  f1, Fraction const& f2) {
    f1 += f2;
    return simplify(f1);
}

Fraction operator-(Fraction f1, Fraction const& f2) {
    f1 -= f2;
    return simplify(f1);
}

Fraction operator*(Fraction f1, Fraction const& f2) {
    f1 *= f2;
    return simplify(f1);
}

Fraction operator/(Fraction f1, Fraction const& f2) {
    f1 /= f2;
    return simplify(f1);
}


bool operator==(Fraction const& f1, Fraction const& f2) {
    return simplify(f1).numerator ==  simplify(f2).numerator && simplify(f1).denominator == simplify(f2).denominator;
    
}

bool operator!=(Fraction const& f1, Fraction const& f2) {
    return !(f1 == f2);
}



// Exercice 4

bool operator<(Fraction const& f1, Fraction const& f2) {
    return f1.numerator*f2.denominator < f2.numerator*f1.denominator;
}
bool operator<=(Fraction const& f1, Fraction const& f2) {
    return f1 < f2 || f1.numerator*f2.denominator == f2.numerator*f1.denominator;
}
bool operator>(Fraction const& f1, Fraction const& f2) {
    return !(f1 <= f2);
}
bool operator>=(Fraction const& f1, Fraction const& f2) {
    return !(f1 < f2);
}


// Exercice 5

 Fraction Fraction::operator+=(Fraction const& f2) {
    
    numerator += numerator * f2.denominator + numerator * f2.denominator - numerator;
    denominator += denominator * f2.denominator - denominator;
    
    return *this;
}

Fraction Fraction::operator-=(Fraction const& f2) {
    
    numerator += numerator * f2.denominator - f2.numerator * denominator - numerator;
    denominator += denominator * f2.denominator - denominator;
    
    return *this;
}

Fraction Fraction::operator*=(Fraction const& f2) {
    
    numerator *= f2.numerator;
    denominator *= f2.denominator;
    
    return *this;
}

Fraction Fraction::operator/=(Fraction const& f2) {
    
    numerator *= f2.denominator;
    denominator *= f2.numerator;
    
    return *this;
}




float Fraction::to_float() const {
    return static_cast<float>(numerator) / static_cast<float>(denominator);
}

Fraction::operator float() const {
    return to_float();
}