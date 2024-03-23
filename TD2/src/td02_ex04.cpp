#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>


std::vector<float> generate_random_vector(size_t const size, int const max = 100) {
    std::vector<float> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}


void dichotomie(std::vector<float> & vec, size_t const left, size_t const right, int const valeur_cherchee) {
    size_t const middle{(left + right)/2};
    if (right - left >= 1 && valeur_cherchee != vec[middle]) {
        if (valeur_cherchee < vec[middle]) {
            dichotomie(vec,left, middle, valeur_cherchee);
        } 
        else if (valeur_cherchee > vec[middle]) {
            dichotomie(vec,middle+1, right, valeur_cherchee);
        }
    } 
    
    if (right - left < 1) {
         std::cout << "Le nombre que vous cherchez n'est pas dans le tableau" << std::endl;
    } else if (valeur_cherchee == vec[middle]) {
        std::cout << "Le nombre que vous cherchez est l'element d'indice " << middle << std::endl;
    }
} 


int main() {
    std::vector<float> tableau {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    
    

    int valeur_cherchee {11};

    dichotomie(tableau, 0, tableau.size(), valeur_cherchee);
    
    
   
    
}