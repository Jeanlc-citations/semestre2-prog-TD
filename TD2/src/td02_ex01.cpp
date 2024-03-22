#include <vector>
#include <cstdlib>
#include <algorithm>
#include "ScopedTimer.hpp"

std::vector<int> generate_random_vector(size_t const size, int const max = 100) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}



std::vector<int> bulle(std::vector<int> & tableau) {
    bool trie{false};
    while (trie == false) {
        trie = true;
        for (int i{0}; i < tableau.size(); i++) {
        if (i+2 <= tableau.size())
        if (tableau[i] > tableau[i+1]) {
            std::swap(tableau[i], tableau[i+1]);
            trie = false;
        }
    }
    }
    return tableau;
}


std::vector<int> selection(std::vector<int> & tableau) {
    bool trie{false};
    int i0{0};
    while (trie == false) {
        trie = true;
        for (int i{i0}; i < tableau.size(); i++) {
            int min{tableau[i]};
            int indice{i0};
            for(int j{i0}; j < tableau.size(); j++) {
                if (min > tableau[j]) {
                    min = tableau[j];
                    indice = j;
                    trie = false;
                }   

            }
            std::swap(tableau[indice], tableau[i0]);
        
        i0++;
    }
    }
    return tableau;
}


int main() {
     std::vector<int> tableau {1, 9, 5, 12, 9, 3, 4, 6, 8};
    // std::vector<int> tableau {generate_random_vector(9, 100)};

    std::vector<int> tableau_trie {selection(tableau)};
    for (int j{0}; j < tableau_trie.size(); j++) {
        std::cout << tableau_trie[j] << std::endl;
    }


    // exercice 3
    {
    ScopedTimer timer("Chronos");
    selection(tableau);
    }

    {
    ScopedTimer timer("Chronos");
    bulle(tableau);
    }
}