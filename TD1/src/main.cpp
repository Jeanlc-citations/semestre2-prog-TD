#include <iostream>
#include "fraction.hpp"

int main()
{
    Fraction f1 { 3, 4 };
    Fraction f2 { 1, 2 };
    Fraction f3 {f1 + f2};
    Fraction f4 {f1 - f2};
    Fraction f5 {f1 * f2};
    Fraction f6 {f1 / f2};

    std::cout << "f1 = ";
    f1.display();
    std::cout << " f2 = ";
    f2.display();
    std::cout << std::endl;

    

    std::cout << "add(f1, f2) = ";
    std::cout << f3;

    std::cout << std::endl << "sub(f1, f2) = ";
    std::cout << f4;

    std::cout << std::endl << "mul(f1, f2) = ";
    std::cout << f5;

    std::cout << std::endl << "div(f1, f2) = ";
    std::cout << f6 << std::endl;

    if (f1 == f2) {
        std::cout << "Les fractions sont egales" << std::endl;
    } 
    if  (f1 != f2) {
        std::cout << "Les fractions ne sont pas egales" << std::endl;
    } 
    if (f1 < f2) {
        std::cout << "f1 est strictement inferieure a f2" << std::endl;
    } 
    if (f1 <= f2) {
        std::cout << "f1 est inferieure ou egale a f2" << std::endl;
    } 
    if (f1 > f2) {
        std::cout << "f1 est strictement superieure a f2" << std::endl;
    } 
    if (f1 >= f2) {
        std::cout << "f1 est superieure ou egale a f2" << std::endl;
    }


    float d1 {static_cast<float>(f1)};
    std::cout << "En valeur decimal, f1 = " << d1 << std::endl;




    
    /*
    std::cout << std::endl << "add(1/6, 2/6) = ";
    (add({1, 6}, {2, 6})).display();
    */
    return 0;
}