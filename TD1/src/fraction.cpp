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













// Fraction add(Fraction const& f1, Fraction const& f2) {
//     Fraction result {
//         f1.numerator * f2.denominator + f2.numerator * f1.denominator
//         f1.denominator * f2.denominator
//     };

//     return simplify(result);
// }

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


Fraction::operator float(Fraction const& f1) const {
    return {static_cast<float>(f1.numerator) / static_cast<float>(f1.denominator)};
}